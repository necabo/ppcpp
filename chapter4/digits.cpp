#include "../std_lib_facilities.h"

int main() {
    vector<string> digits {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string input;
    while (cin >> input) {
        if (input.length() == 1)
            cout << digits[stoi(input)] << '\n';
        else
            cout << distance(digits.begin(), find(digits, input)) << '\n';
    }
}
