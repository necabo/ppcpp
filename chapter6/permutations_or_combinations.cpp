#include "../std_lib_facilities.h"

int factorial(int n) {
    int factor = n;
    while (n > 1) factor *= --n;
    if (factor < 1) error("factorial() overflow");
    return factor;
}

int permutations(int a, int b) {
    if (a <= b || a < 1 || b < 1) error("invalid arguments");
    return factorial(a) / factorial(a - b);
}

int combinations(int a, int b) {
    return permutations(a, b) / factorial(b);
}

int main() {
    try {
        cout << "Please enter two integers:\n";
        int a;
        int b;
        cin >> a >> b;
        cout << "Enter 'p' for permutations or 'c' for combinations:\n";
        char c;
        cin >> c;
        switch (c) {
            case 'p':
                cout << "Permutations: " << permutations(a, b) << '\n';
                break;
            case 'c':
                cout << "Combinations: " << combinations(a, b) << '\n';
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
