#include "library.h"

namespace Library {

Book::Book(string isbn, string title, string author, Date copyright_date, Genre genre)
    : isbn(isbn), title(title), author(author), copyright_date(copyright_date), genre(genre)
{
    if (!is_valid_isbn(isbn)) throw Book::InvalidISBN{};
}

bool is_valid_isbn(const string& isbn) {
    char current;
    int hyphens {0};

    for (size_t i = 0; i < isbn.size(); ++i) {
        current = isbn[i];
        if (hyphens < 3) {
            if (current == '-') ++hyphens;
            else if (!isdigit(current)) return false;
        }
        else return i == isbn.size() - 1 && (isalpha(current) || isdigit(current));
    }
    return false;
}

bool operator==(const Book& a , const Book& b) {
    return a.get_isbn() == b.get_isbn();
}

bool operator!=(const Book& a, const Book& b) {
    return !(a == b);
}

ostream& operator<<(ostream& os, const Book& book) {
    os << book.get_title() << endl
       << book.get_author() << endl
       << book.get_isbn();
    return os;
}

bool owes_fees(const Patron& p) { return p.get_fees() != 0.0; }
bool operator==(const Patron& a, const Patron& b) {
    return a.get_card_number() == b.get_card_number();
}
bool operator!=(const Patron& a, const Patron& b) {
    return !(a == b);
}

void Library::add_book(Book book) { books.push_back(book); }
void Library::add_patron(Patron patron) { patrons.push_back(patron); }

bool is_patron(const Library& l, const Patron& p) {
    for (const Patron& patron: l.patrons) {
        if (patron == p) return true;
    }
    return false;
}

bool is_in_library(const Library& l, const Book& b) {
    for (const Book& book: l.books) {
        if (book == b) return true;
    }
    return false;
}

void Library::check_out(Patron& p, Book& b) {
    if (!is_patron(*this, p)) throw CheckoutError{};
    if (!is_in_library(*this, b)) throw CheckoutError{};
    if (owes_fees(p)) throw CheckoutError{};

    for (Book book: books) {
        if (book == b) {
            transactions.push_back(Transaction{b, p, Date{}});
        }
        b.check_out();
        p.set_fees(p.get_fees() + 42.0);
    }
    throw CheckoutError{}; // unreachable!
}

vector<string> Library::owe_fees() {
    vector<string> names;

    for (const Patron& p: patrons) {
        if (owes_fees(p)) names.push_back(p.get_name());
    }
    return names;
}

}
