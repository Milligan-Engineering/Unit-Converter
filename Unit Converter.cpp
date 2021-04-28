// File name: Unit Converter.cpp
// Author: Rachel Scheffer
// Email Address: rnscheffer@my.milligan.edu
// Description: Program to convert measurements between units.
// Assignment: Term Project
// Last Changed: April 28, 2021

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

void assignArray(ifstream& inStream, char typeUnit[][20], char unit[][10][20],
    double conversion[][10][10], int& numTypes, int& numUnits, int numFactors);
//Preconditions: the infile.txt has a list of unit types, unit options, and conversion factors
//Postconditions: assigns everything in infile.txt to arrays for typeUnit, unit, and conversion,
//      and counts numTypes, numUnits, and numFactors

void listPrint(const char typeUnit[][20], int numTypes, int& unitType);
//Preconditions: the typeUnit array was filled in the assignArray function and 
//      numTypes was determined in the assignArray function as well
//Postconditions: outputs a list of unit types based on the typeUnit array;
//      the user inputs 1, 2, or 3 for unitType, or the program says "Invalid input"
//      if unitType is not 1, 2, or 3

void listPrint(const char unit[][10][20], int numUnits, int& originalUnit, int unitType);
//Preconditions: the unit names are already stored in the array unit,
//      and the user inputted typeUnit; in this function, typeUnit-1 is the first index 
//      in the array, and numTypes is the size of the second index of the array.
//Postconditions: shows options for original.unit based on typeUnit 
//      by printing the array unit; the user inputs 1, 2, or 3 for original.unit,
//      or the program says "Invalid input" if original.unit is not 1, 2, or 3

void listPrint(int numUnits, const char unit[][10][20], int& finalUnit, int unitType);
//Preconditions: the unit names are already stored in the array unit,
//      and the user inputted typeUnit, in this function, typeUnit-1 is the first index 
//      in the array, and numTypes is the size of the second index of the array
//Postconditions: shows options for final.unit based on typeUnit
//      by printing the array unit; the user inputs 1, 2, or 3 for final.unit,
//      or the program says "Invalid input" if final.unit is not 1, 2, or 3

void getConfirmation(char& confirmation);
//Preconditions: program asks if the unit statement is correct
//Postconditions: gets confirmation and validates input for confirmation

void askAgain(char& again);
//Preconditions: again can be anything; again is manipulated in this function
//Postconditions: asks if the user wants to convert another unit, gets again, and validates again

char getAgain(char again);
//Preconditions: again has been set in the askAgain function
//Postconditions: outputs again into the program

struct UnitInfo
{
    int unit;
    double value;
};

class Decimal {
public:
    Decimal();
    //Preconditions: none
    //Postconditions: default constructor

    void setName();
    //Preconditions: none
    //Postconditions: the user inputs Name

    string getName();
    //Preconditions: Name already set in setName function
    //Postconditions: Name outputted into the program

    void setDecimalPlace();
    //Preconditions: none
    //Postconditions: the user inputs decimalPlace and validates this input

    int getDecimalPlace();
    //Preconditions: decimalPlace already set in setDecimalPlace function
    //Postconditions: decimalPlace outputted into the program

private:
    string Name;
    int decimalPlace = 0;
};

int main()
{
    UnitInfo original, final;   
    Decimal program;
    const int arraySize = 10, numChar = 20;
    int unitType, numTypes = 0, numUnits = 0, numFactors = 0;
    char confirmation, again;
    char typeUnit[arraySize][numChar], unit[arraySize][arraySize][numChar];
    double conversion[arraySize][arraySize][arraySize];

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

    assignArray(inStream, typeUnit, unit, conversion, numTypes, numUnits, numFactors);

    // This do-while statement allows the program to start over
    // if the user so chooses to convert another measurement. 
    do {
        program.setDecimalPlace();
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(program.getDecimalPlace());

        outStream.setf(ios::fixed);
        outStream.setf(ios::showpoint);
        outStream.precision(program.getDecimalPlace());

        // This do-while statement allows the user to input their units again in case they messed up.
        do {

            listPrint(typeUnit, numTypes, unitType);//lists unit type
            listPrint(unit, numUnits, original.unit, unitType);//lists original unit options
            listPrint(numUnits, unit, final.unit, unitType);//lists final unit options
            do {
                cout << "\nYou are converting from " << unit[unitType - 1][original.unit - 1]
                    << " to " << unit[unitType - 1][final.unit - 1] << ".\n";
                getConfirmation(confirmation);
            } while ((confirmation != 'Y') && (confirmation != 'y') && (confirmation != 'N') && (confirmation != 'n'));
        } 
        while ((confirmation == 'N') || (confirmation == 'n'));

        cout << "\nWhat is the value of your original measurement? (Enter and then press return)\n";
        cin >> original.value;

        final.value = original.value * conversion[unitType - 1][original.unit - 1][final.unit - 1];
        
        cout << "\n" << original.value << " " << unit[unitType - 1][original.unit - 1]
            << " is equivalent to " << final.value << " " 
            << unit[unitType - 1][final.unit - 1] << ".\n";

        outStream << original.value << " " << unit[unitType - 1][original.unit - 1]
            << " is equivalent to " << final.value << " " 
            << unit[unitType - 1][final.unit - 1] << ".\n";
        
        cout << "\n" << program.getName() << ", thank you for using the Unit Converter!\n";
        askAgain(again);//asks if user wants to convert another input
    }
    while ((getAgain(again) == 'Y') || (getAgain(again) == 'y'));
    // This loops back to line 122 to completely restart the program.

    inStream.close();
    outStream.close();

    cout << "\nHave a great day, " << program.getName() << "! Come back anytime. \n";

    return 0;
}

