#include "../std_lib_facilities.h"

double ctof(double c) {
    if (c < -273.15)
        error("Can't go below absolute zero.");
    double f = c * 1.8 + 32;
    return f;
}

double ftoc(double f) {
    if (f < -459.67)
        error("Can't go below absolute zero.");
    double c = (f - 32) / 1.8;
    return c;
}

int main() {
    try {
        cout << "Convert from (Enter 'c' or 'f'):\n";
        char unit;
        cin >> unit;
        if (unit != 'c' && unit != 'f')
            error("Unknown unit");
        double value;
        cin >> value;
        switch (unit) {
            case 'c':
                cout << ctof(value) << '\n';
                break;
            case 'f':
                cout << ftoc(value) << '\n';
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