// File name: Unit Converter.cpp
// Author: Rachel Scheffer
// Email Address: rnscheffer@my.milligan.edu
// Description: Program to convert measurements between units.
// Assignment: Term Project
// Last Changed: March 1, 2021

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string Name;
int unit[1], decimalPlace, typeUnit;
double originalValue, finalValue; 
bool confirmation, again;

string unitOptionsOriginal(int typeUnit);
//Preconditions: typeUnit
//Postconditions: Shows options for unit[0] based on typeUnit 
//or says "Invalid input" if typeUnit is not 1, 2, or 3.

string unitOptionsConverted(int typeUnit, int originalUnit);
//Preconditions: typeUnit and unit[0]
//Postconditions: Shows options for unit[1] based on typeUnit
//or says "Invalid input" if unit[0] is not 1, 2, or 3.

string originalUnit[3][3] = { "meters", "feet", "miles", 
    "cubic meters", "liters", "gallons", "joules", "calories", "foot-pounds" };

string convertedUnit[3][3] = { "meters", "feet", "miles", 
    "cubic meters", "liters", "gallons", "joules", "calories", "foot-pounds" };

const double conversion[3][3][3] = { 1.0, 3.2808399, 0.00062137, 0.3048, 1.0, 0.00018939, 
    1609.344, 5280, 1.0, 1.0, 1000.0, 264.172053, 0.001, 1.0, 0.264172, 0.00378541, 3.78541178, 1.0, 
    1.0, 0.23900574, 0.73756215, 4.184, 1.0, 3.08596003, 1.35581795, 0.32404827, 1.0 };

int main()
{

    cout << "Unit Converter\n";
    cout << "What is your name? (Enter your name and then press return) \n";
    cin >> Name;

    // This do-while statement allows the program to start over
    // if the user so chooses to convert another measurement. 
    do {

        cout << "\n" << Name << ", how many decimal places do you want in your conversion? "
            << "(Enter a number between 0 and 9 and then press return) \n";
        cin >> decimalPlace;

        for (decimalPlace; decimalPlace < 0; decimalPlace = abs(decimalPlace))
            cout << "Cannot have negative decimal places, changed to positive.\n";
        if (decimalPlace > 9)
            cout << "You cannot request more than 9 decimal places.\n";
        for (decimalPlace; decimalPlace > 9; decimalPlace--);

        cout << "Added one for rounding accuracy.\n";
        cout << "You are going to have " << ++decimalPlace << " decimal places. \n\n";
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
                cout << unitOptionsOriginal(typeUnit);
            } while ((typeUnit != 1) && (typeUnit != 2) && (typeUnit != 3));
            
            //This do-while statement allows users to input their 
            //original unit again if they messed up.
            do {
                cin >> unit[0];
                cout << unitOptionsConverted(typeUnit, unit[0]);
            } while ((unit[0] != 1) && (unit[0] != 2) && (unit[0] != 3));
            
            //This do-while statement allows users to input their
            //converted unit again if they messed up
            do {
                cin >> unit[1];
                if ((unit[1] != 1) && (unit[1] != 2) && (unit[1] != 3))
                    cout << "Invalid input. Try again. \n";
            } while ((unit[1] != 1) && (unit[1] != 2) && (unit[1] != 3));

            cout << "\nYou are converting from " << originalUnit[typeUnit - 1][unit[0] - 1] 
                << " to " << convertedUnit[typeUnit - 1][unit[1] - 1] << ".\n";

            cout << "Is this correct? (Type 1 for yes or 0 for no and then press return)\n";
            cin >> confirmation;
            if (confirmation == false)
                cout << "\nLet's try again. \n";
            else
                cout << "Great! Let's continue.\n";
        } 
        while (confirmation == false);
        // This loops back to line 66 to input the units again.

        cout << "\nWhat is the value of your original measurement? (Enter and then press return)\n";
        cin >> originalValue;
        cout << "\n";

        // Each number is assigned to a type or unit as follows:
        // Unit Type: 1 = length, 2 = volume, 3 = energy
        // Length Units: 1 = meters, 2 = feet, 3 = miles
        // Volume Units: 1 = cubic meters, 2 = liters, 3 = gallons
        // Energy Units: 1 = joules, 2 = calories, 3 = foot-pounds

        finalValue = originalValue * conversion[typeUnit - 1][unit[0] - 1][unit[1] - 1];
        
        cout << originalValue << " " << originalUnit[typeUnit - 1][unit[0] - 1] 
            << " is equivalent to " << finalValue << " " 
            << convertedUnit[typeUnit - 1][unit[1] - 1] << ".\n";
        
        cout << "\n" << Name << ", thank you for using the Unit Converter!\n";
        cout << "Would you like to convert another measurement?"
            << " (Type 1 for yes or 0 for no and then press return\n";
        cin >> again;
        if (again == true)
            cout << "Let's start at the beginning. \n\n";
    }
    while (again == true);
    // This loops back to line 47 to completely restart the program.

    cout << "\nHave a great day, " << Name << "! Come back anytime. \n";

    return 0;
}


string unitOptionsOriginal(int typeUnit) {
    string output;

    switch (typeUnit) {
    case 1:
        output = "\nWhat is your original unit? (Type the corresponding number and then press return)\n1. meters\n2. feet\n3. miles\n";
        break;
    case 2:
        output = "\nWhat is your original unit? (Type the corresponding number and then press return)\n1. cubic meters\n2. liters\n3. gallons \n";
        break;
    case 3:
        output = "\nWhat is your original unit? (Type the corresponding number and then press return)\n1. joules\n2. calories\n3. foot-pounds \n";
        break;
    default:
        output = "\nInvalid input. Try again. \n";
    }
    return(output);
}

string unitOptionsConverted(int typeUnit, int originalUnit) {
    string output;

    if ((originalUnit != 1) && (originalUnit != 2) && (originalUnit != 3))
        output = "\nInvalid input. Try again.\n";
    else {
        switch (typeUnit) {
        case 1:
            output = "\nWhat is your converted unit? (Type the corresponding number and then press return)\n1. meters\n2. feet\n3. miles\n";
            break;
        case 2:
            output = "\nWhat is your converted unit? (Type the corresponding number and then press return)\n1. cubic meters\n2. liters\n3. gallons \n";
            break;
        case 3:
            output = "\nWhat is your converted unit? (Type the corresponding number and then press return)\n1. joules\n2. calories\n3. foot-pounds \n";
            break;
        default:
            output = "\nInvalid input. Try again. \n";
        }
    }
    return(output);
}