#include "../std_lib_facilities.h"

int main() {
    cout << "Enter some positive integers:\n";
    int temp;
    vector<int> integers;
    vector<int> occurences;
    while (cin >> temp) {
        vector<int>::iterator it = find(integers, temp);
        if (it == integers.end()) {
            integers.push_back(temp);
            occurences.push_back(1);
        } else {
            int index = distance(integers.begin(), it);
            ++occurences[index];
        }
    }
    vector<int>::iterator it = max_element(occurences.begin(), occurences.end());
    int index = distance(occurences.begin(), it);
    cout << "The mode (" << *it << " occurences) of the given series is: " << integers[index] << '\n';
}
