
/*
    calculator08buggy.cpp

    Helpful comments removed.

    We have inserted 3 bugs that the compiler will catch and 3 that it won't.
*/

#include "../std_lib_facilities.h"

struct Token {
    char kind;
    double value;
    string name;
    Token(char ch) :kind(ch), value(0) {}
    Token(char ch, double val) :kind(ch), value(val) {}
    Token(char ch, string s) :kind(ch), name(s) {}
};

class Token_stream {
    bool full;
    Token buffer;
public:
    Token_stream() :full(0), buffer(0) { }

    Token get();
    void unget(Token t) { buffer=t; full=true; }

    void ignore(char);
};

const char let = 'L';
const char quit = 'Q';
const char print = ';';
const char number = '8';
const char name = 'a';
const char square_root = 's';
const char power = 'p';
const char comma = ',';
const char help = 'h';

Token Token_stream::get()
{
    if (full) { full=false; return buffer; }
    char ch;
    cin.get(ch);
    if (ch == '\n') return Token(print);
    else cin.unget();

    cin >> ch;
    switch (ch) {
    case '(':
    case ')':
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
    case ';':
    case '=':
    case comma:
        return Token(ch);
    case '.':
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    {    cin.unget();
        double val;
        cin >> val;
        return Token(number,val);
    }
    case '#':
        return Token(let);
    case 'h': case 'H':
        return Token(help);
    case 'q':
        return Token(quit);
    default:
        if (isalpha(ch)) {
            string s;
            s += ch;
            while(cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_')) s+=ch;
            cin.unget();
            if (s == "sqrt") return Token(square_root);
            if (s == "pow") return Token(power);
            return Token(name,s);
        }
        error("Bad token");
    }
}

void Token_stream::ignore(char c)
{
    if (full && c==buffer.kind) {
        full = false;
        return;
    }
    full = false;

    char ch;
    while (cin>>ch)
        if (ch==c) return;
}

struct Variable {
    string name;
    double value;
    bool is_const;
    Variable(string n, double v) :name(n), value(v) {}
    Variable(string n, double v, bool b) :name(n), value(v), is_const(b) {}
};

class Symbol_table {
    vector<Variable> var_table;
    public:
        double get(string s);
        void set(string s, double d);
        double declare(string var, double val, bool is_const);
    private:
        bool is_declared(string s);
};

double Symbol_table::get(string s) {
    for (Variable& v: var_table)
        if (v.name == s) return v.value;
    error("get: undefined name ", s);
}

void Symbol_table::set(string s, double d) {
    for (Variable& v: var_table)
        if (v.name == s) {
            if (!v.is_const) v.value = d;
            return;
        }
    error("set: undefined name ", s);
}

bool Symbol_table::is_declared(string s) {
    for (Variable& v: var_table)
        if (v.name == s) return true;
    return false;
}

double Symbol_table::declare(string var, double val, bool is_const) {
    if (is_declared(var)) error(var, " declared twice");
    var_table.push_back(Variable(var, val, is_const));
    return val;
}

Symbol_table symbol_table;

Token_stream ts;

double expression();

double primary()
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':
    {
        double d = expression();
        t = ts.get();
        if (t.kind != ')') error("')' expected");
        return d;
    }
    case '-':
        return - primary();
    case number:
        return t.value;
    case name: {
        string var = t.name;
        t = ts.get();
        if (t.kind == '=') {
            double val = expression();
            symbol_table.set(var, val);
            return val;
        }
        ts.unget(t);
        return symbol_table.get(var);
    }
    default:
        error("primary expected");
    }
}

double term()
{
    double left = primary();
    while(true) {
        Token t = ts.get();
        switch(t.kind) {
        case '*':
            left *= primary();
            break;
        case '/':
        {    double d = primary();
            if (d == 0) error("divide by zero");
            left /= d;
            break;
        }
        default:
            ts.unget(t);
            return left;
        }
    }
}

double expression()
{
    double left = term();
    while(true) {
        Token t = ts.get();
        switch(t.kind) {
        case '+':
            left += term();
            break;
        case '-':
            left -= term();
            break;
        default:
            ts.unget(t);
            return left;
        }
    }
}

double pow2() {
    Token t = ts.get();
    if (t.kind != '(') error("( missing in function call of pow");
    double left = expression();
    t = ts.get();
    if (t.kind != comma) error("invalid arguments");
    double right = expression();
    t = ts.get();
    if (t.kind != ')') error("')' expected");
    return pow(left, narrow_cast<int>(right));
}

double sqrt2() {
    double d = expression();
    if (d < 0) error("are you for real?");
    return sqrt(d);
}

double declaration()
{
    Token t = ts.get();
    if (t.kind != 'a') error ("name expected in declaration");
    string name = t.name;
    Token t2 = ts.get();
    if (t2.kind != '=') error("= missing in declaration of " ,name);
    double d = expression();
    symbol_table.declare(name, d, false);
    return d;
}

double statement() {
    Token t = ts.get();
    switch(t.kind) {
    case let:
        return declaration();
    case square_root: {
        double d = expression();
        if (d < 0) error("are you for real?");
        return sqrt(d);
    }
    case power:
        return pow2();
    default:
        ts.unget(t);
        return expression();
    }
}

void clean_up_mess() {
    ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";

double calculate(Token t) {
    switch (t.kind) {
        case let:
            return declaration();
        case square_root:
            return sqrt2();
        case power:
            return pow2();
        default:
            ts.unget(t);
            return expression();
    }
}

void handle_input() {
    while(true) try {
        cout << prompt;
        Token t = ts.get();
        while (t.kind == print) t=ts.get();
        if (t.kind == quit) return;
        ts.unget(t);

        t = ts.get();
        switch (t.kind) {
            case help:
                cout << "HELP:" << endl
                     << "Supported operators:" << endl
                     << "- +" << endl
                     << "- -" << endl
                     << "- *" << endl
                     << "- /" << endl
                     << "- %" << endl
                     << "- (" << endl
                     << "- )" << endl << endl
                     << "Supported functions:" << endl
                     << "- pow(double x, int y)" << endl
                     << "- sqrt(double x)" << endl << endl
                     << "Additional features:" << endl
                     << "- variables:" << endl
                     << "   - declaration: # <name> = <expression>" << endl
                     << "   - (re)assignment: <name> = <expression>" << endl;
                break;
            default:
                cout << result << calculate(t) << endl;
                break;
        }
    }
    catch(runtime_error& e) {
        cerr << e.what() << endl;
        clean_up_mess();
    }
}

int main() {
    try {
        symbol_table.declare("k", 1000, true);

        handle_input();
        return 0;
    }
    catch (exception& e) {
        cerr << "exception: " << e.what() << endl;
        char c;
        while (cin >>c&& c!=';') ;
        return 1;
    }
    catch (...) {
        cerr << "exception\n";
        char c;
        while (cin>>c && c!=';');
        return 2;
    }
}
