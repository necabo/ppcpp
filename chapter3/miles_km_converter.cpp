#include "../std_lib_facilities.h"

int main() {
    cout << "Enter the number of miles to convert:\n";
    double miles {0};
    cin >> miles;
    cout << miles << " mile(s) are " << miles * 1.609 << " kilometer(s).\n";
}
