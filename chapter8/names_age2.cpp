#include "../std_lib_facilities.h"

void print(const vector<string>& names, const vector<int>& ages) {
    for (size_t i = 0; i < names.size(); ++i) cout << names[i] << ", " << ages[i] << endl;
}

int index_of(const vector<string>& v, const string& s) {
    for (size_t i = 0; i < v.size(); ++i) if (v[i] == s) return i;
    return -1;
}

void sort_ages(
    const vector<string>& old_names,
    const vector<int>& old_ages,
    const vector<string>& names,
    vector<int>& ages
) {
    for (size_t i = 0; i < old_names.size(); ++i) ages[index_of(names, old_names[i])] = old_ages[i];
}

int main() {
    vector<string> names;
    cout << "Enter some names (enter ';' to terminate): ";
    string name;
    while (cin >> name && name != ";") names.push_back(name);

    vector<int> ages;
    ages.reserve(names.size());
    cout << "Enter the corresponding ages: " << endl;
    int age;
    
    for (const string& name: names) {
        cout << name << ": ";
        cin >> age;
        ages.push_back(age);
    }

    cout << "Inserting order:" << endl;
    print(names, ages);

    vector<string> names_copy = names;
    sort(names.begin(), names.end());
    vector<int> ages_copy = ages;
    sort_ages(names_copy, ages_copy, names, ages);

    cout << "Alphabetical order:" << endl;
    print(names, ages);
}
