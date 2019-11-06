#include "../std_lib_facilities.h"

int main() {
    try {
        cout << "Enter values for a, b and c of a quadratic equation:\n";
        double a, b, c;
        cin >> a >> b >> c;
        double radicant = b * b - 4 * a * c;
        if (radicant < 0)
            error("Oh noes, complex roots!");
        double root = sqrt(radicant);
        double x1 = (-1 * b + root) / (2 * a);
        double x2 = (-1 * b - root) / (2 * a);
        cout << "The results are " << x1 << " and " << x2 << '\n';
        return 0;
    } catch (exception& e) {
        cerr << "Error: " << e.what() << '\n';
        return 1;
    } catch (...) {
        cerr << "Unknown exception!\n";
        return 2;
    }
}
