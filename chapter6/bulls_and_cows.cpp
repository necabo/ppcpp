#include "../std_lib_facilities.h"

bool contains(vector<char> chars, char c) {
    for (char ch: chars) {
        if (ch == c) return true;
    }
    return false;
}

int main() {
    try {
        cout << "Enter a seed for your game:\n";
        int seed;
        cin >> seed;
        vector<char> chars;
        string alphabet = "abcdefghjklmnopqrstuvwxyz";

        chars.reserve(4);
        seed_randint(seed);
        int temp_rand;
        while (chars.size() < chars.capacity()) {
            temp_rand = randint(25);
            if (!contains(chars, alphabet.at(temp_rand))) {
                chars.push_back(alphabet.at(temp_rand));
            }
        }
        vector<char> guesses;
        guesses.reserve(4);
        int bulls = 0;
        int cows = 0;
        char temp;
        while (bulls < 4) {
            cout << "Guess four characters:\n";
            for (size_t i = 0; i < chars.size(); ++i) {
                cin >> temp;
                guesses.push_back(temp);
            }
            bulls = 0;
            cows = 0;
            for (size_t i = 0; i < guesses.size(); ++i) {
                if (guesses[i] == chars[i]) ++bulls;
                else if (contains(chars, guesses[i])) ++cows;
            }
            cout << bulls << " bull";
            if (bulls != 1) cout << 's';
            cout << " and " << cows << " cow";
            if (cows != 1) cout << 's';
            cout << ".\n";
            guesses.clear();
        }
        return 0;
    } catch (exception& e) {
        cerr << "Error: " << e.what() << '\n';
        return 1;
    } catch (...) {
        cerr << "Unknown exception!\n";
        return 2;
    }
}
