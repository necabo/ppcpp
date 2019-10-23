#include <vector> 
#include <iostream> 
#include <cmath> 
using namespace std;

int main() {
    int n;
    cout << "Enter a number up to which you want to know the prime numbers:\n";
    cin >> n;
    vector<bool> striked(n, false);
    striked[0] = true;
    striked[1] = true;
    vector<int> primes;
    for (int i = 2; i <= sqrt(n); ++i) {
        if (!striked[i]) {
            for (int j = i * i; j <= n; j += i)
                striked[j] = true;
        }
    }
    for (size_t i = 0; i < striked.size(); ++i) {
        if (!striked[i])
            primes.push_back(i);
    }

    cout << "Here are the prime numbers up to " << n << ":\n"; 
    for (int prime: primes)
        cout << prime << '\n';
}
