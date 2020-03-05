#include "chrono.h"
#include <vector>

using namespace Chrono;

namespace Library {

enum class Genre {
    fiction, nonfiction, periodical, biography, children
};

class Book {
    private:
        string isbn;
        string title;
        string author;
        Date copyright_date;
        Genre genre;
        bool checked_out;
    public:
        string get_isbn() const { return isbn; };
        string get_title() const { return title; };
        string get_author() const { return author; };
        Date get_copyright_date() const { return copyright_date; };
        bool is_checked_out() const { return checked_out; };
        void check_out() { checked_out = true; };
        void check_in() { checked_out = false; };
        class InvalidISBN{};
        Book(string isbn, string title, string author, Date copyright_date, Genre genre);
};

bool operator==(const Book&, const Book&);
bool operator!=(const Book&, const Book&);
ostream& operator<<(ostream&, const Book&);

bool is_valid_isbn(const string&);

class Patron {
    private:
        string name;
        int card_number;
        double fees {0.0};
    public:
        string get_name() const { return name; };
        int get_card_number() const { return card_number; };
        double get_fees() const { return fees; };
        void set_fees(double fees) { fees = fees; };
        Patron(string name, int card_number) : name(name), card_number(card_number) {};
};

bool owes_fees(const Patron&);
bool operator==(const Patron&, const Patron&);
bool operator!=(const Patron&, const Patron&);

class Library {
    private:
        vector<Book> books;
        vector<Patron> patrons;

        struct Transaction {
            Book book;
            Patron patron;
            Date date;
        };
        vector<Transaction> transactions;
        friend bool is_patron(const Library&, const Patron&);
        friend bool is_in_library(const Library&, const Book&);
    public:
        void add_book(Book);
        void add_patron(Patron);
        void check_out(Patron&, Book&);
        vector<string> owe_fees();
        class CheckoutError{};
};

}
