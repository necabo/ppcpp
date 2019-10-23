#include "../std_lib_facilities.h"

int main() {
    cout << "Enter values for a, b and c of a quadratic equation:\n";
    double a, b, c;
    cin >> a >> b >> c;
    double root = sqrt(b * b - 4 * a * c);
    double x1 = (-1 * b + root) / 2 * a;
    double x2 = (-1 * b - root) / 2 * a;
    cout << "The results are " << x1 << " and " << x2 << '\n';
}
