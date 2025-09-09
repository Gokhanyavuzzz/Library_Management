# Library Management System

This is a simple library management system that allows the user to perform various actions such as adding, borrowing, selling, and removing books from a library. The system also keeps track of the number of available books and provides methods to update stock levels.

## Features

- **Add a Book**: Adds a new book to the library if there is enough space.
- **Remove a Book**: Removes a book from the library if it exists.
- **Borrow a Book**: Allows a user to borrow a book, decreasing the available stock.
- **Sell a Book**: Allows a user to purchase a book, decreasing the available stock.
- **Update Stock**: Allows the library to increase or decrease the stock of a specific book.
- **Display Book Info**: Displays detailed information about a book, including the title, author, and number of available copies.

## Classes

### `Book`
- **Attributes**:
  - `nameOfBook`: The name of the book.
  - `author`: The author of the book.
  - `borrowerName`: The name of the person borrowing the book.
  - `buyerName`: The name of the person buying the book.
  - `numberOfPages`: The total number of pages in the book.
  - `availableBooks`: The number of available copies of the book in the library.
  - `capacity`: The maximum capacity of copies for a particular book.

- **Methods**:
  - `borrowTheBook()`: Borrows the book, reducing its available stock.
  - `sellTheBook()`: Sells the book, reducing its available stock.
  - `removeBook()`: Removes the book from the library.
  - `setAvailableBooks()`: Updates the number of available copies of a book.
  - `increaseAvailableBooks()`: Increases the available copies by one.
  - `decreaseAvailableBooks()`: Decreases the available copies by one.
  - `printInfoOfBook()`: Prints the information of the book.

### `Library`
- **Attributes**:
  - `books`: A vector of `Book` objects representing the library's collection.
  
- **Methods**:
  - `addBook()`: Adds a book to the library collection.
  - `removeBook()`: Removes a book from the library collection.
  - `borrowTheBook()`: Allows borrowing a book from the library.
  - `sellTheBook()`: Allows purchasing a book from the library.
  - `printLibrary()`: Prints the details of all books in the library.
  - `indexOfBooks()`: Returns the index of a specific book in the library collection.
  - `isIn()`: Checks if a book is present in the library.
  - `setOfBooks()`: Updates the stock of a book (either increases or decreases).

## Example Usage

### Adding Books to the Library
```cpp
Library library;
Book book1("Life of Pi", "Yann Martel", 100);
Book book2("The Great Gatsby", "F. Scott Fitzgerald", 180);

library.addBook(book1);
library.addBook(book2);
