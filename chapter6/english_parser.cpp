#include "../std_lib_facilities.h"

bool is_conjunction(string token) {
    return token == "and" || token == "or" || token == "but";
}

bool is_noun(string token) {
    return token == "birds" || token == "fish" || token == "C++";
}

bool is_verb(string token) {
    return token == "rules" || token == "fly" || token == "swim";
}

bool is_sentence() {
    string input;
    char dot;
    while (true) {
        cin >> input;
        if (!is_noun(input)) return false;
        cin >> input;
        if (!is_verb(input)) return false;
        cin >> dot;
        if (dot == '.') return true;
        else cin.putback(dot);
        cin >> input;
        if (!is_conjunction(input)) return false;
    }
}

int main() {
    try {
        while (cin) {
            if (is_sentence()) cout << "OK\n";
            else cout << "not OK\n";
        }
        return 0;
    } catch (exception& e) {
        cerr << "Error: " << e.what() << '\n';
        return 1;
    } catch (...) {
        cerr << "Unknown exception!\n";
        return 2;
    }
}

