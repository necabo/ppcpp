#include "../std_lib_facilities.h"

int main() {
    for (char chr = 'A'; chr <= 'Z'; ++chr)
        cout << chr << '\t' << int(chr) << '\n';
    for (char chr = 'a'; chr <= 'z'; ++chr)
        cout << chr << '\t' << int(chr) << '\n';
}
