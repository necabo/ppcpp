#include "library.h"

using namespace Library;

int main() {
    Book book = Book{
        "0-321-99278-4",
        "Programming: Principles and Practice Using C++",
        "Bjarne Stroustrup",
        Date(2014, Date::may, 15),
        Genre::nonfiction
    };
    cout << book << endl;
    return 0;
}
