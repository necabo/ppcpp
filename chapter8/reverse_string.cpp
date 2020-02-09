#include "../std_lib_facilities.h"

vector<string> reverse(const vector<string>& vec) {
    vector<string> reversed;
    for (vector<string>::const_reverse_iterator it = vec.rbegin(); it != vec.rend(); ++it) {
        reversed.push_back(*it);
    }
    return reversed;
}

void reverse2(vector<string>& vec) {
    for (size_t i = 0; i < vec.size() / 2; ++i) {
        swap(vec[0 + i], vec[vec.size() - 1 - i]);
    }
}

void print(string label, const vector<string>& vec) {
    for (string v: vec) cout << label << " " << v << endl;
}

int main() {
    vector<string> vec{"1", "3", "5", "7", "9"};
    print("original vector:", vec);
    vector<string> reversed = reverse(vec);
    print("reverse()d vector:", reversed);
    reverse2(vec);
    print("reverse2()d vector:", vec);
    return 0;
}
