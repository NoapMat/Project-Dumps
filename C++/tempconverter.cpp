#include<iostream>

using namespace std;

// @TODO: Temperature, Celsius to Farenheit converter
int main() {
   int choice, temp;
   string sign;
   double result;
   cout << "Enter your temperature: ";
   cin >> temp;
   cout << "Pick One:\n1. Celsius to Farenheit\n2. Farenheit to Celsius\n: ";
   cin >> choice;
   switch (choice) {
      case 1:
         result = temp * 1.8 + 32;
         sign = "°F";
         break;
      case 2:
         result = (temp - 32) * 5 / 9;
         sign = "°C";
         break;
   }
   cout << "Your Temperature was: " << result << sign << endl;
}
