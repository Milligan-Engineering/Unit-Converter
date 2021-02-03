// Unit Converter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

int typeUnit;
double originalValue, finalValue;
string OriginalUnit, ConvertedUnit, Confirmation;

int main()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(5);
    cout << "Unit Converter\n";
    cout << "What is your unit type? (Type the number that corresponds and then press return)\n";
    cout << "1. length\n" << "2. volume \n" << "3. energy\n";
    cin >> typeUnit;
    cout << "What is your original unit? (Type exactly as shown below and then press return)\n";
    if (typeUnit == 1) { cout << "meters, feet, miles \n"; }
    if (typeUnit == 2) { cout << "cubic meters, liters, gallons \n"; }
    if (typeUnit == 3) { cout << "joules, calories, foot-pounds \n"; }
    cin >> OriginalUnit;
    cout << "What is your preferred unit? (Type exactly as shown below and then press return)\n";
    cout << "meters, feet, miles, cubic meters, liters, gallons, joules, calories, foot-pounds\n";
    cin >> ConvertedUnit;
    cout << "You are converting from" << " " << OriginalUnit << " to " << ConvertedUnit << "\n";
    cout << "Is this correct? (Type yes or no and then press return)\n";
    cin >> Confirmation;
    cout << "What is the value of your original measurement? (Enter and then press return)\n";
    cin >> originalValue;
    finalValue = 3.2808399 * originalValue;
    cout << originalValue << " " << OriginalUnit << " is equivalent to " << finalValue << " " << ConvertedUnit << "\n";
    cout << "Thank you for using the Unit Converter!";
   

}