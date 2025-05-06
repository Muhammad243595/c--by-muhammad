#include<iostream>
using namespace std;

class Book {
    string title;
    string author;
    long long isbn;
public:
    Book() {
        title = "NULL";
        author = "NULL";
        isbn = 0;
    }

    Book(string t, string a, long long i) {
        title = t;
        author = a;
        isbn = i;
    }

    void displayBookInfo() const {
        cout << "Title: " << title << endl
             << "Author: " << author << endl
             << "ISBN: " << isbn << endl << endl;
    }
};

class Library {
    string libraryName;
    Book* books;         // Pointer to dynamic array of books
    int capacity;        // Total allocated space
    int bookCount;       // Number of books currently stored
public:
    Library(string name, int initialCapacity = 2) {
        libraryName = name;
        capacity = initialCapacity;
        bookCount = 0;
        books = new Book[capacity];  // Dynamic memory allocation
    }

    ~Library() {
        delete[] books;  // Free dynamically allocated memory
    }

    void addBook(const Book &b) {
        if (bookCount == capacity) {
            expandLibrary();
        }
        books[bookCount] = b;
        bookCount++;
    }

    void displayAllBooks() const {
        cout << "Library: " << libraryName << endl << endl;
        for (int i = 0; i < bookCount; i++) {
            books[i].displayBookInfo();
        }
    }

private:
    void expandLibrary() {
        int newCapacity = capacity * 2;
        Book* temp = new Book[newCapacity];
        for (int i = 0; i < bookCount; i++) {
            temp[i] = books[i];  // Copy old books to new memory
        }
        delete[] books;         // Delete old memory
        books = temp;
        capacity = newCapacity;
    }
};

int main() {
    Library lib("City Library");

    Book b1("The Great Gatsby", "F. Scott Fitzgerald", 1234567890123);
    Book b2("1984", "George Orwell", 9876543210987);
    Book b3("Moby-Dick", "Herman Melville", 4567891234567);

    lib.addBook(b1);
    lib.addBook(b2);
    lib.addBook(b3);  // Triggers expansion when needed

    lib.displayAllBooks();

    return 0;
}
