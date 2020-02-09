#include "../std_lib_facilities.h"

struct Stats {
    vector<int> char_count;
    string longest;
    string shortest;
    string first;
    string last;
    Stats(vector<int> cha, string lon, string sho, string fir, string las)
    :char_count{cha}, longest{lon}, shortest{sho}, first{fir}, last{las} {}
};

Stats do_it_all(vector<string> words) {
    sort(words.begin(), words.end());
    string shortest = words[0];
    string longest = words[0];
    vector<int> char_count {narrow_cast<int>(words[0].length())};
    for (size_t i = 1; i < words.size(); ++i) {
        if (words[i].length() < shortest.length()) shortest = words[i];
        else if (words[i].length() > longest.length()) longest = words[i];
        char_count.push_back(words[i].length());
    }

    return Stats{char_count, longest, shortest, words[0], words[words.size() - 1]};
}

int main() {
    vector<string> words {"foo", "bar", "baz", "qux", "quux"};
    Stats stats = do_it_all(words);
    cout << "Char count:";
    for (int c: stats.char_count) cout << ' ' << c;
    cout << endl
         << "Longest: " << stats.longest << endl
         << "Shortest: " << stats.shortest << endl
         << "First: " << stats.first << endl
         << "Last: " << stats.last << endl;
}
