#include "../std_lib_facilities.h"

int main() {
    vector<char> moves {'r', 'p', 's'};

    int prng_number;
    cout << "Enter some number that's on your mind:\n";
    cin >> prng_number;
    prng_number %= 3;

    char move;
    cout << "Enter Rock (r), Paper (p) or Scissors (s): \n";
    cin >> move;

    switch (move) {
        case 'r':
            if (moves[prng_number] == 'p')
                cout << "You lose.\n";
            else if(moves[prng_number] == 's')
                cout << "You win.\n";
            else
                cout << "It's a tie.\n";
            break;
        case 'p':
            if (moves[prng_number] == 'r')
                cout << "You win.\n";
            else if (moves[prng_number] == 's')
                cout << "You lose.\n";
            else
                cout << "It's a tie.\n";
            break;
        case 's':
            if (moves[prng_number] == 'r')
                cout << "You lose.\n";
            else if (moves[prng_number] == 'p')
                cout << "You win.\n";
            else
                cout << "It's a tie.\n";
            break;
    }
}
