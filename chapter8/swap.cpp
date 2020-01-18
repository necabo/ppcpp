#include <iostream>
using namespace std;

void swap_v(int a, int b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}
void swap_r(int& a, int& b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

// Does not compile!
// void swap_cr(const int& a, const int& b) {
//     int temp;
//     temp = a;
//     a = b;
//     b = temp;
// }

int main() {
    int x = 7;
    int y = 9;
    swap_v(x, y);  // Does not swap (pass-by-value)
    cout << x << ' ' << y << endl;
    swap_r(x, y);
    cout << x << ' ' << y << endl;

    const int cx = 7;
    const int cy = 9;
    swap_v(cx, cy); // Does not swap (pass-by-value)
    cout << cx << ' ' << cy << endl;
// Does not compile!
//    swap_r(cx, cy);
//    cout << cx << ' ' << cy << endl;

    double dx = 7.7;
    double dy = 9.9;
    swap_v(dx, dy); // Does not swap (pass-by-value)
    cout << dx << ' ' << dy << endl;
// Does not compile!
//    swap_r(dx, dy);
//    cout << dx << ' ' << dy << endl;

    return 0;
}
