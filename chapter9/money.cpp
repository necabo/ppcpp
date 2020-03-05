#include "../std_lib_facilities.h"

class Money {
    private:
        int long cents {0};
        string currency{"USD"};

        // arithmetic operations
        friend Money operator+(const Money&, const Money&);
        friend Money operator-(const Money&, const Money&);
        friend Money operator*(const Money&, double);
        friend Money operator*(double, const Money&);
        friend Money operator/(const Money&, double);
        friend double operator/(const Money&, const Money&);
        // in-/output
        friend ostream& operator<<(ostream&, const Money&);
        friend istream& operator>>(istream&, Money&);
    public:
        Money() {}
        Money(double);
        Money(double, string);
        Money(long int cents) : cents(cents) {}
        Money(long int cents, string currency) : cents(cents), currency(currency) {}
        class Division_By_Zero{};
        class Different_Currency{};
};

Money::Money(double amount) {
    cents = static_cast<long int>(amount * 100 + 0.5);
}

Money::Money(double amount, string currency) : currency(currency) {
    cents = static_cast<long int>(amount * 100 + 0.5);
}

Money operator+(const Money& lhs, const Money& rhs) {
    if (lhs.currency != rhs.currency) throw Money::Different_Currency{};
    return Money {lhs.cents + rhs.cents};
}

Money operator-(const Money& lhs, const Money& rhs) {
    if (lhs.currency != rhs.currency) throw Money::Different_Currency{};
    return Money {lhs.cents - rhs.cents};
}

Money operator*(const Money& lhs, double rhs) {
    return Money {lhs.cents * rhs};
}

Money operator*(double lhs, const Money& rhs) {
    return Money {lhs * rhs.cents};
}

Money operator/(const Money& lhs, double rhs) {
    if (rhs == 0.0) throw Money::Division_By_Zero{};
    return Money {lhs.cents / (rhs * 100)};
}

double operator/(const Money& lhs, const Money& rhs) {
    if (lhs.currency != rhs.currency) throw Money::Different_Currency{};
    if (rhs.cents == 0) throw Money::Division_By_Zero{};
    return static_cast<double>(lhs.cents) / static_cast<double>(rhs.cents);
}

ostream& operator<<(ostream& os, const Money& m) {
    return os << m.currency << m.cents / 100 << '.' << abs(m.cents % 100);
}

istream& operator>>(istream& is, Money& m) {
    string currency;
    char c;
    for (int i = 0; i < 3; ++i) {
        cin >> c;
        currency += c;
    }

    double amount;
    is >> amount;
    m = Money {amount, currency};
    return is;
}

int main() {
    Money m{123.45};
    Money m2{543.21};
    cout << m << " + " << m2 << " = " << m + m2 << endl;
    cout << m << " - " << m2 << " = " << m - m2 << endl;
    cout << m << " * " << 42 << " = " << m * 42 << endl;
    cout << 42 << " * " << m << " = " << 42 * m << endl;
    cout << m << " / " << m2 << " = " << m / m2 << endl;
    cout << m << " / " << 42 << " = " << m / 42 << endl;

    Money foo;
    cout << "Enter Money:";
    cin >> foo;
    cout << foo << endl;
}
