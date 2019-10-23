#include "../std_lib_facilities.h"

void print_names(vector<string> names, vector<int> scores, int sc) {
    for (size_t i = 0; i < scores.size(); ++i) {
        if (scores[i] == sc)
            cout << names[i] << '\n';
    } 
}

void print_score(vector<string> names, vector<int> scores, string nm) {
    for (size_t i = 0; i < names.size(); ++i) {
        if (names[i] == nm) {
            cout << scores[i] << '\n';
            return;
        }
    }
    cout << "Name not found.\n";
}

int main() {
    string name;
    int score;
    vector<string> names;
    vector<int> scores;
    while (cin >> name >> score && !(name == "NoName" && score == 0)) {
        if (find(names, name) != names.end()) {
            simple_error("duplicate name");
        }
        names.push_back(name);
        scores.push_back(score);
    }

    for (size_t i = 0; i < names.size(); ++i)
        cout << names[i] << ' ' << scores[i] << '\n'; 

    while (cin) {
        int sc = 0;
        cout << "Enter name or score:\n";
        if (cin >> sc)
            print_names(names, scores, sc);
        else {
            string nm;
            cin.clear();
            cin >> nm;
            print_score(names, scores, nm);
        }
    } 
}
