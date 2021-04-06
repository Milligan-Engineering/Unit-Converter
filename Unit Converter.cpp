// File name: Unit Converter.cpp
// Author: Rachel Scheffer
// Email Address: rnscheffer@my.milligan.edu
// Description: Program to convert measurements between units.
// Assignment: Term Project
// Last Changed: April 6, 2021

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

void getOriginal(char unit[][10][20], int numUnits, int& originalUnit, int unitType);
//Preconditions: the unit names are already stored in the array unitName[3][3]
//      and the user inputs typeUnit of 1 for length, 2 for volume, or 3 for energy;
//      in this function, typeUnit-1 is the first index in the array, and 
//      numTypes is the size of the first index of the array.
//Postconditions: shows options for unit[0] based on typeUnit 
//      by printing the array unitName[typeUnit-1][0-2]
//      or says "Invalid input" if typeUnit is not 1, 2, or 3.

void getFinal(char unit[][10][20], int numUnits, int& finalUnit, int unitType);
//Preconditions: the unit names are already stored in the array unitName[3][3],
//      user inputs typeUnit of 1 for length, 2 for volume, or 3 for energy,
//      and the user inputs unit[0] of 1, 2, or 3 based on what they want;
//      in this function, typeUnit-1 is the first index in the array, and
//      numTypes is the first index of the array.
//Postconditions: shows options for unit[1] based on typeUnit
//      by printing the array unitName[typeUnit-1][0-2]
//      or says "Invalid input" if unit[0] is not 1, 2, or 3.

void assignArray(ifstream& inStream, char typeUnit[][20], char unit[][10][20], double conversion[][3][3], int numTypes, int numUnits, int numFactors);
//Preconditions: the infile.txt has a list of type of units and numTypes is initialized to 0.
//Postconditions: assigns everything in infile.txt to arrays for typeUnit, unit, and conversion.

void getType(char typeUnit[][20], int numTypes, int& unitType);
//Preconditions: the typeUnit array was filled in the assignArray function and 
//      numTypes was determined in the assignArray function as well.
//Postconditions: outputs a list of unit types based on the typeUnit array.

struct UnitInfo
{
    int unit;
    double value;
};

class Decimal {
public:
    string getName();
    void setName();
    int getDecimalPlace();
    void setDecimalPlace();
private:
    string Name;
    int decimalPlace;
};

int main()
{
    Decimal program;
    int unitType;
    char confirmation, again;
    UnitInfo original, final;
    int numTypes = 0, numUnits = 0, numFactors = 0;
    char typeUnit[10][20];
    char unit[10][10][20];
    double conversion[3][3][3] = { 1.0000e0,3.2808e0,6.2137e-4,3.0480e-1,1.0000e0,1.8939e-4,1.6093e3,5.2800e3,1.0000e0,1.0000e0,1.0000e3,2.6417e2,1.0000e-3,1.0000e0,2.6417e-1,3.7854e-3,3.7854e0,1.0000e0,1.0000e0,2.3901e-1,7.3756e-1,4.1840e0,1.0000e0,3.0860e0,1.3558e0,3.2405e-1,1.0000e0 };

    ifstream inStream;
    ofstream outStream;

    cout << "Unit Converter\n";
    program.setName();
    cout << "Hi, " << program.getName() << "!\n";

    inStream.open("infile.txt");
    if (inStream.fail()) {
        cout << "Input file opening failed. \n";
        exit(1);
    }

    outStream.open("outfile.txt");
    if (outStream.fail()) {
        cout << "Output file opening failed. \n";
        exit(1);
    }

    // This do-while statement allows the program to start over
    // if the user so chooses to convert another measurement. 
    do {
        program.setDecimalPlace();
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(program.getDecimalPlace());

        // This do-while statement allows the user to input their units again in case they messed up.
        do {

            assignArray(inStream, typeUnit, unit, conversion, numTypes, numUnits, numFactors);
            getType(typeUnit, numTypes, unitType);
            getOriginal(unit, numUnits, original.unit, unitType);
            getFinal(unit, numUnits, final.unit, unitType);

            cout << "\nYou are converting from " << unit[unitType - 1][original.unit - 1]
                << " to " << unit[unitType - 1][final.unit - 1] << ".\n";

            cout << "Is this correct? (Type 1 for yes or 0 for no and then press return)\n";
            cin >> confirmation;
            if ((confirmation == '0') || (confirmation == 'n'))
                cout << "\nLet's try again. \n";
            else
                cout << "Great! Let's continue.\n";
        } 
        while ((confirmation == '0') || (confirmation == 'n'));
        // This loops back to line 90 to input the units again.

        cout << "\nWhat is the value of your original measurement? (Enter and then press return)\n";
        cin >> original.value;

        // Each number is assigned to a type or unit as follows:
        // Unit Type: 1 = length, 2 = volume, 3 = energy
        // Length Units: 1 = meters, 2 = feet, 3 = miles
        // Volume Units: 1 = cubic meters, 2 = liters, 3 = gallons
        // Energy Units: 1 = joules, 2 = calories, 3 = foot-pounds

        final.value = original.value * conversion[unitType - 1][original.unit - 1][final.unit - 1];
        
        cout << "\n" << original.value << " " << unit[unitType - 1][original.unit - 1]
            << " is equivalent to " << final.value << " " 
            << unit[unitType - 1][final.unit - 1] << ".\n";

        outStream << "\n" << original.value << " " << unit[unitType - 1][original.unit - 1]
            << " is equivalent to " << final.value << " " 
            << unit[unitType - 1][final.unit - 1] << ".\n";
        
        cout << "\n" << program.getName() << ", thank you for using the Unit Converter!\n";
        cout << "Would you like to convert another measurement?"
            << " (Type 1 for yes or 0 for no and then press return\n";
        cin >> again;
        if ((again == '1') || (again == 'y'))
            cout << "Let's start at the beginning. \n\n";
    }
    while ((again == '1') || (again == 'y'));
    // This loops back to line 104 to completely restart the program.

    inStream.close();
    outStream.close();

    cout << "\nHave a great day, " << program.getName() << "! Come back anytime. \n";

    return 0;
}


