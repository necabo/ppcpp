#include "../std_lib_facilities.h"

int main() {
    cout << "Think of a number between 1 and 100 then enter 'y' to start the game.\n";
    char user_input;
    cin >> user_input;
    if (user_input == 'y') {
        int low = 0;
        int high = 100;
        int guess;
        
        while (low <= high) {
            guess = (low + high) / 2;
            cout << "Is the number you are thinking of less than " << guess << "? Enter 'y' or 'n'.\n";
            cin >> user_input;
            switch (user_input) {
                case 'y':
                    high = guess - 1;
                    break;
                case 'n':
                    low = guess + 1;
                    break;
                default:
                    cout << "I don't understand that.\n";
                    break;
            }
        }
        cout << "Your number is " << high << ".\n"; 
    }
    cout << "Goodbye!\n";
}
