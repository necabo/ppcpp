#include "../std_lib_facilities.h"

int main() {
    cout << "Enter some prices (enter ';' to terminate): ";
    char c;
    vector<double> prices;
    double price;
    while (cin >> c && c != ';') {
        cin.unget();
        cin >> price;
        prices.push_back(price);
    }
    cout << "Enter the corresponding weights:" << endl;
    vector<double> weights;
    double weight;
    for (double price: prices) {
        cout << price << ": ";
        cin >> weight;
        weights.push_back(weight);
    }

    double sum = 0;
    for (size_t i = 0; i < prices.size(); ++i) {
        sum += prices[i] * weights[i];
    }
    cout << "The \"index\" is " << sum << endl;
}
