#include "../std_lib_facilities.h"

int maxv(const vector<int>& vec) {
    int max = vec[0];
    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i] > max) max = vec[i];
    }
    return max;
}

int main() {
    vector<int> foo {12, 124, 12, 1254, 46, 6213, 1623, 6346, 2314, 623};
    cout << maxv(foo) << endl;
}
