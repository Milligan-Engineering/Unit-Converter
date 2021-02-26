// File name: Unit Converter.cpp
// Author: Rachel Scheffer
// Email Address: rnscheffer@my.milligan.edu
// Description: Program to convert measurements between units.
// Assignment: Term Project
// Last Changed: February 26, 2021

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string Name;
int unit[1]; int unitInfo(int typeUnitPar, int originalUnitPar, int convertedUnitPar);
int decimalPlace, typeUnit;
double originalValue, finalValue; 
bool confirmation, again;
const double conversion[3][3][3] = {1.0,3.2808399,0.00062137,0.3048,1.0,0.00018939,1609.344,5280,1.0,1.0,1000.0,264.172053,0.001,1.0,0.264172,0.00378541,3.78541178,1.0,1.0,0.23900574,0.73756215,4.184,1.0,3.08596003,1.35581795,0.32404827,1.0};

int main()
{

    cout << "Unit Converter\n";
    cout << "What is your name? (Enter your name and then press return) \n";
    cin >> Name;

    // This do-while statement allows the program to start over
    // if the user so chooses to convert another measurement. 
    do {
        cout << "\n" << Name << ", how many decimal places do you want in your conversion? (Enter a number between 0 and 9 and then press return) \n";
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
                switch (typeUnit) {
                    case 1:
                        cout << "\nWhat is your original unit? (Type the corresponding number and then press return)\n";
                        cout << "1. meters\n" << "2. feet\n" << "3. miles\n";
                        break;
                    case 2:
                        cout << "\nWhat is your original unit? (Type the corresponding number and then press return)\n";
                        cout << "1. cubic meters\n" << "2. liters\n" << "3. gallons \n";
                        break;
                    case 3:
                        cout << "\nWhat is your original unit? (Type the corresponding number and then press return)\n";
                        cout << "1. joules\n" << "2. calories\n" << "3. foot-pounds \n";
                        break;
                    default:
                        cout << "\nInvalid input. Try again. \n";
                }
            } while ((typeUnit != 1) && (typeUnit != 2) && (typeUnit != 3));
            //This loops back to line 56.
            
            //This do-while statement allows users to input their original unit again if they messed up.
            do {
                cin >> unit[0];
                if ((unit[0] != 1) && (unit[0] != 2) && (unit[0] != 3))
                    cout << "Invalid input. Try again. \n";
            } while ((unit[0] != 1) && (unit[0] != 2) && (unit[0] != 3));

            cout << "\nWhat is your converted unit? (Type the corresponding number and then press return)\n";
            if (typeUnit == 1) //length
                cout << "1. meters\n" << "2. feet\n" << "3. miles \n";
            else if (typeUnit == 2) //volume
                cout << "1. cubic meters\n" << "2. liters\n" << "3. gallons \n";
            else //if (typeUnit == 3), energy
                cout << "1. joules\n" << "2. calories\n" << "3. foot-pounds \n";
            
            //This do-while statement allows users to input their converted unit again if they messed up
            do {
                cin >> unit[1];
                if ((unit[1] != 1) && (unit[1] != 2) && (unit[1] != 3))
                    cout << "Invalid input. Try again. \n";
            } while ((unit[1] != 1) && (unit[1] != 2) && (unit[1] != 3));

            cout << "\n";

            if (unitInfo(typeUnit, unit[0], unit[1]) == 112)
                cout << "You are converting from meters to feet.\n";
            else if (unitInfo(typeUnit, unit[0], unit[1]) == 113)
                cout << "You are converting from meters to miles.\n";
            else if (unitInfo(typeUnit, unit[0], unit[1]) == 121)
                cout << "You are converting from feet to meters.\n";
            else if (unitInfo(typeUnit, unit[0], unit[1]) == 123)
                cout << "You are converting from feet to miles.\n";
            else if (unitInfo(typeUnit, unit[0], unit[1]) == 131)
                cout << "You are converting from miles to meters.\n";
            else if (unitInfo(typeUnit, unit[0], unit[1]) == 132)
                cout << "You are converting from miles to feet.\n";
            else if (unitInfo(typeUnit, unit[0], unit[1]) == 212)
                cout << "You are converting from cubic meters to liters.\n";
            else if (unitInfo(typeUnit, unit[0], unit[1]) == 213)
                cout << "You are converting from cubic meters to gallons.\n";
            else if (unitInfo(typeUnit, unit[0], unit[1]) == 221)
                cout << "You are converting from liters to cubic meters.\n";
            else if (unitInfo(typeUnit, unit[0], unit[1]) == 223)
                cout << "You are converting from liters to gallons.\n";
            else if (unitInfo(typeUnit, unit[0], unit[1]) == 231)
                cout << "You are converting from gallons to cubic meters.\n";
            else if (unitInfo(typeUnit, unit[0], unit[1]) == 232)
                cout << "You are converting from gallons to liters.\n";
            else if (unitInfo(typeUnit, unit[0], unit[1]) == 312)
                cout << "You are converting from joules to calories.\n";
            else if (unitInfo(typeUnit, unit[0], unit[1]) == 313)
                cout << "You are converting from joules to foot-pounds.\n";
            else if (unitInfo(typeUnit, unit[0], unit[1]) == 321)
                cout << "You are converting from calories to joules.\n";
            else if (unitInfo(typeUnit, unit[0], unit[1]) == 323)
                cout << "You are converting from calories to foot-pounds.\n";
            else if (unitInfo(typeUnit, unit[0], unit[1]) == 331)
                cout << "You are converting from foot-pounds to joules.\n";
            else if (unitInfo(typeUnit, unit[0], unit[1]) == 332)
                cout << "You are converting from foot-pounds to calories.\n";
            else if (unitInfo(typeUnit, unit[0], unit[1]) == 111)
                cout << "You are converting between the same unit (meters).\n";
            else if (unitInfo(typeUnit, unit[0], unit[1]) == 122)
                cout << "You are converting between the same unit (feet).\n";
            else if (unitInfo(typeUnit, unit[0], unit[1]) == 133)
                cout << "You are converting between the same unit (miles).\n";
            else if (unitInfo(typeUnit, unit[0], unit[1]) == 211)
                cout << "You are converting between the same unit (cubic meters).\n";
            else if (unitInfo(typeUnit, unit[0], unit[1]) == 222)
                cout << "You are converting between the same unit (liters).\n";
            else if (unitInfo(typeUnit, unit[0], unit[1]) == 233)
                cout << "You are converting between the same unit (gallons).\n";
            else  if (unitInfo(typeUnit, unit[0], unit[1]) == 311)
                cout << "You are converting between the same unit (joules).\n";
            else if (unitInfo(typeUnit, unit[0], unit[1]) == 322)
                cout << "You are converting between the same unit (calories).\n";
            else //if (unitInfo(typeUnit, unit[0], unit[1]) == 333)
                cout << "You are converting between the same unit (foot-pounds).\n";

            cout << "Is this correct? (Type 1 for yes or 0 for no and then press return)\n";
            cin >> confirmation;
            if (confirmation == false)
                cout << "\nLet's try again. \n";
            else
                cout << "Great! Let's continue.\n";
        } 
        while (confirmation == false);
        // This loops back to line 46 to input the units again.

        cout << "\nWhat is the value of your original measurement? (Enter and then press return)\n";
        cin >> originalValue;
        cout << "\n";

        // Each number is assigned to a type or unit as follows:
        // Unit Type: 1 = length, 2 = volume, 3 = energy
        // Length Units: 1 = meters, 2 = feet, 3 = miles
        // Volume Units: 1 = cubic meters, 2 = liters, 3 = gallons
        // Energy Units: 1 = joules, 2 = calories, 3 = foot-pounds

        finalValue = originalValue * conversion[typeUnit - 1][unit[0] - 1][unit[1] - 1];

        if (unitInfo(typeUnit, unit[0], unit[1]) == 112)
            cout << originalValue << " meters is equivalent to " << finalValue << " feet.\n";
        else if (unitInfo(typeUnit, unit[0], unit[1]) == 113)
            cout << originalValue << " meters is equivalent to " << finalValue << " miles.\n";
        else if (unitInfo(typeUnit, unit[0], unit[1]) == 121)
            cout << originalValue << " feet is equivalent to " << finalValue << " meters.\n";
        else if (unitInfo(typeUnit, unit[0], unit[1]) == 123)
            cout << originalValue << " feet is equivalent to " << finalValue << " miles.\n";
        else if (unitInfo(typeUnit, unit[0], unit[1]) == 131)
            cout << originalValue << " miles is equivalent to " << finalValue << " meters.\n";
        else if (unitInfo(typeUnit, unit[0], unit[1]) == 132)
            cout << originalValue << " miles is equivalent to " << finalValue << " feet.\n";
        else if (unitInfo(typeUnit, unit[0], unit[1]) == 212)
            cout << originalValue << " cubic meters is equivalent to " << finalValue << " liters.\n";
        else if (unitInfo(typeUnit, unit[0], unit[1]) == 213)
            cout << originalValue << " cubic meters is equivalent to " << finalValue << " gallons.\n";
        else if (unitInfo(typeUnit, unit[0], unit[1]) == 221)
            cout << originalValue << " liters is equivalent to " << finalValue << " cubic meters.\n";
        else if (unitInfo(typeUnit, unit[0], unit[1]) == 223)
            cout << originalValue << " liters is equivalent to " << finalValue << " gallons.\n";
        else if (unitInfo(typeUnit, unit[0], unit[1]) == 231)
            cout << originalValue << " gallons is equivalent to " << finalValue << " cubic meters.\n";
        else if (unitInfo(typeUnit, unit[0], unit[1]) == 232)
            cout << originalValue << " gallons is equivalent to " << finalValue << " liters.\n";
        else if (unitInfo(typeUnit, unit[0], unit[1]) == 312)
            cout << originalValue << " joules is equivalent to " << finalValue << " calories.\n";
        else if (unitInfo(typeUnit, unit[0], unit[1]) == 313)
            cout << originalValue << " joules is equivalent to " << finalValue << " foot-pounds.\n";
        else if (unitInfo(typeUnit, unit[0], unit[1]) == 321)
            cout << originalValue << " calories is equivalent to " << finalValue << " joules.\n";
        else if (unitInfo(typeUnit, unit[0], unit[1]) == 323)
            cout << originalValue << " calories is equivalent to " << finalValue << " foot-pounds.\n";
        else if (unitInfo(typeUnit, unit[0], unit[1]) == 331)
            cout << originalValue << " foot-pounds is equivalent to " << finalValue << " joules.\n";
        else if (unitInfo(typeUnit, unit[0], unit[1]) == 332)
            cout << originalValue << " foot-pounds is equivalent to " << finalValue << " calories.\n";
        else if (unitInfo(typeUnit, unit[0], unit[1]) == 111)
            cout << originalValue << " meters is equivalent to " << finalValue << " meters.\n";
        else if (unitInfo(typeUnit, unit[0], unit[1]) == 122)
            cout << originalValue << " feet is equivalent to " << finalValue << " feet.\n";
        else if (unitInfo(typeUnit, unit[0], unit[1]) == 133)
            cout << originalValue << " miles is equivalent to " << finalValue << " miles.\n";
        else if (unitInfo(typeUnit, unit[0], unit[1]) == 211)
            cout << originalValue << " cubic meters is equivalent to " << finalValue << " cubic meters.\n";
        else if (unitInfo(typeUnit, unit[0], unit[1]) == 222)
            cout << originalValue << " liters is equivalent to " << finalValue << " liters.\n";
        else if (unitInfo(typeUnit, unit[0], unit[1]) == 233)
            cout << originalValue << " gallons is equivalent to " << finalValue << " gallons.\n";
        else if (unitInfo(typeUnit, unit[0], unit[1]) == 311)
            cout << originalValue << " joules is equivalent to " << finalValue << " joules.\n";
        else if (unitInfo(typeUnit, unit[0], unit[1]) == 322)
            cout << originalValue << " calories is equivalent to " << finalValue << " calories.\n";
        else //if (unitInfo(typeUnit, unit[0], unit[1]) == 333)
            cout << originalValue << " foot-pounds is equivalent to " << finalValue << " foot-pounds.\n";

        cout << "\n" << Name << ", thank you for using the Unit Converter!\n";
        cout << "Would you like to convert another measurement? (Type 1 for yes or 0 for no and then press return\n";
        cin >> again;
        if (again == true)
            cout << "Let's start at the beginning. \n\n";
    }
    while (again == true);
    // This loops back to line 29 to completely restart the program.

    cout << "\nHave a great day, " << Name << "! Come back anytime. \n";

    return 0;
}

int unitInfo(int typeUnitPar, int originalUnitPar, int convertedUnitPar) {
    int typeBase, originalBase, totalInfo;

    typeBase = 100 * typeUnitPar;
    originalBase = 10 * originalUnitPar;
    totalInfo = typeBase + originalBase + convertedUnitPar;
    return (totalInfo);
}