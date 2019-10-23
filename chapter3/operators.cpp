#include "../std_lib_facilities.h"

int main () {
    cout << "Please enter a number and a name:\n";

    int count;
    cin >> count;
    string name;
    cin >> name;

    int c2 = count + 2;
    string s2 = name + " Jr. ";

    int c3 = count - 2;

    // Won't compile. Can't subtract strings.
    // string s3 = name - " Jr. ";

    cout << "count: " << count << ", name: " << name << ", c2: " << c2 << ", c3: " << c3 << ", s2: " << s2 << "\n";
}

