#include "../std_lib_facilities.h"

int main() {
    for (string word = ""; cin >> word; )
        if (word == "Broccoli" || word == "PHP" || word == "Javascript" || word == "Greenfoot")
            cout << "BLEEP\n";
        else
            cout << word << '\n'; 
}
