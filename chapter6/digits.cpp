#include "../std_lib_facilities.h"

int main() {
    try {
        char digit;
        vector<int> digits;
        for (int i = 0; i < 4 && cin >> digit; i++) {
            digits.push_back(digit - '0');
        }

        int number = 0;
        for (size_t i = digits.size() - 1, factor = 1; i != size_t(-1); --i, factor *= 10) {
            number += digits[i] * factor;
        }
        cout << number << " is ";
        if (digits.size() == 1) {
            cout << digits[0] << " one";
            if (digits[0] != 1) cout << 's';
        }
        if (digits.size() == 2) {
            cout << digits[0] << " ten";
            if (digits[0] != 1) cout << 's';
            cout << " and " << digits[1] << " one";
            if (digits[1] != 1) cout << 's';
        }
        if (digits.size() == 3) {
            cout << digits[0] << " hundred";
            if (digits[0] != 1) cout << 's';
            cout << " and " << digits[1] << " ten";
            if (digits[1] != 1) cout << 's';
            cout << " and " << digits[2] << " one";
            if (digits[2] != 1) cout << 's';
        }
        if (digits.size() == 4) {
            cout << digits[0] << " thousand";
            if (digits[0] != 1) cout << 's';
            cout << " and " << digits[1] << " hundred";
            if (digits[1] != 1) cout << 's';
            cout << " and " << digits[2] << " ten";
            if (digits[2] != 1) cout << 's';
            cout << " and " << digits[3] << " one";
            if (digits[3] != 1) cout << 's';
        }
        cout << '\n';

        return 0;
    } catch (exception& e) {
        cerr << "Error: " << e.what() << '\n';
        return 1;
    } catch (...) {
        cerr << "Unknown exception!\n";
        return 2;
    }
}
