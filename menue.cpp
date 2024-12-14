#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype> 

using namespace std;

struct book {
    string title;
    string author;
    int year;
    int isbn; 
};

void add_book(vector<book>& library);

// lowercase for checking
string toLowerCase(const string& str) {
    string lowercase = str;
    transform(lowercase.begin(), lowercase.end(), lowercase.begin(), ::tolower);
    return lowercase;
}

int main() {
    vector<book> library = {
        {"The Iliad", "Homer", -850, 55242},
        {"The Odyssey", "Homer", -800, 23444},
        {"Histories", "Herodotus", -440, 34567}
    };

    int choice;

    do {
        cout << "                   ____  " << endl;
        cout << "             ___===    ===___" << endl;
        cout << "        ___===__===      ===__===____" << endl;
        cout << "   ___===__===________________===__===___" << endl;
        cout << "  ========================================" << endl;
        cout << "   |------THE LIBRARY OF ALEXANDRIA-----|" << endl;
        cout << "   |___|----------------------------|___| " << endl;
        cout << "   @   @   [1] Browse the books     @   @" << endl;
        cout << "    |||    [2] Add a New Book        ||| " << endl;
        cout << "    |||    [3] Remove a book         ||| " << endl;
        cout << "    |||    [4] Search for a book     ||| "<< endl;
        cout << "    |||    [5] View the stats        ||| " << endl;
        cout << "   (___)   [6] Exit                 (___)" << endl;
        cout << "  ========================================" << endl;
        cout << "_|________________________________________|_" << endl;
        cout << "" << endl; 
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // browse_books(library);
                break;
            case 2:
                add_book(library);
                break;
            case 3:
                // remove_book(library);
                break;
            case 4:
                // search_books(library);
                break;
            case 5:
                // display_stats(library);
                break;
            case 6:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}

void add_book(vector<book>& library) {
    while (true) {
        book new_book;
        cout << "Enter book details (Title, Author, Year, ISBN) separated by commas: ";
        cout << "* Type \"back\" to return to the menu" << endl;
        
        string input;
        cin.ignore();  // CLear the buffer before using getline
        getline(cin, input);  // eead title

        if (input == "back" || input == "Back") return;
        new_book.title = input;

        cout << "Enter author: ";
        getline(cin, new_book.author);  

        cout << "Enter year: ";
        cin >> new_book.year;

        cout << "Enter ISBN: ";
        cin >> new_book.isbn;
        cin.ignore();  

        if (new_book.year == -1) {
            new_book.year = 0; // unknown year
        }

        // duplicate check
        for (const auto& existing_book : library) {
            if (toLowerCase(existing_book.title) == toLowerCase(new_book.title)) {
                cout << "Error: A book with this title already exists.\n";
                return;
            }
            if (existing_book.isbn == new_book.isbn) {
                cout << "Error: A book with this ISBN already exists.\n";
                return;
            }
        }

        library.push_back(new_book); // add to library
        cout << "Book added successfully!\n";

        return;
    }
}
