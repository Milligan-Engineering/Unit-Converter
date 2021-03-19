// File name: Unit Converter.cpp
// Author: Rachel Scheffer
// Email Address: rnscheffer@my.milligan.edu
// Description: Program to convert measurements between units.
// Assignment: Term Project
// Last Changed: March 19, 2021

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

void listPrint(const string unitArray[][3], int typeUnit, int numTypes);
//Preconditions: the unit names are already stored in the array unitName[3][3]
//      and the user inputs typeUnit of 1 for length, 2 for volume, or 3 for energy;
//      in this function, typeUnit-1 is the first index in the array, and 
//      numTypes is the size of the first index of the array.
//Postconditions: shows options for unit[0] based on typeUnit 
//      by printing the array unitName[typeUnit-1][0-2]
//      or says "Invalid input" if typeUnit is not 1, 2, or 3.

void listPrint(const string unitArray[][3], int typeUnit, int originalUnit, int numTypes);
//Preconditions: the unit names are already stored in the array unitName[3][3],
//      user inputs typeUnit of 1 for length, 2 for volume, or 3 for energy,
//      and the user inputs unit[0] of 1, 2, or 3 based on what they want;
//      in this function, typeUnit-1 is the first index in the array, and
//      numTypes is the first index of the array.
//Postconditions: shows options for unit[1] based on typeUnit
//      by printing the array unitName[typeUnit-1][0-2]
//      or says "Invalid input" if unit[0] is not 1, 2, or 3.

int decimalPlaceInfo(int decimalPlace);
//Preconditions: the user inputs a value for decimalPlace between 0 and 9
//Postconditions: alters decimalPlace when user inputs value
//      that is out of range.

void decimalPlaceComments(int decimalPlace);
//Preconditions: the user inputs a value for decimalPlace between 0 and 9
//Postconditions: explains alteration from decimalPlaceInfo function.

void unitType(ifstream& inStream, int& numTypes);
//Preconditions: the infile.txt has a list of type of units and numTypes is initialized to 0.
//Postconditions: outputs a list of type of units based on the file infile.txt and records how 
//      many unit types there are.

