#include "../std_lib_facilities.h"

void print(string label, const vector<int>& vec) {
    for (int v: vec) cout << label << " " << v << endl;
}

void fibonacci(int x, int y, vector<int>& v) {
    v.push_back(x);
    v.push_back(y);
    while (true) {
        int temp = v[v.size() - 2] + v[v.size() - 1];
        if (temp > 0) v.push_back(temp);
        else break;
    }
}

int main() {
    vector<int> vec{};
    fibonacci(1, 2, vec);
    print("fibonacci sequence:", vec);
    cout << "max fibonacci int is: " << vec[vec.size() - 1] << endl;
    return 0;
}
