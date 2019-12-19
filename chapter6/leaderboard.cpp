#include "../std_lib_facilities.h"

class Name_value {
    public:
        string name;
        int value;
};

bool contains(vector<Name_value> scores, string name) {
    for (size_t i = 0; i < scores.size(); ++i) {
        if (scores[i].name == name) return true;
    }
    return false;
}

void print_scores(vector<Name_value> scores) {
    for (size_t i = 0; i < scores.size(); ++i) {
        cout << scores[i].name << ' ' << scores[i].value << '\n';
    }
}

int main() {
    try {
        vector<Name_value> scores;
        string name;
        int value;
        while (cin >> name >> value && !(name == "NoName" && value == 0)) {
            cout << name << '\n';
            if (contains(scores, name)) simple_error("duplicate name");
            scores.push_back(Name_value{name, value});
        }
        print_scores(scores);
        return 0;

    } catch (exception& e) {
        cerr << "Error: " << e.what() << '\n';
        return 1;
    } catch (...) {
        cerr << "Unknown exception!\n";
        return 2;
    }
}
