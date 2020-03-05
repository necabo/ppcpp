#include "../std_lib_facilities.h"

class Rational {
    private:
        int numerator;
        int denominator;
        // arithmetic operations
        friend Rational operator+(const Rational&, const Rational&);
        friend Rational operator-(const Rational&, const Rational&);
        friend Rational operator*(const Rational&, const Rational&);
        friend Rational operator/(const Rational&, const Rational&);
        // equality operations
        friend bool operator==(const Rational&, const Rational&);
        friend bool operator!=(const Rational&, const Rational&);
        friend void reduce(Rational&);
        friend void normalize(Rational&);
        friend double rational_to_double(const Rational&);
    public:
        Rational(int numerator, int denominator);
        class Invalid{};
};

Rational::Rational(int numerator, int denominator)
    : numerator(numerator), denominator(denominator)
{
    if (denominator == 0) throw Invalid {};
    normalize(*this);
    reduce(*this);
}

int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    int tmp;

    while (b != 0) {
        tmp = a;
        a = b;
        b = tmp % b;
    }
    return a;
}

void reduce(Rational& r) {
    int divisor {gcd(r.numerator, r.denominator)};
    r.numerator /= divisor;
    r.denominator /= divisor;
}

void normalize(Rational& r) {
    if (r.denominator < 0) {
        r.denominator = -r.denominator;
        r.numerator = -r.numerator;
    }
}

double rational_to_double(const Rational& r) {
    return static_cast<double>(r.numerator) / static_cast<double>(r.denominator);
}

Rational operator+(const Rational& a, const Rational& b) {
    int numerator {a.numerator * b.denominator + b.numerator * a.denominator};
    int denominator {a.denominator * b.denominator};
    return Rational {numerator, denominator};
}

Rational operator-(const Rational& a, const Rational& b) {
    int numerator {a.numerator * b.denominator - b.numerator * a.denominator};
    int denominator {a.denominator * b.denominator};
    return Rational {numerator, denominator};
}

Rational operator*(const Rational& a, const Rational& b) {
    int numerator {a.numerator * b.numerator};
    int denominator {a.denominator * b.denominator};
    return Rational {numerator, denominator};
}

Rational operator/(const Rational& a, const Rational& b) {
    int numerator {a.numerator * b.denominator};
    int denominator {a.denominator * b.numerator};
    return Rational {numerator, denominator};
}

bool operator==(const Rational& a, const Rational& b) {
    return a.numerator == b.numerator && a.denominator == b.denominator;
}

bool operator!=(const Rational& a, const Rational& b) {
    return !(a == b);
}

int main() {
    Rational r1 {1, 4};
    Rational r2 {1, 2};
    cout << rational_to_double(r1 + r2) << endl;
    cout << rational_to_double(r1 - r2) << endl;
    cout << rational_to_double(r1 * r2) << endl;
    cout << rational_to_double(r1 / r2) << endl;
}
