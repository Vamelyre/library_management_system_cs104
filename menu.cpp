#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
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
            cout << "\n";
            clearConsole(); 
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
    string title, author, description;
    int isbn, year;

    cout << "Enter the title: ";
    cin.ignore(); 
    getline(cin, title);
    
    cout << "Enter the author: ";
    getline(cin, author);
    
    cout << "Enter a 5-digit ISBN: ";
    cin >> isbn;
    
    if (isbn < 10000 || isbn > 99999) {
        cout << "[Error]: ISBN must be exactly 5 digits.\n";
        return;
    }
    cout << "Enter the publication year: ";
    cin >> year;
    
     if (year < 0 || year > 2024) {
        cout << "[Error]: Publication year must be between 800 AD and 2024 AD.\n";
        return;
    }
    
    cin.ignore(); 
    cout << "Enter the description (or press Enter to skip): ";
    getline(cin, description);

    for (const auto& book : books) {
        if (book.title == title && book.author == author && book.isbn == isbn) {
            cout << "[Error]: Book already exists in the system.\n";
            return;
        }
    }

    

    books.push_back({title, author, isbn, year, description});
    cout << "Book added successfully!\n";
}

void removeBook(vector<Book>& books) {
    int isbn;
    cout << "Enter ISBN of the book to remove: ";
    cin >> isbn;  
    
    bool found = false;  
    
    for (int i = 0; i < books.size(); i++) {
        if (books[i].isbn == isbn) { 
            books.erase(books.begin() + i);  
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
    
    bool found = false;

    for (size_t i = 0; i < books.size(); ++i) {
        const Book& book = books[i];
        
        if (book.title == search_word || book.author == search_word) {
            cout << setw(5) << "[" << i + 1  << "]"
            << setw(25) << book.title 
            << setw(25) << book.author 
            << setw(10) << book.isbn 
            << setw(15) << book.publicationYear 
            << "\n";
            found = true;
        }
    }

    if (!found) {
        cout << "No books found matching the search word.\n";
        return;
    }

    int selectedIndex;
    cout << "Enter the index of the book to view details, or 0 to skip: ";
    cin >> selectedIndex;

    if (selectedIndex > 0 && selectedIndex <= books.size()) {
        viewBookDetails(books, selectedIndex - 1); 
    } else {
        cout << "No book selected, or invalid index.\n";
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
    cout << "\nLibrary Statistics:\n";
    cout << "Total Books: " << totalBooks << "\n";
    cout << "Books Published Before 1950: " << pre1950 << "\n";
}

void clearConsole() {
   
    cout << "Press Enter to clear the console.";
    cin.get();
    
    system("clear");

    cout << "Console cleared.\n";
}
