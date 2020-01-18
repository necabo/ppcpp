#include "../std_lib_facilities.h"

void print(string label, const vector<int>& vec) {
    for (int v: vec) cout << label << " " << v << endl;
}

void fibonacci(int x, int y, vector<int>& v, size_t n) {
    v.push_back(x);
    v.push_back(y);
    while (v.size() < n) v.push_back(v[v.size() - 2] + v[v.size() - 1]);
}

int main() {
    vector<int> vec{};
    fibonacci(1, 2, vec, 7);
    print("fibonacci sequence:", vec);
    return 0;
}
