#include "../std_lib_facilities.h"

void reassign_and_print(const int i) {
    // i = 42; // NOTE: can't reassign const parameter
    cout << i << endl;
}

int main() {
    int i = 7;
    reassign_and_print(i);
}
