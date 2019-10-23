#include "../std_lib_facilities.h"

constexpr double cm_to_m = 0.01;
constexpr double in_to_m = 0.0254;
constexpr double ft_to_m = 0.3048;

double convert_to_meters(double value, string unit) {
    if (unit == "cm")
        return value * cm_to_m;
    else if (unit == "in")
        return value * in_to_m;
    else if (unit == "ft")
        return value * ft_to_m;
    else
        return value;
}

int main() {
    double value;
    string unit;  // can be cm, in, ft or m
    vector<double> values;
    cin >> value >> unit;

    double value_in_m = convert_to_meters(value, unit);
    values.push_back(value_in_m);

    // use meters for the sum
    double smallest = value_in_m;
    double largest = value_in_m;
    double sum = value_in_m;
    cout << value << unit << " the smallest so far, the largest so far\n";
    
    while (cin >> value >> unit) {
        double value_in_m = convert_to_meters(value, unit);
        values.push_back(value_in_m);
        cout << value << unit;
        sum += value_in_m;
        if (value_in_m < smallest) {
            smallest = value_in_m;
            cout << " the smallest so far";
        }
        if (value_in_m > largest) {
            largest = value_in_m;
            cout << " the largest so far";
        }
        cout << '\n';
    }

    cout << "smallest: " << smallest << "m\n";
    cout << "largest: " << largest << "m\n";
    cout << "sum: " << sum << "m\n";
    cout << "here are all the values:\n";
    sort(values);
    for (double value: values)
        cout << value << "m\n";
}
