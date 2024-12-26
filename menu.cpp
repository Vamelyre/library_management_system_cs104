

//?data file 

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <stdlib.h> 
using namespace std;

struct Book {
    string title;
    string author;
    int isbn;
    int publicationYear;
};

void displayRules();
void addBook(vector<Book>& books);
void removeBook(vector<Book>& books);
void searchBooks(const vector<Book>& books);
void displayBooks(const vector<Book>& books);
void displayStatistics(const vector<Book>& books);
void loadBooks(vector<Book>& books);
void saveBooks(const vector<Book>& books);

int main() {
    vector<Book> books;
    loadBooks(books);

    int choice;
    do {

    
        cout << "\n                   _______  " << endl;
        cout << "             ___===__  __===___" << endl;
        cout << "        ___===__===      ===__===____" << endl;
        cout << "   ___===__===________________===__===___" << endl;
        cout << "  ========================================" << endl;
        cout << "   |--------LIBRARY OF ALEXANDRIA-------|" << endl;
        cout << "   |___|----------------------------|___| " << endl;
        cout << "   @   @   [1] Browse the books     @   @" << endl;
        cout << "    |||    [2] Add a New Book        ||| " << endl;
        cout << "    |||    [3] Remove a book         ||| " << endl;
        cout << "    |||    [4] Search for a book     ||| "<< endl;
        cout << "    |||    [5] View the stats        ||| " << endl;
        cout << "    |||    [6] View the rules        ||| " << endl;
        cout << "   (___)   [7] Exit                 (___)" << endl;
        cout << "  ========================================" << endl;
        cout << "_|________________________________________|_" << endl;
        cout << "" << endl; 
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice) {
            case 1:
                displayBooks(books);
                break;
            case 2:
                addBook(books);
                
                break;
            case 3:
                removeBook(books);
               
                break;
            case 4:
                 searchBooks(books);
                break;
            case 5:
                displayStatistics(books);
                break;
            case 6:
                displayRules();
                break;
            case 7:
                cout << "Exiting...\n";
                saveBooks(books);
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

        if (choice != 7) {
            cout << "\nPress any key to return to the menu...";
        }
    } while (choice != 7);
    
    system("clear");
    return 0;
}

void displayRules() {
    cout << "\nRules for Adding Books:\n";
    cout << "* Title, Author, and ISBN (5 digits) must be unique.\n";
    cout << "* ISBN should only contain 5 digits.\n";
    cout << "* Books must have a valid publication year.\n";
}

void addBook(vector<Book>& books) {
    string title, author;
    int isbn, year;
    
    cout << "Enter Title: ";

    getline(cin, title);
    cout << "Enter Author: ";
    getline(cin, author);
    cout << "Enter 5-digit ISBN: ";
    cin >> isbn;
    cout << "Enter Publication Year: ";
    cin >> year;

    for (const auto& book : books) {
        if (book.title == title && book.author == author && book.isbn == isbn) {
            cout << "[Error]: Book already exists in the system.\n";
            return;
        }
    }

    if (year < 800 || year > 2024) {
        cout << "[Error]: Publication year must be between 800 AD and 2024 AD.\n";
        return;
    }

    if (to_string(isbn).length() != 5) {
        cout << "[Error]: ISBN must be exactly 5 digits.\n";
        return;
    }
    

    books.push_back({title, author, isbn, year});
    cout << "Book added successfully!\n";
}

void removeBook(vector<Book>& books) {
    int isbn;
    cout << "Enter ISBN of the book to remove: ";
    cin >> isbn;

    auto it = remove_if(books.begin(), books.end(), [isbn](const Book& book) {
        return book.isbn == isbn;
    });

    if (it != books.end()) {
        books.erase(it, books.end());
        cout << "Book removed successfully.\n";
    } else {
        cout << "Error: Book not found.\n";
    }
}
//---------------------------Search books
void searchBooks(const vector<Book>& books) {
    string search_word;
    cout << "Enter Title, Author, or ISBN to search: ";

    getline(cin, search_word);

    cout << setw(20) << "Title" << setw(20) << "Author" << setw(10) << "ISBN" << setw(15) << "Year" << "\n";
     for (const auto& book : books) {
         if (book.title == search_word || book.author == search_word || to_string(book.isbn) == search_word) {
             cout << setw(20) << book.title << setw(20) << book.author << setw(10) << book.isbn << setw(15) << book.publicationYear << "\n";
        }
    }
 }

void displayBooks(const vector<Book>& books) {
    vector<Book> sortedBooks = books;
    int option;
    cout << "\nSort by:\n[1]. Title (Alphabetical)\n[2]. Author (Alphabetical)\n[3]. Publication Year\n";
    cout << "Enter choice: ";
    cin >> option;

    switch (option) {
    case 1:
        sort(sortedBooks.begin(), sortedBooks.end(), [](const Book& a, const Book& b) { // -------------------this line 
            return a.title < b.title;
        });
        break;
    case 2:
        sort(sortedBooks.begin(), sortedBooks.end(), [](const Book& a, const Book& b) {
            return a.author < b.author;
        });
        break;
    case 3:
        sort(sortedBooks.begin(), sortedBooks.end(), [](const Book& a, const Book& b) {
            return a.publicationYear < b.publicationYear;
        });
        break;
    default:
        cout << "Invalid choice.\n";
        break;
}


    cout << setw(20) << "Title" << setw(20) << "Author" << setw(10) << "ISBN" << setw(15) << "Year" << "\n";
    for (const auto& book : sortedBooks) {
        cout << setw(20) << book.title << setw(20) << book.author << setw(10) << book.isbn << setw(15) << book.publicationYear << "\n";
    }
    
}




//-------------------stats
 void displayStatistics(const vector<Book>& books) {
     int totalBooks = books.size();
     int pre1950 = count_if(books.begin(), books.end(), [](const Book& book) {
         return book.publicationYear < 1950;
     });

     cout << "\nLibrary Statistics:\n";
     cout << "Total Books: " << totalBooks << "\n";
    cout << "Books Published Before 1950: " << pre1950 << "\n";
 }

void loadBooks(vector<Book>& books) {
    books = {
        {"The Iliad", "Homer", 12345, -762},
        {"Metamorphoses", "Ovid", 23456, 8},
        {"Histories", "Herodotus", 34567, -450}
    };
}

void saveBooks(const vector<Book>& books) {
    cout << "\nData saved.\n";
}
