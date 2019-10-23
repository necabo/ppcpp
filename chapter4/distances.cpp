#include "../std_lib_facilities.h"

int main() {
    vector<double> distances;
    double temp;
    double sum = 0;
    while (cin >> temp) {
        distances.push_back(temp);
        sum += temp;
    }
    cout << "Total distance: " << sum << '\n';
    sort(distances);
    cout << "Smallest distance: " << distances.front() << '\n';
    cout << "Greatest distance: " << distances.back() << '\n';
    cout << "Mean distance: " << sum / distances.size() << '\n';
}
