#include <iostream>

using namespace std;

// @TODO: Create a simple calculator, with 4 fundamental operations
int main() {
    while (1) {
        int n1, n2, operation;
        string choice;
        double result;
        
        cout << "Enter your First number: ";
        cin >> n1;
        
        cout << "Enter your Second number: ";
        cin >> n2;
        
        cout << "Select Your Operations:\n1. Addition\n2. Subtraction\n3. Division\n4. Multiplication\n:>>";
        cin >> operation;
        
        switch (operation) {
            case 1:
                result = n1 + n2;
                break;
            case 2:
                result = n1 - n2;
                break;
            case 3:
                result = n2 / n1;
                break;
            case 4:
                result = n1 * n2;
                break;
        }
        cout << "Result: " << result << endl;
        cout << "Do you want to continue?: (y/n) ";
        cin >> choice;
        
        if (choice == "n" || choice == "no" || choice == "N") {
            break;
        }
    }
}
