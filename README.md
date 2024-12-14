# Library of Alexandria - C++ Library Management System

This is a simple terminal-based Library Management System written in C++, where users can add, remove, browse, and search for books, as well as view their stats. The system uses C++ structures and vectors to manage book data.

## Features

- **Browse Books**: View all books in the library, including some preadded books.
- **Add a Book**: Add a new book with details such as title, author, publication year, and ISBN.
- **Remove a Book**: Remove books from the library.
- **Search for a Book**: Search for books by title or author.
- **View Stats**: Displays statistics about the library, such as total books or the most added author.

## Data Structures Used

- **Book Structure**: Each book is represented by a structure containing:
  - `title`: The title of the book.
  - `author`: The author of the book.
  - `year`: The publication year of the book.
  - `isbn`: The ISBN number of the book.

- **Vector**: A vector of `book` structures is used to store and manage the books in the library.

## Installation

To run this program on your local machine:

1. You must have a C++ compiler installed (e.g., GCC or Clang).
2. Clone this repository to your local machine:

   ```bash
   git clone https://github.com/Vamelyre/library_management_system_cs104.git
