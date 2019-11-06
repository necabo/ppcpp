#include "../std_lib_facilities.h"

bool is_n_in_numbers(int n, vector<int> numbers) {
    for (int number: numbers) {
        if (number == n)
            return true;
    }
    return false;
}

int main() {
    try {
        cout << "Enter a seed for your game:\n";
        int seed;
        cin >> seed;
        vector<int> numbers;
        numbers.reserve(4);
        seed_randint(seed);
        int temp_rand;
        while (numbers.size() < numbers.capacity()) {
            temp_rand = randint(10);
            if (!is_n_in_numbers(temp_rand, numbers))
                numbers.push_back(temp_rand);
        }
        vector<int> guesses;
        guesses.reserve(4);
        int bulls = 0;
        int cows = 0;
        int temp;
        while (bulls < 4) {
            cout << "Guess four digits:\n";
            for (size_t i = 0; i < numbers.size(); ++i) {
                cin >> temp;
                guesses.push_back(temp);
            }
            bulls = 0;
            cows = 0;
            for (size_t i = 0; i < guesses.size(); ++i) {
                if (guesses[i] == numbers[i])
                    ++bulls;
                else if (is_n_in_numbers(guesses[i], numbers))
                    ++cows;
            }
            cout << bulls << " bull";
            if (bulls != 1)
                cout << 's';
            cout << " and " << cows << " cow";
            if (cows != 1)
                cout << 's';
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