#include "../std_lib_facilities.h"

double ctok(double c) {
    if (c < -273.15)
        error("Can't go below absolute zero.");
    double k = c + 273.15;
    return k;
}

double ktoc(double k) {
    if (k < 0)
        error("Can't go below absolute zero.");
    double c = k - 273.15;
    return c;
}

int main() {
    try {
        cout << "Convert from (Enter 'c' or 'k'):\n";
        char unit;
        cin >> unit;
        if (unit != 'c' && unit != 'k')
            error("Unknown unit");
        double value;
        cin >> value;
        switch (unit) {
            case 'c':
                cout << ctok(value) << '\n';
                break;
            case 'k':
                cout << ktoc(value) << '\n';
                break;
            default:
                break;
        }
        return 0;
    } catch (exception& e) {
        cerr << "Error: " << e.what() << '\n';
        return 1;
    } catch (...) {
        cerr << "Unknown exception!\n";
        return 2;
    }
}