int main()
{
    string Name;
    int originalUnit, convertedUnit, decimalPlace, typeUnit, numTypes;
    double originalValue, finalValue;
    bool confirmation, again;

    ifstream inStream;
    ofstream outStream;

    string unitName[3][3] = { "meters", "feet", "miles",
    "cubic meters", "liters", "gallons", "joules", "calories", "foot-pounds" };

    const double conversion[3][3][3] = { 1.0, 3.2808399, 0.00062137, 0.3048, 1.0, 0.00018939,
        1609.344, 5280, 1.0, 1.0, 1000.0, 264.172053, 0.001, 1.0, 0.264172, 0.00378541, 3.78541178, 1.0,
        1.0, 0.23900574, 0.73756215, 4.184, 1.0, 3.08596003, 1.35581795, 0.32404827, 1.0 };

    cout << "Unit Converter\n";
    cout << "What is your name? (Enter your name and then press return) \n";
    cin >> Name;

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

        cout << "\n" << Name << ", how many decimal places do you want in your conversion? "
            << "(Enter a number between 0 and 9 and then press return) \n";
        cin >> decimalPlace;
        decimalPlaceComments(decimalPlace);
        decimalPlace = decimalPlaceInfo(decimalPlace);

        cout << "\nYou are going to have " << ++decimalPlace << " decimal places. \n\n";
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(decimalPlace);

        // This do-while statement allows the user to input their units again in case they messed up.
        do {

            unitType(inStream, numTypes);

            //This do-while statement allows users to input their unit type again if they messed up.
            do {
                cin >> typeUnit;
                listPrint(unitName, typeUnit, numTypes);
            } while ((typeUnit != 1) && (typeUnit != 2) && (typeUnit != 3));
            
            //This do-while statement allows users to input their 
            //original unit again if they messed up.
            do {
                cin >> originalUnit;
                listPrint(unitName, typeUnit, originalUnit, numTypes);
            } while ((originalUnit != 1) && (originalUnit != 2) && (originalUnit != 3));
            
            //This do-while statement allows users to input their
            //converted unit again if they messed up
            do {
                cin >> convertedUnit;
                if ((convertedUnit != 1) && (convertedUnit != 2) && (convertedUnit != 3))
                    cout << "Invalid input. Try again. \n";
            } while ((convertedUnit != 1) && (convertedUnit != 2) && (convertedUnit != 3));

            cout << "\nYou are converting from " << unitName[typeUnit - 1][originalUnit - 1]
                << " to " << unitName[typeUnit - 1][convertedUnit - 1] << ".\n";

            cout << "Is this correct? (Type 1 for yes or 0 for no and then press return)\n";
            cin >> confirmation;
            if (confirmation == false)
                cout << "\nLet's try again. \n";
            else
                cout << "Great! Let's continue.\n";
        } 
        while (confirmation == false);
        // This loops back to line 96 to input the units again.

        cout << "\nWhat is the value of your original measurement? (Enter and then press return)\n";
        cin >> originalValue;

        // Each number is assigned to a type or unit as follows:
        // Unit Type: 1 = length, 2 = volume, 3 = energy
        // Length Units: 1 = meters, 2 = feet, 3 = miles
        // Volume Units: 1 = cubic meters, 2 = liters, 3 = gallons
        // Energy Units: 1 = joules, 2 = calories, 3 = foot-pounds

        finalValue = originalValue * conversion[typeUnit - 1][originalUnit - 1][convertedUnit - 1];
        
        cout << "\n" << originalValue << " " << unitName[typeUnit - 1][originalUnit - 1]
            << " is equivalent to " << finalValue << " " 
            << unitName[typeUnit - 1][convertedUnit - 1] << ".\n";

        outStream << "\n" << originalValue << " " << unitName[typeUnit - 1][originalUnit - 1]
            << " is equivalent to " << finalValue << " " 
            << unitName[typeUnit - 1][convertedUnit - 1] << ".\n";
        
        cout << "\n" << Name << ", thank you for using the Unit Converter!\n";
        cout << "Would you like to convert another measurement?"
            << " (Type 1 for yes or 0 for no and then press return\n";
        cin >> again;
        if (again == true)
            cout << "Let's start at the beginning. \n\n";
    }
    while (again == true);
    // This loops back to line 82 to completely restart the program.

    inStream.close();
    outStream.close();

    cout << "\nHave a great day, " << Name << "! Come back anytime. \n";

    return 0;
}


void listPrint(const string unitArray[][3], int typeUnit, int numTypes) {
    if ((typeUnit != 1) && (typeUnit != 2) && (typeUnit != 3))
        cout << "\nInvalid input. Try again.\n";
    else {
        cout << "\nWhat is your original unit? (Type the corresponding number and then press return)\n";
        for (int i=1; i <= 3; i++)
            cout << i << ". " << unitArray[typeUnit - 1][i - 1] << "\n";
    }
    return;
}

void listPrint(const string unitArray[][3], int typeUnit, int originalUnit, int numTypes) {
    if ((originalUnit != 1) && (originalUnit != 2) && (originalUnit != 3))
        cout << "\nInvalid input. Try again.\n";
    else {
        cout << "\nWhat is your converted unit? (Type the corresponding number and then press return)\n";
        for (int i=1; i <= 3; i++)
            cout << i << ". " << unitArray[typeUnit - 1][i - 1] << "\n";
    }
    return;
}

int decimalPlaceInfo(int decimalPlace) {
    for (decimalPlace; decimalPlace < 0; decimalPlace = abs(decimalPlace));;
    for (decimalPlace; decimalPlace > 9; decimalPlace--);
    return(decimalPlace);
}

void decimalPlaceComments(int decimalPlace) {
    if (decimalPlace < 0)
        cout << "Cannot have negative decimal places. Changed to positive.\n";
    if (abs(decimalPlace) > 9)
        cout << "Cannot request more than 9 decimal places. Changed to 9.\n";
    cout << "Added one for rounding accuracy.\n";
    return;
}

void unitType(ifstream& inStream, int& numTypes) {
    cout << "What is your unit type? (Type the corresponding number and then press return)\n";
    string next;
    numTypes = 0;
    while (inStream >> next) {
        numTypes++;
        cout << numTypes << ". " << next << "\n";
    }
}