#include "../std_lib_facilities.h"

int main() {
    cout << "Enter some strings:\n";
    string temp;
    vector<string> strings;
    vector<int> occurences;
    while (cin >> temp) {
        vector<string>::iterator it = find(strings, temp);
        if (it == strings.end()) {
            strings.push_back(temp);
            occurences.push_back(1);
        } else {
            int index = distance(strings.begin(), it);
            ++occurences[index];
        }
    }
    vector<int>::iterator it = max_element(occurences.begin(), occurences.end());
    int index = distance(occurences.begin(), it);
    cout << "The min of the given series is: " << *min_element(strings.begin(), strings.end()) << '\n';
    cout << "The max of the given series is: " << *max_element(strings.begin(), strings.end()) << '\n';
    cout << "The mode (" << *it << " occurences) of the given series is: " << strings[index] << '\n';
}
