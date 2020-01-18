#include "../std_lib_facilities.h"

void print(string label, const vector<int>& vec) {
    for (int v: vec) cout << label << " " << v << endl;
}

int main() {
    vector<int> vec {1, 2, 3, 4, 5};
    print("label this:", vec);
    return 0;
}
