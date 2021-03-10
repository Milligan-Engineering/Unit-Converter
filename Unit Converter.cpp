// File name: Unit Converter.cpp
// Author: Rachel Scheffer
// Email Address: rnscheffer@my.milligan.edu
// Description: Program to convert measurements between units.
// Assignment: Term Project
// Last Changed: March 10, 2021

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void listPrint(const string unitArray[3][3], int typeUnit);
//Preconditions: the unit names are already stored in the array unitName[3][3]
//and the user inputs typeUnit of 1 for length, 2 for volume, or 3 for energy;
//in this function, typeUnit-1 is the first index in the array
//Postconditions: Shows options for unit[0] based on typeUnit 
//by printing the array unitName[typeUnit-1][0-2]
//or says "Invalid input" if typeUnit is not 1, 2, or 3.

void listPrint(const string unitArray[3][3], int typeUnit, int originalUnit);
//Preconditions: the unit names are already stored in the array unitName[3][3],
//user inputs typeUnit of 1 for length, 2 for volume, or 3 for energy,
//and the user inputs unit[0] of 1, 2, or 3 based on what they want
//in this function, typeUnit-1 is the first index in the array
//Postconditions: Shows options for unit[1] based on typeUnit
//by printing the array unitName[typeUnit-1][0-2]
//or says "Invalid input" if unit[0] is not 1, 2, or 3.

int decimalPlaceInfo(int decimalPlace);
//Preconditions: the user inputs a value for decimalPlace between 0 and 9
//Postconditions: Alters decimalPlace when user inputs value
//that is out of range.

void decimalPlaceComments(int decimalPlace);
//Preconditions: the user inputs a value for decimalPlace between 0 and 9
//Postconditions: Explains alteration from decimalPlaceInfo function.

int main()
{
    string Name;
    int unit[2], decimalPlace, typeUnit;
    double value[2];
    bool confirmation, again;

    string unitName[3][3] = { "meters", "feet", "miles",
    "cubic meters", "liters", "gallons", "joules", "calories", "foot-pounds" };

    const double conversion[3][3][3] = { 1.0, 3.2808399, 0.00062137, 0.3048, 1.0, 0.00018939,
        1609.344, 5280, 1.0, 1.0, 1000.0, 264.172053, 0.001, 1.0, 0.264172, 0.00378541, 3.78541178, 1.0,
        1.0, 0.23900574, 0.73756215, 4.184, 1.0, 3.08596003, 1.35581795, 0.32404827, 1.0 };

    cout << "Unit Converter\n";
    cout << "What is your name? (Enter your name and then press return) \n";
    cin >> Name;

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

            cout << "What is your unit type? (Type the corresponding number and then press return)\n";
            cout << "1. length\n" << "2. volume \n" << "3. energy\n";

            //This do-while statement allows users to input their unit type again if they messed up.
            do {
                cin >> typeUnit;
                listPrint(unitName, typeUnit);
            } while ((typeUnit != 1) && (typeUnit != 2) && (typeUnit != 3));
            
            //This do-while statement allows users to input their 
            //original unit again if they messed up.
            do {
                cin >> unit[0];
                listPrint(unitName, typeUnit, unit[0]);
            } while ((unit[0] != 1) && (unit[0] != 2) && (unit[0] != 3));
            
            //This do-while statement allows users to input their
            //converted unit again if they messed up
            do {
                cin >> unit[1];
                if ((unit[1] != 1) && (unit[1] != 2) && (unit[1] != 3))
                    cout << "Invalid input. Try again. \n";
            } while ((unit[1] != 1) && (unit[1] != 2) && (unit[1] != 3));

            cout << "\nYou are converting from " << unitName[typeUnit - 1][unit[0] - 1] 
                << " to " << unitName[typeUnit - 1][unit[1] - 1] << ".\n";

            cout << "Is this correct? (Type 1 for yes or 0 for no and then press return)\n";
            cin >> confirmation;
            if (confirmation == false)
                cout << "\nLet's try again. \n";
            else
                cout << "Great! Let's continue.\n";
        } 
        while (confirmation == false);
        // This loops back to line 68 to input the units again.

        cout << "\nWhat is the value of your original measurement? (Enter and then press return)\n";
        cin >> value[0];

        // Each number is assigned to a type or unit as follows:
        // Unit Type: 1 = length, 2 = volume, 3 = energy
        // Length Units: 1 = meters, 2 = feet, 3 = miles
        // Volume Units: 1 = cubic meters, 2 = liters, 3 = gallons
        // Energy Units: 1 = joules, 2 = calories, 3 = foot-pounds

        value[1] = value[0] * conversion[typeUnit - 1][unit[0] - 1][unit[1] - 1];
        
        cout << "\n" << value[0] << " " << unitName[typeUnit - 1][unit[0] - 1] 
            << " is equivalent to " << value[1] << " " 
            << unitName[typeUnit - 1][unit[1] - 1] << ".\n";
        
        cout << "\n" << Name << ", thank you for using the Unit Converter!\n";
        cout << "Would you like to convert another measurement?"
            << " (Type 1 for yes or 0 for no and then press return\n";
        cin >> again;
        if (again == true)
            cout << "Let's start at the beginning. \n\n";
    }
    while (again == true);
    // This loops back to line 54 to completely restart the program.

    cout << "\nHave a great day, " << Name << "! Come back anytime. \n";

    return 0;
}


void listPrint(const string unitArray[3][3], int typeUnit) {
    if ((typeUnit != 1) && (typeUnit != 2) && (typeUnit != 3))
        cout << "\nInvalid input. Try again.\n";
    else {
        cout << "\nWhat is your converted unit? (Type the corresponding number and then press return)\n";
        for (int i=1; i <= 3; i++)
            cout << i << ". " << unitArray[typeUnit - 1][i - 1] << "\n";
    }
    return;
}

void listPrint(const string unitArray[3][3], int typeUnit, int originalUnit) {
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