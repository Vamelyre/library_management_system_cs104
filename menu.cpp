#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cstdlib>
#include <limits>
using namespace std;

struct Book {
    string title;
    string author;
    int isbn;
    int publicationYear;
    string description;
};

void displayRules();
void addBook(vector<Book>& books);
void removeBook(vector<Book>& books);
void searchBooks(const vector<Book>& books);
void displayBooks(const vector<Book>& books);
void displayStatistics(const vector<Book>& books);
void loadBooks(vector<Book>& books);

void clearConsole();
void viewBookDetails(const vector<Book>& books, int index);

int main() {
    vector<Book> books;
    loadBooks(books);

    int choice;
    do {
        cout << "\n                   ______  " << endl;
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
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

        if (choice != 7) {
            clearConsole(); 
        }
    } while (choice != 7);

    return 0;  // This closes the main function properly.
}

void displayRules() {
    cout << "\nRules for Adding Books:\n";
    cout << "* Title, Author, and ISBN (5 digits) must be unique.\n";
    cout << "* ISBN should only contain 5 digits.\n";
    cout << "* Books must have a valid publication year.\n";
}

void addBook(vector<Book>& books) {
    string title, author, description;
    int isbn, year;

    cout << "Enter the title: ";
    cin.ignore(); 
    getline(cin, title);
    cout << "Enter the author: ";
    getline(cin, author);
    cout << "Enter a 5-digit ISBN: ";
    cin >> isbn;
    cout << "Enter the publication year: ";
    cin >> year;
    
    cin.ignore(); 
    cout << "Enter the description (or press Enter to skip): ";
    getline(cin, description);

    for (const auto& book : books) {
        if (book.title == title && book.author == author && book.isbn == isbn) {
            cout << "[Error]: Book already exists in the system.\n";
            return;
        }
    }

    if (year < 0 || year > 2024) {
        cout << "[Error]: Publication year must be between 800 AD and 2024 AD.\n";
        return;
    }

    if (to_string(isbn).length() != 5) {
        cout << "[Error]: ISBN must be exactly 5 digits.\n";
        return;
    }

    books.push_back({title, author, isbn, year, description});
    cout << "Book added successfully!\n";
}

void removeBook(vector<Book>& books) {
    int isbn;
    cout << "Enter ISBN of the book to remove: ";
    cin >> isbn;

    bool found = false;
    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->isbn == isbn) {
            books.erase(it);
            found = true;
            cout << "Book removed successfully.\n";
            break;
        }
    }

    if (!found) {
        cout << "Error: Book not found.\n";
    }
}

void viewBookDetails(const vector<Book>& books, int index) {
    const Book& book = books[index];
    cout << "\nDetails for: " << book.title << endl;
    cout << "Author: " << book.author << endl;
    cout << "ISBN: " << book.isbn << endl;
    cout << "Publication Year: " << book.publicationYear << endl;
    cout << "Description: " << book.description << endl;
}


void searchBooks(const vector<Book>& books) {
    string search_word;
    cout << "Enter Title, Author, or ISBN to search: ";
    cin.ignore();  
    getline(cin, search_word);

    cout << setw(25) << "Title" << setw(25) << "Author" << setw(10) << "ISBN" << setw(25) << "Year" << "\n";
    for (const auto& book : books) {
        if (book.title == search_word || book.author == search_word // or the isbn code but the search word is a string and isbn isn't 
        ) { 
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

    if (option == 1) {
        for (int i = 0; i < sortedBooks.size(); ++i) {
            for (int j = i + 1; j < sortedBooks.size(); ++j) {
                if (sortedBooks[i].title > sortedBooks[j].title) {
                    swap(sortedBooks[i], sortedBooks[j]);
                }
            }
        }
    } else if (option == 2) {
        for (int i = 0; i < sortedBooks.size(); ++i) {
            for (int j = i + 1; j < sortedBooks.size(); ++j) {
                if (sortedBooks[i].author > sortedBooks[j].author) {
                    swap(sortedBooks[i], sortedBooks[j]);
                }
            }
        }
    } else if (option == 3) {
        for (int i = 0; i < sortedBooks.size(); ++i) {
            for (int j = i + 1; j < sortedBooks.size(); ++j) {
                if (sortedBooks[i].publicationYear > sortedBooks[j].publicationYear) {
                    swap(sortedBooks[i], sortedBooks[j]);
                }
            }
        }
    }

    cout << setw(5) << "Index" << setw(20) << "Title" << setw(20) << "Author" << setw(10) << "ISBN" << setw(15) << "Year" << "\n";
    cout << "---------------------------------------------------------------------" << endl;
    for (size_t i = 0; i < sortedBooks.size(); ++i) {
        cout << setw(5) << "[" << i + 1 << "]" << setw(20) << sortedBooks[i].title 
        << setw(20) << sortedBooks[i].author 
        << setw(10) << sortedBooks[i].isbn 
        << setw(15) << sortedBooks[i].publicationYear << "\n";
    }

    int selectedIndex;
    cout << "Enter the index of the book to view details, or 0 to skip: ";
    cin >> selectedIndex;

    if (selectedIndex > 0 && selectedIndex <= sortedBooks.size()) {
        viewBookDetails(sortedBooks, selectedIndex - 1); 
    }
}


void loadBooks(vector<Book>& books) {
    books = {
        {"The Iliad", "Homer", 12345, 762},
        {"Metamorphoses", "Ovid", 23456, 8},
        {"Histories", "Herodotus", 34567, 450}
    };
}

void displayStatistics(const vector<Book>& books) {
    int totalBooks = 0;
    int pre1950 = 0;
    for (const auto& book : books) {
        totalBooks++;
        if (book.publicationYear < 1950) {
            pre1950++;
        }
    }
}

void clearConsole() {
   
    
    cout << "Press Enter to clear the console.";
    cin.get();
    
    system("clear");

    cout << "Console cleared.\n";
}
