// Unit Converter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

int typeUnit, originalUnit, convertedUnit, decimalPlace;
double originalValue, finalValue, conversion; 
bool confirmation, again;

int main()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(5);
    cout << "Unit Converter\n";
    do
    {
        cout << "How many decimal places do you want in your conversion? (Enter number and then press return) \n";
        cin >> decimalPlace;
        decimalPlace++;
        cout << "You are going to have " << decimalPlace << " decimal places for rounding accuracy. \n";
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(decimalPlace);

        do
        {
            cout << "What is your unit type? (Type the corresponding number and then press return)\n";
            cout << "1. length\n" << "2. volume \n" << "3. energy\n";
            cin >> typeUnit;

            cout << "What is your original unit? (Type the corresponding number and then press return)\n";
            if (typeUnit == 1)
                cout << "1. meters\n" << "2. feet\n" << "3. miles\n";
                else if (typeUnit == 2)
                    cout << "1. cubic meters\n" << "2. liters\n" << "3. gallons \n";
                else
                    cout << "1. joules\n" << "2. calories\n" << "3. foot-pounds \n";
            cin >> originalUnit;

            cout << "What is your preferred unit? (Type the corresponding number and then press return)\n";
            if (typeUnit == 1)
                cout << "1. meters\n" << "2. feet\n" << "3. miles \n";
                else if (typeUnit == 2)
                    cout << "1. cubic meters\n" << "2. liters\n" << "3. gallons \n";
                else
                    cout << "1. joules\n" << "2. calories\n" << "3. foot-pounds \n";
            cin >> convertedUnit;

            if ((typeUnit == 1) && (originalUnit == 1) && (convertedUnit == 2))
                cout << "You are converting from meters to feet.\n";
                else if ((typeUnit == 1) && (originalUnit == 1) && (convertedUnit == 3))
                    cout << "You are converting from meters to miles.\n";
                else if ((typeUnit == 1) && (originalUnit == 2) && (convertedUnit == 1))
                    cout << "You are converting from feet to meters.\n";
                else if ((typeUnit == 1) && (originalUnit == 2) && (convertedUnit == 3))
                    cout << "You are converting from feet to miles.\n";
                else if ((typeUnit == 1) && (originalUnit == 3) && (convertedUnit == 1))
                    cout << "You are converting from miles to meters.\n";
                else if ((typeUnit == 1) && (originalUnit == 3) && (convertedUnit == 2))
                    cout << "You are converting from miles to feet.\n";
                else if ((typeUnit == 2) && (originalUnit == 1) && (convertedUnit == 2))
                    cout << "You are converting from cubic meters to liters.\n";
                else if ((typeUnit == 2) && (originalUnit == 1) && (convertedUnit == 3))
                    cout << "You are converting from cubic meters to gallons.\n";
                else if ((typeUnit == 2) && (originalUnit == 2) && (convertedUnit == 1))
                    cout << "You are converting from liters to cubic meters.\n";
                else if ((typeUnit == 2) && (originalUnit == 2) && (convertedUnit == 3))
                    cout << "You are converting from liters to gallons.\n";
                else if ((typeUnit == 2) && (originalUnit == 3) && (convertedUnit == 1))
                    cout << "You are converting from gallons to cubic meters.\n";
                else if ((typeUnit == 2) && (originalUnit == 3) && (convertedUnit == 2))
                    cout << "You are converting from gallons to liters.\n";
                else if ((typeUnit == 3) && (originalUnit == 1) && (convertedUnit == 2))
                    cout << "You are converting from joules to calories.\n";
                else if ((typeUnit == 3) && (originalUnit == 1) && (convertedUnit == 3))
                    cout << "You are converting from joules to foot-pounds.\n";
                else if ((typeUnit == 3) && (originalUnit == 2) && (convertedUnit == 1))
                    cout << "You are converting from calories to joules.\n";
                else if ((typeUnit == 3) && (originalUnit == 2) && (convertedUnit == 3))
                    cout << "You are converting from calories to foot-pounds.\n";
                else if ((typeUnit == 3) && (originalUnit == 3) && (convertedUnit == 1))
                    cout << "You are converting from foot-pounds to joules.\n";
                else if ((typeUnit == 3) && (originalUnit == 3) && (convertedUnit == 2))
                    cout << "You are converting from foot-pounds to calories.\n";
                else if ((typeUnit == 1) && (originalUnit == 1) && (convertedUnit == 1))
                    cout << "You are converting between the same unit (meters).\n";
                else if ((typeUnit == 1) && (originalUnit == 2) && (convertedUnit == 2))
                    cout << "You are converting between the same unit (feet).\n";
                else if ((typeUnit == 1) && (originalUnit == 3) && (convertedUnit == 3))
                    cout << "You are converting between the same unit (miles).\n";
                else if ((typeUnit == 2) && (originalUnit == 1) && (convertedUnit == 1))
                    cout << "You are converting between the same unit (cubic meters).\n";
                else if ((typeUnit == 2) && (originalUnit == 2) && (convertedUnit == 2))
                    cout << "You are converting between the same unit (liters).\n";
                else if ((typeUnit == 2) && (originalUnit == 3) && (convertedUnit == 3))
                    cout << "You are converting between the same unit (gallons).\n";
                else  if ((typeUnit == 3) && (originalUnit == 1) && (convertedUnit == 1))
                    cout << "You are converting between the same unit (joules).\n";
                else if ((typeUnit == 3) && (originalUnit == 2) && (convertedUnit == 2))
                    cout << "You are converting between the same unit (calories).\n";
                else
                    cout << "You are converting between the same unit (foot-pounds).\n";

            cout << "Is this correct? (Type 1 for yes or 0 for no and then press return)\n";
            cin >> confirmation;
            if (confirmation == false)
                cout << "Let's try again. \n";
            else
                cout << "Great! Let's continue.\n";
        } while (confirmation == false);

        cout << "What is the value of your original measurement? (Enter and then press return)\n";
        cin >> originalValue;

        if ((typeUnit == 1) && (originalUnit == 1) && (convertedUnit == 2))
        {
            finalValue = originalValue * 3.2808399;
            cout << originalValue << " meters is equivalent to " << finalValue << " feet.\n";
        }
            else if ((typeUnit == 1) && (originalUnit == 1) && (convertedUnit == 3))
            {
                finalValue = originalValue * 0.00062137;
                cout << originalValue << " meters is equivalent to " << finalValue << " miles.\n";
            }
            else if ((typeUnit == 1) && (originalUnit == 2) && (convertedUnit == 1))
            {
                finalValue = originalValue * 0.3048;
                cout << originalValue << " feet is equivalent to " << finalValue << " meters.\n";
            }
            else if ((typeUnit == 1) && (originalUnit == 2) && (convertedUnit == 3))
            {
                finalValue = originalValue * 0.00018939;
                cout << originalValue << " feet is equivalent to " << finalValue << " miles.\n";
            }
            else if ((typeUnit == 1) && (originalUnit == 3) && (convertedUnit == 1))
            {
                finalValue = originalValue * 1609.344;
                cout << originalValue << " miles is equivalent to " << finalValue << " meters.\n";
            }
            else if ((typeUnit == 1) && (originalUnit == 3) && (convertedUnit == 2))
            {
                finalValue = originalValue * 5280.0;
                cout << originalValue << " miles is equivalent to " << finalValue << " feet.\n";
            }
            else if ((typeUnit == 2) && (originalUnit == 1) && (convertedUnit == 2))
            {
                finalValue = originalValue * 1000.0;
                cout << originalValue << " cubic meters is equivalent to " << finalValue << " liters.\n";
            }
            else if ((typeUnit == 2) && (originalUnit == 1) && (convertedUnit == 3))
            {
                finalValue = originalValue * 264.172053;
                cout << originalValue << " cubic meters is equivalent to " << finalValue << " gallons.\n";
            }
            else if ((typeUnit == 2) && (originalUnit == 2) && (convertedUnit == 1))
            {
                finalValue = originalValue * 0.001;
                cout << originalValue << " liters is equivalent to " << finalValue << " cubic meters.\n";
            }
            else if ((typeUnit == 2) && (originalUnit == 2) && (convertedUnit == 3))
            {
                finalValue = originalValue * 0.26417205;
                cout << originalValue << " liters is equivalent to " << finalValue << " gallons.\n";
            }
            else if ((typeUnit == 2) && (originalUnit == 3) && (convertedUnit == 1))
            {
                finalValue = originalValue * 0.00378541;
                cout << originalValue << " gallons is equivalent to " << finalValue << " cubic meters.\n";
            }
            else if ((typeUnit == 2) && (originalUnit == 3) && (convertedUnit == 2))
            {
                finalValue = originalValue * 3.78541178;
                cout << originalValue << " gallons is equivalent to " << finalValue << " liters.\n";
            }
            else if ((typeUnit == 3) && (originalUnit == 1) && (convertedUnit == 2))
            {
                finalValue = originalValue * 0.23900574;
                cout << originalValue << " joules is equivalent to " << finalValue << " calories.\n";
            }
            else if ((typeUnit == 3) && (originalUnit == 1) && (convertedUnit == 3))
            {
                finalValue = originalValue * 0.73756215;
                cout << originalValue << " joules is equivalent to " << finalValue << " foot-pounds.\n";
            }
            else if ((typeUnit == 3) && (originalUnit == 2) && (convertedUnit == 1))
            {
                finalValue = originalValue * 4.184;
                cout << originalValue << " calories is equivalent to " << finalValue << " joules.\n";
            }
            else if ((typeUnit == 3) && (originalUnit == 2) && (convertedUnit == 3))
            {
                finalValue = originalValue * 3.08596003;
                cout << originalValue << " calories is equivalent to " << finalValue << " foot-pounds.\n";
            }
            else if ((typeUnit == 3) && (originalUnit == 3) && (convertedUnit == 1))
            {
                finalValue = originalValue * 1.35581795;
                cout << originalValue << " foot-pounds is equivalent to " << finalValue << " joules.\n";
            }
            else if ((typeUnit == 3) && (originalUnit == 3) && (convertedUnit == 2))
            {
                finalValue = originalValue * 0.32404827;
                cout << originalValue << " foot-pounds is equivalent to " << finalValue << " calories.\n";
            }
            else if ((typeUnit == 1) && (originalUnit == 1) && (convertedUnit == 1))
            {
                finalValue = originalValue;
                cout << originalValue << " meters is equivalent to " << finalValue << " meters.\n";
            }
            else if ((typeUnit == 1) && (originalUnit == 2) && (convertedUnit == 2))
            {
                finalValue = originalValue;
                cout << originalValue << " feet is equivalent to " << finalValue << " feet.\n";
            }
            else if ((typeUnit == 1) && (originalUnit == 3) && (convertedUnit == 3))
            {
                finalValue = originalValue;
                cout << originalValue << " miles is equivalent to " << finalValue << " miles.\n";
            }
            else if ((typeUnit == 2) && (originalUnit == 1) && (convertedUnit == 1))
            {
                finalValue = originalValue;
                cout << originalValue << " cubic meters is equivalent to " << finalValue << " cubic meters.\n";
            }
            else if ((typeUnit == 2) && (originalUnit == 2) && (convertedUnit == 2))
            {
                finalValue = originalValue;
                cout << originalValue << " liters is equivalent to " << finalValue << " liters.\n";
            }
            else if ((typeUnit == 2) && (originalUnit == 3) && (convertedUnit == 3))
            {
                finalValue = originalValue;
                cout << originalValue << " gallons is equivalent to " << finalValue << " gallons.\n";
            }
            else if ((typeUnit == 3) && (originalUnit == 1) && (convertedUnit == 1))
            {
                finalValue = originalValue;
                cout << originalValue << " joules is equivalent to " << finalValue << " joules.\n";
            }
            else if ((typeUnit == 3) && (originalUnit == 2) && (convertedUnit == 2))
            {
                finalValue = originalValue;
                cout << originalValue << " calories is equivalent to " << finalValue << " calories.\n";
            }
            else
            {
                finalValue = originalValue;
                cout << originalValue << " foot-pounds is equivalent to " << finalValue << " foot-pounds.\n";
            }

        cout << "Thank you for using the Unit Converter!\n";
        cout << "Would you like to convert another measurement? (Type 1 for yes or 0 for no and then press return\n";
        cin >> again;
        if (again == true)
            cout << "Let's start at the beginning. \n";
        else
            cout << "Have a great day! Come back anytime. \n";
    }
    while (again == true);

    return 0;
}