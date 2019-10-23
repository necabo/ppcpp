#include "../std_lib_facilities.h"

int main() {
    double first, second;
    char op;
    cout << "Please enter two numbers and an operator.\n";
    while (cin >> first >> second >> op) {
        switch (op) {
            case '+':
                cout << "The sum of " << first << " and " << second << " is " << first + second << ".\n";
                break;
            case '-':
                cout << "The difference of " << first << " and " << second << " is " << first - second << ".\n";
                break;
            case '*':
                cout << "The product of " << first << " times " << second << " is " << first * second << ".\n";
                break;
            case '/':
                cout << "The quotient of " << first << " divided by " << second << " is " << first / second << ".\n";
                break;
            default:
                cout << "Invalid operator.\n";
                break;
        }
    }
}
