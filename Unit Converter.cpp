// File name: Unit Converter.cpp
// Author: Rachel Scheffer
// Email Address: rnscheffer@my.milligan.edu
// Description: Program to convert measurements between units.
// Assignment: Term Project
// Last Changed: February 15, 2021

#include <iostream>
#include <string>
using namespace std;

string Name;
int unit[2];
int decimalPlace, typeUnit;
double originalValue, finalValue; 
bool confirmation, again;
const double METERS_TO_FEET = 3.2808399;
const double METERS_TO_MILES = 0.00062137;
const double FEET_TO_MILES = 0.00018939;
const double CUBIC_METERS_TO_LITERS = 1000.0;
const double CUBIC_METERS_TO_GALLONS = 264.172053;
const double LITERS_TO_GALLONS = 0.26417205;
const double JOULES_TO_CALORIES = 0.23900574;
const double JOULES_TO_FOOT_POUNDS = 0.73756215;
const double CALORIES_TO_FOOT_POUNDS = 3.08596003;

int main(){

    cout << "Unit Converter\n";
    cout << "What is your name? (Enter your name and then press return) \n";
    cin >> Name;

    // This do-while statement allows the program to start over
    // if the user so chooses to convert another measurement. 
    do {
        cout << Name << ", how many decimal places do you want in your conversion? (Enter a number between 1 and 10 and then press return) \n";
        cin >> decimalPlace;
        decimalPlace++;
        cout << "You are going to have " << decimalPlace << " decimal places for rounding accuracy. \n";
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
                        cout << "What is your original unit? (Type the corresponding number and then press return)\n";
                        cout << "1. meters\n" << "2. feet\n" << "3. miles\n";
                        break;
                    case 2:
                        cout << "What is your original unit? (Type the corresponding number and then press return)\n";
                        cout << "1. cubic meters\n" << "2. liters\n" << "3. gallons \n";
                        break;
                    case 3:
                        cout << "What is your original unit? (Type the corresponding number and then press return)\n";
                        cout << "1. joules\n" << "2. calories\n" << "3. foot-pounds \n";
                        break;
                    default:
                        cout << "Invalid input. Try again. \n";
                }
            } while ((typeUnit != 1) && (typeUnit != 2) && (typeUnit != 3));
            //This loops back to line 51.
            
            //This do-while statement allows users to input their original unit again if they messed up.
            do {
                cin >> unit[0];
                if ((unit[0] != 1) && (unit[0] != 2) && (unit[0] != 3))
                    cout << "Invalid input. Try again. \n";
            } while ((unit[0] != 1) && (unit[0] != 2) && (unit[0] != 3));

            cout << "What is your converted unit? (Type the corresponding number and then press return)\n";
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

            if ((typeUnit == 1) && (unit[0] == 1) && (unit[1] == 2))
                cout << "You are converting from meters to feet.\n";
            else if ((typeUnit == 1) && (unit[0] == 1) && (unit[1] == 3))
                cout << "You are converting from meters to miles.\n";
            else if ((typeUnit == 1) && (unit[0] == 2) && (unit[1] == 1))
                cout << "You are converting from feet to meters.\n";
            else if ((typeUnit == 1) && (unit[0] == 2) && (unit[1] == 3))
                cout << "You are converting from feet to miles.\n";
            else if ((typeUnit == 1) && (unit[0] == 3) && (unit[1] == 1))
                cout << "You are converting from miles to meters.\n";
            else if ((typeUnit == 1) && (unit[0] == 3) && (unit[1] == 2))
                cout << "You are converting from miles to feet.\n";
            else if ((typeUnit == 2) && (unit[0] == 1) && (unit[1] == 2))
                cout << "You are converting from cubic meters to liters.\n";
            else if ((typeUnit == 2) && (unit[0] == 1) && (unit[1] == 3))
                cout << "You are converting from cubic meters to gallons.\n";
            else if ((typeUnit == 2) && (unit[0] == 2) && (unit[1] == 1))
                cout << "You are converting from liters to cubic meters.\n";
            else if ((typeUnit == 2) && (unit[0] == 2) && (unit[1] == 3))
                cout << "You are converting from liters to gallons.\n";
            else if ((typeUnit == 2) && (unit[0] == 3) && (unit[1] == 1))
                cout << "You are converting from gallons to cubic meters.\n";
            else if ((typeUnit == 2) && (unit[0] == 3) && (unit[1] == 2))
                cout << "You are converting from gallons to liters.\n";
            else if ((typeUnit == 3) && (unit[0] == 1) && (unit[1] == 2))
                cout << "You are converting from joules to calories.\n";
            else if ((typeUnit == 3) && (unit[0] == 1) && (unit[1] == 3))
                cout << "You are converting from joules to foot-pounds.\n";
            else if ((typeUnit == 3) && (unit[0] == 2) && (unit[1] == 1))
                cout << "You are converting from calories to joules.\n";
            else if ((typeUnit == 3) && (unit[0] == 2) && (unit[1] == 3))
                cout << "You are converting from calories to foot-pounds.\n";
            else if ((typeUnit == 3) && (unit[0] == 3) && (unit[1] == 1))
                cout << "You are converting from foot-pounds to joules.\n";
            else if ((typeUnit == 3) && (unit[0] == 3) && (unit[1] == 2))
                cout << "You are converting from foot-pounds to calories.\n";
            else if ((typeUnit == 1) && (unit[0] == 1) && (unit[1] == 1))
                cout << "You are converting between the same unit (meters).\n";
            else if ((typeUnit == 1) && (unit[0] == 2) && (unit[1] == 2))
                cout << "You are converting between the same unit (feet).\n";
            else if ((typeUnit == 1) && (unit[0] == 3) && (unit[1] == 3))
                cout << "You are converting between the same unit (miles).\n";
            else if ((typeUnit == 2) && (unit[0] == 1) && (unit[1] == 1))
                cout << "You are converting between the same unit (cubic meters).\n";
            else if ((typeUnit == 2) && (unit[0] == 2) && (unit[1] == 2))
                cout << "You are converting between the same unit (liters).\n";
            else if ((typeUnit == 2) && (unit[0] == 3) && (unit[1] == 3))
                cout << "You are converting between the same unit (gallons).\n";
            else  if ((typeUnit == 3) && (unit[0] == 1) && (unit[1] == 1))
                cout << "You are converting between the same unit (joules).\n";
            else if ((typeUnit == 3) && (unit[0] == 2) && (unit[1] == 2))
                cout << "You are converting between the same unit (calories).\n";
            else //if ((typeUnit == 3) && (unit[0] == 3) && (unit[1] == 3))
                cout << "You are converting between the same unit (foot-pounds).\n";

            cout << "Is this correct? (Type 1 for yes or 0 for no and then press return)\n";
            cin >> confirmation;
            if (confirmation == false)
                cout << "Let's try again. \n";
            else
                cout << "Great! Let's continue.\n";
        } 
        while (confirmation == false);
        // This loops back to line 45 to input the units again.

        cout << "What is the value of your original measurement? (Enter and then press return)\n";
        cin >> originalValue;

        // Each number is assigned to a type or unit as follows:
        // Unit Type: 1 = length, 2 = volume, 3 = energy
        // Length Units: 1 = meters, 2 = feet, 3 = miles
        // Volume Units: 1 = cubic meters, 2 = liters, 3 = gallons
        // Energy Units: 1 = joules, 2 = calories, 3 = foot-pounds
        if ((typeUnit == 1) && (unit[0] == 1) && (unit[1] == 2)){
            finalValue = originalValue * METERS_TO_FEET;
            cout << originalValue << " meters is equivalent to " << finalValue << " feet.\n";
        }
        else if ((typeUnit == 1) && (unit[0] == 1) && (unit[1] == 3)){
            finalValue = originalValue * METERS_TO_MILES;
            cout << originalValue << " meters is equivalent to " << finalValue << " miles.\n";
        }
        else if ((typeUnit == 1) && (unit[0] == 2) && (unit[1] == 1)){
            finalValue = originalValue / METERS_TO_FEET;
            cout << originalValue << " feet is equivalent to " << finalValue << " meters.\n";
        }
        else if ((typeUnit == 1) && (unit[0] == 2) && (unit[1] == 3)){
            finalValue = originalValue * FEET_TO_MILES;
            cout << originalValue << " feet is equivalent to " << finalValue << " miles.\n";
        }
        else if ((typeUnit == 1) && (unit[0] == 3) && (unit[1] == 1)){
            finalValue = originalValue / METERS_TO_MILES;
            cout << originalValue << " miles is equivalent to " << finalValue << " meters.\n";
        }
        else if ((typeUnit == 1) && (unit[0] == 3) && (unit[1] == 2)){
            finalValue = originalValue / FEET_TO_MILES;
            cout << originalValue << " miles is equivalent to " << finalValue << " feet.\n";
        }
        else if ((typeUnit == 2) && (unit[0] == 1) && (unit[1] == 2)){
            finalValue = originalValue * CUBIC_METERS_TO_LITERS;
            cout << originalValue << " cubic meters is equivalent to " << finalValue << " liters.\n";
        }
        else if ((typeUnit == 2) && (unit[0] == 1) && (unit[1] == 3)){
            finalValue = originalValue * CUBIC_METERS_TO_GALLONS;
            cout << originalValue << " cubic meters is equivalent to " << finalValue << " gallons.\n";
        }
        else if ((typeUnit == 2) && (unit[0] == 2) && (unit[1] == 1)){
            finalValue = originalValue / CUBIC_METERS_TO_LITERS;
            cout << originalValue << " liters is equivalent to " << finalValue << " cubic meters.\n";
        }
        else if ((typeUnit == 2) && (unit[0] == 2) && (unit[1] == 3)){
            finalValue = originalValue * LITERS_TO_GALLONS;
            cout << originalValue << " liters is equivalent to " << finalValue << " gallons.\n";
        }
        else if ((typeUnit == 2) && (unit[0] == 3) && (unit[1] == 1)){
            finalValue = originalValue / CUBIC_METERS_TO_GALLONS;
            cout << originalValue << " gallons is equivalent to " << finalValue << " cubic meters.\n";
        }
        else if ((typeUnit == 2) && (unit[0] == 3) && (unit[1] == 2)){
            finalValue = originalValue / LITERS_TO_GALLONS;
            cout << originalValue << " gallons is equivalent to " << finalValue << " liters.\n";
        }
        else if ((typeUnit == 3) && (unit[0] == 1) && (unit[1] == 2)){
            finalValue = originalValue * JOULES_TO_CALORIES;
            cout << originalValue << " joules is equivalent to " << finalValue << " calories.\n";
        }
        else if ((typeUnit == 3) && (unit[0] == 1) && (unit[1] == 3)){
            finalValue = originalValue * JOULES_TO_FOOT_POUNDS;
            cout << originalValue << " joules is equivalent to " << finalValue << " foot-pounds.\n";
        }
        else if ((typeUnit == 3) && (unit[0] == 2) && (unit[1] == 1)){
            finalValue = originalValue / JOULES_TO_CALORIES;
            cout << originalValue << " calories is equivalent to " << finalValue << " joules.\n";
        }
        else if ((typeUnit == 3) && (unit[0] == 2) && (unit[1] == 3)){
            finalValue = originalValue * CALORIES_TO_FOOT_POUNDS;
            cout << originalValue << " calories is equivalent to " << finalValue << " foot-pounds.\n";
        }
        else if ((typeUnit == 3) && (unit[0] == 3) && (unit[1] == 1)){
            finalValue = originalValue / JOULES_TO_FOOT_POUNDS;
            cout << originalValue << " foot-pounds is equivalent to " << finalValue << " joules.\n";
        }
        else if ((typeUnit == 3) && (unit[0] == 3) && (unit[1] == 2)){
            finalValue = originalValue / CALORIES_TO_FOOT_POUNDS;
            cout << originalValue << " foot-pounds is equivalent to " << finalValue << " calories.\n";
        }
        else if ((typeUnit == 1) && (unit[0] == 1) && (unit[1] == 1)){
            finalValue = originalValue;
            cout << originalValue << " meters is equivalent to " << finalValue << " meters.\n";
        }
        else if ((typeUnit == 1) && (unit[0] == 2) && (unit[1] == 2)){
            finalValue = originalValue;
            cout << originalValue << " feet is equivalent to " << finalValue << " feet.\n";
        }
        else if ((typeUnit == 1) && (unit[0] == 3) && (unit[1] == 3)){
            finalValue = originalValue;
            cout << originalValue << " miles is equivalent to " << finalValue << " miles.\n";
        }
        else if ((typeUnit == 2) && (unit[0] == 1) && (unit[1] == 1)){
            finalValue = originalValue;
            cout << originalValue << " cubic meters is equivalent to " << finalValue << " cubic meters.\n";
        }
        else if ((typeUnit == 2) && (unit[0] == 2) && (unit[1] == 2)){
            finalValue = originalValue;
            cout << originalValue << " liters is equivalent to " << finalValue << " liters.\n";
        }
        else if ((typeUnit == 2) && (unit[0] == 3) && (unit[1] == 3)){
            finalValue = originalValue;
            cout << originalValue << " gallons is equivalent to " << finalValue << " gallons.\n";
        }
        else if ((typeUnit == 3) && (unit[0] == 1) && (unit[1] == 1)){
            finalValue = originalValue;
            cout << originalValue << " joules is equivalent to " << finalValue << " joules.\n";
        }
        else if ((typeUnit == 3) && (unit[0] == 2) && (unit[1] == 2)){
            finalValue = originalValue;
            cout << originalValue << " calories is equivalent to " << finalValue << " calories.\n";
        }
        else{ //if ((typeUnit == 3) && (unit[0] == 3) && (unit[1] == 3))
            finalValue = originalValue;
            cout << originalValue << " foot-pounds is equivalent to " << finalValue << " foot-pounds.\n";
        }

        cout << Name << ", thank you for using the Unit Converter!\n";
        cout << "Would you like to convert another measurement? (Type 1 for yes or 0 for no and then press return\n";
        cin >> again;
        if (again == true)
            cout << "Let's start at the beginning. \n";
    }
    while (again == true);
    // This loops back to line 35 to completely restart the program.

    cout << "Have a great day, " << Name << "! Come back anytime. \n";

    return 0;
}