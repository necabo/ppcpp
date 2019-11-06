#include "../std_lib_facilities.h"

int main() {
    try {
        cout << "Please enter the number of values you want to sum:\n";
        size_t n;
        cin >> n;
        if (n < 1)
            error("Can't sum less than one value.");
        cout << "Please enter some values (press '|' to stop):\n";
        vector<double> values;
        double temp;
        while (cin >> temp) {
            values.push_back(temp);
        }
        if (n > values.size())
            error("Can't sum " + to_string(n) + " values as you have only provided " + to_string(values.size()) + " values to sum.");
        double sum = 0;
        for (size_t i = 0; i < n; ++i)
            sum += values[i];
        cout << "The sum of the first " << n << " provided values is: " << sum << ".\n";
        return 0;
    } catch (exception& e) {
        cerr << "Error: " << e.what() << '\n';
        return 1;
    } catch (...) {
        cerr << "Unknown exception!\n";
        return 2;
    }
}