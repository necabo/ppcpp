#include "../std_lib_facilities.h"

int main() {
    try {
        cout << "Show the first n fibonacci numbers ('n') or the largest to fit in an int ('l'):\n";
        char mode;
        cin >> mode;
        vector<int> memoized {1, 1};

        switch (mode) {
            case 'n': {
                cout << "Enter how many fibonacci numbers to output:\n";
                size_t n;
                cin >> n;
                for (int i = 2; memoized.size() < n; ++i)
                    memoized.push_back(memoized[i-2] + memoized[i - 1]);
                cout << "The first " << n << " fibonacci numbers are:\n";
                for (int i: memoized)
                    cout << i << '\n';
            }
                break;
            case 'l': {
                int next = memoized[0] + memoized[1];
                while (next > memoized[memoized.size() - 1]) {
                    memoized.push_back(next);
                    next = memoized[memoized.size() - 2] + memoized[memoized.size() - 1];
                }
                cout << "The largest fibonacci number to fit in an int is: " << memoized[memoized.size() - 1] << '\n';
            }
                break;
            default:
                error("Invalid input.");
                break;
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