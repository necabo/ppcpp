#include "../std_lib_facilities.h"

vector<int> reverse(const vector<int>& vec) {
    vector<int> reversed;
    for (vector<int>::const_reverse_iterator it = vec.rbegin(); it != vec.rend(); ++it) {
        reversed.push_back(*it);
    }
    return reversed;
}

void reverse2(vector<int>& vec) {
    for (size_t i = 0; i < vec.size() / 2; ++i) {
        swap(vec[0 + i], vec[vec.size() - 1 - i]);
    }
}

void print(string label, const vector<int>& vec) {
    for (int v: vec) cout << label << " " << v << endl;
}

int main() {
    vector<int> vec{1, 3, 5, 7, 9};
    print("original vector:", vec);
    vector<int> reversed = reverse(vec);
    print("reverse()d vector:", reversed);
    reverse2(vec);
    print("reverse2()d vector:", vec);
    return 0;
}
