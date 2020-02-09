#include "../std_lib_facilities.h"

struct Stats {
    double smallest;
    double largest;
    double mean;
    double median;

    Stats(double sma, double lar, double mea, double med)
    :smallest{sma}, largest{lar}, mean{mea}, median{med} {}
};

Stats do_it_all(vector<double> vec) {
    sort(vec.begin(), vec.end());
    size_t size = vec.size();

    double sum = 0;
    for (double v: vec) sum += v;
    double mean = sum / size;

    double median;
    if (size % 2 == 0) median = (vec[size / 2 - 1] + vec[size / 2]) / 2;
    else median = vec[size / 2];

    return Stats{vec[0], vec[size - 1], mean, median};
}

int main() {
    vector<double> vec {3.3, 1.1, 6.6, 2.2, 4.4, 9.9, 8.8, 5.5, 7.7, 10.10};
    Stats stats = do_it_all(vec);
    cout << "Smallest: " << stats.smallest << endl
         << "Largest: " << stats.largest << endl
         << "Mean: " << stats.mean << endl
         << "Median: " << stats.median << endl;
}