void getOriginal(char unit[][10][20], int numUnits, int& originalUnit, int unitType) {
    do{
        cout << "What is your original unit? (Type the corresponding number and then press return)\n";
        for (int i = 1; i <= 3; i++)
            cout << i << ". " << unit[unitType-1][i-1] << "\n";
        cin >> originalUnit;
        if ((originalUnit < 1) || (originalUnit > 3))
            cout << "Invalid input. Please try again.\n";
    } while ((originalUnit < 1) || (originalUnit > 3));
    return;
}

void getFinal(char unit[][10][20], int numUnits, int& finalUnit, int unitType) {
    do {
        cout << "What is your converted unit? (Type the corresponding number and then press return)\n";
        for (int i = 1; i <= 3; i++)
            cout << i << ". " << unit[unitType - 1][i - 1] << "\n";
        cin >> finalUnit;
        if ((finalUnit < 1) || (finalUnit > 3))
            cout << "Invalid input. Please try again.\n";
    } while ((finalUnit < 1) || (finalUnit > 3));
    return;
}

int decimalPlaceInfo(int& decimalPlace) {
    for (decimalPlace; decimalPlace < 0; decimalPlace = abs(decimalPlace));;
    for (decimalPlace; decimalPlace > 9; decimalPlace--);
    return(decimalPlace);
}

void assignArray(ifstream& inStream, char typeUnit[][20], char unit[][10][20], double conversion[][3][3], int numTypes, int numUnits, int numFactors) {
    char factor[30][10];
    char next;

    while (!inStream.eof()) {
        inStream.get(next);
        while ((next != ';') && (next != '\n')) {
            int i = 0;
            while (next != ',') {
                typeUnit[numTypes][i] = next;
                i++;
                inStream.get(next);
            }
            typeUnit[numTypes][i] = '\0';
            numUnits = 0;
            inStream.get(next);
            while ((next != 'n') && (next != '\n')) {
                int j = 0;
                while ((next != ',') && (next != '\\')) {
                    unit[numTypes][numUnits][j] = next;
                    j++;
                    inStream.get(next);
                }
                unit[numTypes][numUnits][j] = '\0';
                numUnits++;
                inStream.get(next);
            }
            numTypes++;
            inStream.get(next);
            inStream.get(next);
        }
        inStream.get(next);
        while (next != '\n') {
            int k = 0;
            while ((next != ',') && (next != ':')) {
                factor[numFactors][k] = next;
                k++;
                inStream.get(next);
            }
            factor[numFactors][k] = '\0';
            //atof(factor[numFactors]);
            numFactors++;
            inStream.get(next);
        }
        inStream.get(next);
    }
    return;
}

void getType(char typeUnit[][20], int numTypes, int& unitType) {
    do {
        cout << "What is your unit type? (Type the corresponding number and then press return)\n";
        for (int i = 1; i <= 3; i++)
            cout << i << ". " << typeUnit[i - 1] << "\n";
        cin >> unitType;
        if ((unitType < 1) || (unitType > 3))
            cout << "Invalid input. Please try again.\n";
    } while ((unitType < 1) || (unitType > 3));
    return;
}

void Decimal::setDecimalPlace() {
    cout << "\n" << Name << ", how many decimal places do you want in your conversion? "
        << "(Enter a number between 0 and 9 and then press return) \n";
    cin >> decimalPlace;
    if (decimalPlace < 0)
        cout << "Cannot have negative decimal places. Changed to positive.\n";
    if (abs(decimalPlace) > 9)
        cout << "Cannot request more than 9 decimal places. Changed to 9.\n";
    for (decimalPlace; decimalPlace < 0; decimalPlace = abs(decimalPlace));;
    for (decimalPlace; decimalPlace > 9; decimalPlace--);
    cout << "Added one for rounding accuracy.\n";
    cout << "\nYou are going to have " << ++decimalPlace << " decimal places. \n\n";
    return;
}

int Decimal::getDecimalPlace() {
    return(decimalPlace);
}

void Decimal::setName() {
    cout << "What is your name? (Type your name without any spaces and then press return.)\n";
    cin >> Name;
    return;
}

string Decimal::getName() {
    return(Name);
}