void assignArray(ifstream& inStream, char typeUnit[][20], char unit[][10][20],
    double conversion[][10][10], int& numTypes, int& numUnits, int numFactors) {
    char factor[50][10];
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
            while (next != '\n') {
                int j = 0;
                while ((next != ',') && (next != '\n')) {
                    unit[numTypes][numUnits][j] = next;
                    j++;
                    inStream.get(next);
                }
                unit[numTypes][numUnits][j] = '\0';
                numUnits++;
                if (next == '\n')
                    break;
                inStream.get(next);
            }
            numTypes++;
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
            numFactors++;
            inStream.get(next);
        }
        inStream.get(next);
    }
    int z = 0;
    for (int w = 0; w < numTypes; w++) {
        for (int x = 0; x < numUnits; x++) {
            for (int y = 0; y < numUnits; y++) {
                conversion[w][x][y] = atof(factor[z++]);
            }
        }
    }
    return;
}

void listPrint(const char typeUnit[][20], int numTypes, int& unitType) {
    do {
        cout << "\nWhat is your unit type? (Type the corresponding number and then press return)\n";
        for (int i = 1; i <= numTypes; i++)
            cout << i << ". " << typeUnit[i - 1] << "\n";
        cin >> unitType;
        if ((unitType < 1) || (unitType > numTypes))
            cout << "Invalid input. Please try again.\n";
    } while ((unitType < 1) || (unitType > numTypes));
    return;
}

void listPrint(const char unit[][10][20], int numUnits, int& originalUnit, int unitType) {
    do {
        cout << "\nWhat is your original unit? (Type the corresponding number and then press return)\n";
        for (int i = 1; i <= numUnits; i++)
            cout << i << ". " << unit[unitType-1][i-1] << "\n";
        cin >> originalUnit;
        if ((originalUnit < 1) || (originalUnit > numUnits))
            cout << "Invalid input. Please try again.\n";
        else
            return;
    } while ((originalUnit < 1) || (originalUnit > numUnits));
}

void listPrint(int numUnits, const char unit[][10][20], int& finalUnit, int unitType) {
    do {
        cout << "\nWhat is your converted unit? (Type the corresponding number and then press return)\n";
        for (int i = 1; i <= numUnits; i++)
            cout << i << ". " << unit[unitType - 1][i - 1] << "\n";
        cin >> finalUnit;
        if ((finalUnit < 1) || (finalUnit > numUnits))
            cout << "Invalid input. Please try again.\n";
        else
            return;
    } while ((finalUnit < 1) || (finalUnit > numUnits));
}

void getConfirmation(char& confirmation) {
    cout << "Is this correct? (Type Y for yes or N for no and then press return)\n";
    cin >> confirmation;
    switch (confirmation) {
    case 'Y':
        cout << "Great! Let's continue.\n";
        break;
    case 'y':
        cout << "Great! Let's continue.\n";
        break;
    case 'N':
        cout << "\nLet's try again. \n";
        break;
    case 'n':
        cout << "\nLet's try again. \n";
        break;
    default:
        cout << "Invalid input. Let's try again.\n";
    }
    return;
}

void askAgain(char& again) {
    do {
        cout << "Would you like to convert another measurement?"
            << " (Type Y for yes or N for no and then press return\n";
        cin >> again;
        switch (again) {
        case 'Y':
            cout << "Let's start at the beginning. \n\n";
            break;
        case 'y':
            cout << "Let's start at the beginning. \n";
            break;
        case 'N':
            break;
        case 'n':
            break;
        default:
            cout << "Invalid input. Let's try again.\n";
        }
    } while ((again != 'Y') && (again != 'y') && (again != 'N') && (again != 'n'));
    return;
}

char getAgain(char again) {
    return(again);
}

Decimal::Decimal() {
    return;
}

void Decimal::setName() {
    cout << "What is your name? (Type your name without any spaces and then press return.)\n";
    cin >> Name;
    return;
}

string Decimal::getName() {
    return(Name);
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
    cout << "\nYou are going to have " << ++decimalPlace << " decimal places. \n";
    return;
}

int Decimal::getDecimalPlace() {
    return(decimalPlace);
}