#include "../std_lib_facilities.h"

class Name_pairs {
    public:
        vector<string> name;
        vector<double> age;

        void read_names();
        void read_ages();
        void sort();
};

void Name_pairs::read_names() {
    string n;
    cout << "Please enter some names (terminate with ';'): " << endl;
    while (cin >> n) {
        if (n == ";") break;
        name.push_back(n);
    }
}

void Name_pairs::read_ages() {
    int a;
    for (const string& n: name) {
        cout << "Please enter an age for " << n << ": ";
        cin >> a;
        age.push_back(a);
    }
}

void Name_pairs::sort() {
    vector<string> sorted_name = name;
    ::sort(sorted_name);
    vector<double> sorted_age;

    for (size_t i = 0; i < sorted_name.size(); ++i) {
        for (size_t j = 0; j < name.size(); ++j) {
            if (sorted_name[i] == name[j]) sorted_age.push_back(age[j]);
        }
    }
    name = sorted_name;
    age = sorted_age;
}

ostream& operator<<(ostream& os, const Name_pairs& np) {
    os << "Name: " << np.name[0] << ", Age: " << np.age[0];
    for (size_t i = 1; i < np.name.size(); ++i) {
        os << endl << "Name: " << np.name[i] << ", Age: " << np.age[i];
    }
    return os;
}

bool operator==(const Name_pairs& a, const Name_pairs& b) {
    return a.name == b.name && b.age == b.age;
}

bool operator!=(const Name_pairs& a, const Name_pairs& b) {
    return !(a == b);
}

int main() {
    Name_pairs np = Name_pairs{};
    np.read_names();
    np.read_ages();
    cout << np << endl;
    cout << "Sorting..." << endl;
    np.sort();
    cout << np << endl;

    Name_pairs np2 = Name_pairs{};
    np2.read_names();
    np2.read_ages();
    cout << "Equal?: " << (np == np2) << endl;
    cout << "Not equal?: " << (np != np2) << endl;
}
