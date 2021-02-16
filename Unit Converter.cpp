// File name: Unit Converter.cpp
// Author: Rachel Scheffer
// Email Address: rnscheffer@my.milligan.edu
// Description: Program to convert measurements between units.
// Assignment: Term Project
// Last Changed: February 16, 2021

#include <iostream>
#include <string>
using namespace std;

string Name;
int unit[2];
int decimalPlace, typeUnit;
double originalValue, finalValue; 
bool confirmation, again;
const double FEET_PER_METER = 3.2808399;
const double MILES_PER_METER = 0.00062137;
const double MILES_PER_FOOT = 0.00018939;
const double LITERS_PER_CUBIC_METER = 1000.0;
const double GALLONS_PER_CUBIC_METER = 264.172053;
const double GALLONS_PER_LITER = 0.26417205;
const double CALORIES_PER_JOULE = 0.23900574;
const double FOOT_POUNDS_PER_JOULE = 0.73756215;
const double FOOT_POUNDS_PER_CALORIE = 3.08596003;

int main(){

    cout << "Unit Converter\n";
    cout << "What is your name? (Enter your name and then press return) \n";
    cin >> Name;

    // This do-while statement allows the program to start over
    // if the user so chooses to convert another measurement. 
    do {
        cout << "\n" << Name << ", how many decimal places do you want in your conversion? (Enter a number between 0 and 10 and then press return) \n";
        cin >> decimalPlace;

        for (decimalPlace; decimalPlace < 0; decimalPlace = decimalPlace * -1)
            cout << "Cannot have negative decimal places, changed to positive.\n";

        cout << "Added one for rounding accuracy.\n";
        decimalPlace++;
        cout << "You are going to have " << decimalPlace << " decimal places. \n\n";
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
                cout << "\nLet's try again. \n";
            else
                cout << "Great! Let's continue.\n";
        } 
        while (confirmation == false);
        // This loops back to line 50 to input the units again.

        cout << "\nWhat is the value of your original measurement? (Enter and then press return)\n";
        cin >> originalValue;
        cout << "\n";

        // Each number is assigned to a type or unit as follows:
        // Unit Type: 1 = length, 2 = volume, 3 = energy
        // Length Units: 1 = meters, 2 = feet, 3 = miles
        // Volume Units: 1 = cubic meters, 2 = liters, 3 = gallons
        // Energy Units: 1 = joules, 2 = calories, 3 = foot-pounds
        if ((typeUnit == 1) && (unit[0] == 1) && (unit[1] == 2)){
            finalValue = originalValue * FEET_PER_METER;
            cout << originalValue << " meters is equivalent to " << finalValue << " feet.\n";
        }
        else if ((typeUnit == 1) && (unit[0] == 1) && (unit[1] == 3)){
            finalValue = originalValue * MILES_PER_METER;
            cout << originalValue << " meters is equivalent to " << finalValue << " miles.\n";
        }
        else if ((typeUnit == 1) && (unit[0] == 2) && (unit[1] == 1)){
            finalValue = originalValue / FEET_PER_METER;
            cout << originalValue << " feet is equivalent to " << finalValue << " meters.\n";
        }
        else if ((typeUnit == 1) && (unit[0] == 2) && (unit[1] == 3)){
            finalValue = originalValue * MILES_PER_FOOT;
            cout << originalValue << " feet is equivalent to " << finalValue << " miles.\n";
        }
        else if ((typeUnit == 1) && (unit[0] == 3) && (unit[1] == 1)){
            finalValue = originalValue / MILES_PER_METER;
            cout << originalValue << " miles is equivalent to " << finalValue << " meters.\n";
        }
        else if ((typeUnit == 1) && (unit[0] == 3) && (unit[1] == 2)){
            finalValue = originalValue / MILES_PER_FOOT;
            cout << originalValue << " miles is equivalent to " << finalValue << " feet.\n";
        }
        else if ((typeUnit == 2) && (unit[0] == 1) && (unit[1] == 2)){
            finalValue = originalValue * LITERS_PER_CUBIC_METER;
            cout << originalValue << " cubic meters is equivalent to " << finalValue << " liters.\n";
        }
        else if ((typeUnit == 2) && (unit[0] == 1) && (unit[1] == 3)){
            finalValue = originalValue * GALLONS_PER_CUBIC_METER;
            cout << originalValue << " cubic meters is equivalent to " << finalValue << " gallons.\n";
        }
        else if ((typeUnit == 2) && (unit[0] == 2) && (unit[1] == 1)){
            finalValue = originalValue / LITERS_PER_CUBIC_METER;
            cout << originalValue << " liters is equivalent to " << finalValue << " cubic meters.\n";
        }
        else if ((typeUnit == 2) && (unit[0] == 2) && (unit[1] == 3)){
            finalValue = originalValue * GALLONS_PER_LITER;
            cout << originalValue << " liters is equivalent to " << finalValue << " gallons.\n";
        }
        else if ((typeUnit == 2) && (unit[0] == 3) && (unit[1] == 1)){
            finalValue = originalValue / GALLONS_PER_CUBIC_METER;
            cout << originalValue << " gallons is equivalent to " << finalValue << " cubic meters.\n";
        }
        else if ((typeUnit == 2) && (unit[0] == 3) && (unit[1] == 2)){
            finalValue = originalValue / GALLONS_PER_LITER;
            cout << originalValue << " gallons is equivalent to " << finalValue << " liters.\n";
        }
        else if ((typeUnit == 3) && (unit[0] == 1) && (unit[1] == 2)){
            finalValue = originalValue * CALORIES_PER_JOULE;
            cout << originalValue << " joules is equivalent to " << finalValue << " calories.\n";
        }
        else if ((typeUnit == 3) && (unit[0] == 1) && (unit[1] == 3)){
            finalValue = originalValue * FOOT_POUNDS_PER_JOULE;
            cout << originalValue << " joules is equivalent to " << finalValue << " foot-pounds.\n";
        }
        else if ((typeUnit == 3) && (unit[0] == 2) && (unit[1] == 1)){
            finalValue = originalValue / CALORIES_PER_JOULE;
            cout << originalValue << " calories is equivalent to " << finalValue << " joules.\n";
        }
        else if ((typeUnit == 3) && (unit[0] == 2) && (unit[1] == 3)){
            finalValue = originalValue * FOOT_POUNDS_PER_CALORIE;
            cout << originalValue << " calories is equivalent to " << finalValue << " foot-pounds.\n";
        }
        else if ((typeUnit == 3) && (unit[0] == 3) && (unit[1] == 1)){
            finalValue = originalValue / FOOT_POUNDS_PER_JOULE;
            cout << originalValue << " foot-pounds is equivalent to " << finalValue << " joules.\n";
        }
        else if ((typeUnit == 3) && (unit[0] == 3) && (unit[1] == 2)){
            finalValue = originalValue / FOOT_POUNDS_PER_CALORIE;
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

        cout << "\n" << Name << ", thank you for using the Unit Converter!\n";
        cout << "Would you like to convert another measurement? (Type 1 for yes or 0 for no and then press return\n";
        cin >> again;
        if (again == true)
            cout << "Let's start at the beginning. \n\n";
    }
    while (again == true);
    // This loops back to line 35 to completely restart the program.

    cout << "\nHave a great day, " << Name << "! Come back anytime. \n";

    return 0;
}