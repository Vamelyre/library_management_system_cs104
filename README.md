# Library Management System (Library of Alexandria)

## Overview
This program simulates a basic library management system called the "Library of Alexandria." Users can interact with a collection of books through a menu-driven interface. The system supports various functionalities such as browsing books, adding new books, removing books, searching for books, viewing library statistics, and viewing rules for adding books.

## Features
- **Browse Books**: View a list of all books in the library.
- **Add a New Book**: Allows users to add a new book to the library with a unique title, author, ISBN, publication year, and description.
- **Remove a Book**: Users can remove a book from the library by providing its ISBN.
- **Search for Books**: Users can search for books by title, author, or ISBN and view book details.
- **View Library Stats**: Displays statistics such as the total number of books and how many were published before 1950.
- **View Rules**: Provides the rules for adding a new book to the library (e.g., ISBN format, valid years).
- **Console Clear**: Clears the console window (platform-dependent).

## Prerequisites
- A C++ compiler (e.g., GCC or MSVC)
- A Unix-based or Windows-based environment for running the program.

## Files
- `menu.cpp`: The main source code for the library management system.

## How to Run

1. **Compile the Code**:
   - Use a C++ compiler (e.g., `g++` or `clang++`) to compile the `main.cpp` file:
   ```bash
   g++ main.cpp -o library_system
