#include "../std_lib_facilities.h"

int main() {
    int square = 1;
    int grains = 1;
    int total_grains {grains};
    vector<int> required_squares;

    while (total_grains <= 1000000000) {
        cout << "square: " << square << ", "
             << "grains: " << grains << ", "
             << "total grains: " << total_grains << '\n';
        ++square;
        grains *= 2;
        total_grains += grains;
    }
}
