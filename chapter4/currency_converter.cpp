#include "../std_lib_facilities.h"

int main() {
    constexpr double yen_per_dollar = .0092;
    constexpr double kroner_per_dollar = .11;
    constexpr double pounds_per_dollar = 1.26;

    double amount = 1;
    char unit = ' ';
    cout << "Please enter an amount followed by a unit (y, k or p):\n";
    cin >> amount >> unit;

    switch (unit) {
        case 'y':
            cout << amount << "y == " << yen_per_dollar * amount << "d\n";
            break;
        case 'k':
            cout << amount << "k == " << kroner_per_dollar * amount << "k\n";
            break;
        case 'p':
            cout << amount << "p == " << pounds_per_dollar * amount << "p\n";
            break;
        default:
            cout << "Sorry, I don't know a unit called '" << unit << "'\n";
            break;
    }
}
