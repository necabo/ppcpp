#include "../std_lib_facilities.h"

class Token {
    public:
        char kind;
        double value;
};

class Token_stream {
    public:
        Token get();
        void putback(Token t);
    private:
        bool full {false};
        Token buffer;
};

Token Token_stream::get() {
    if (full) {
        full = false;
        return buffer;
    }
    char ch;
    cin >> ch;
    switch (ch) {
        case ';':
        case 'q':
        case '(': case ')': case '{': case '}': case '+': case '-': case '*': case '/': case '!':
            return Token{ch};
        case '.':
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9': {
            cin.putback(ch);
            double val;
            cin >> val;
            return Token{'8', val};
        }
        default:
            error("Bad token");
    }
}

void Token_stream::putback(Token t) {
    if (full)
        error("putback() into a full buffer");
    buffer = t;
    full = true;
}

Token_stream ts;  // FIXME: global variables are pretty meh!
double expression();

double primary() {
    Token t = ts.get();
    switch (t.kind) {
        case '(': {
            double d = expression();
            t = ts.get();
            if (t.kind != ')')
                error("')' expected");
            return d;
        }
        case '{': {
            double d = expression();
            t = ts.get();
            if (t.kind != '}')
                error("'}' expected");
            return d;
        }
        case '8':
            return t.value;
        default:
            error("primary expected");
    }
}

double factorial() {
    double left = primary();
    Token t = ts.get();
    while (true) {
        switch (t.kind) {
            case '!': {
                int leftInt = left;
                int res = 1;
                for (; leftInt > 1; --leftInt) {
                    res *= leftInt;
                }
                left = res;
                t = ts.get();
                break;
            }
            default:
                ts.putback(t);
                return left;
        }
    }
}

double term() {
    double left = factorial();
    Token t = ts.get();
    while (true) {
        switch (t.kind) {
            case '*':
                left *= factorial();
                t = ts.get();
                break;
            case '/': {
                double d = factorial();
                if (d == 0)
                    error("divide by zero");
                left /= d;
                t = ts.get();
                break;
            }
            default:
                ts.putback(t);
                return left;
        }
    }
}

double expression() {
    double left = term();
    Token t = ts.get();
    while (true) {
        switch (t.kind) {
            case '+':
                left += term();
                t = ts.get();
                break;
            case '-':
                left -= term();
                t = ts.get();
                break;
            default:
                ts.putback(t);
                return left;
        }
    }
}

int main() {
    try {
        double val = 0;
        while (cin) {
            Token t = ts.get();
            if (t.kind == 'q')
                break;
            if (t.kind == ';')
                cout << "=" << val << '\n';
            else
                ts.putback(t);
            val = expression();
        }
    } catch (exception& e) {
        cerr << e.what() << '\n';
        return 1;
    } catch (...) {
        cerr << "exception \n";
        return 2;
    }
}
