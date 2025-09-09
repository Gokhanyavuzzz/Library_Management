#include <iostream>
#include <vector>
using namespace std;


class Book {
private:
	string nameOfBook;
	string author;
	string borrowerName;
	string buyerName;
	int numberOfPages;
	int availableBooks = 1;
	int capacity = 50;

public:
	Book(string nameOfBook, string author, int numberOfPages) {
		this->nameOfBook = nameOfBook;
		this->author = author;
		this->numberOfPages = numberOfPages;
	}
	class Library;
	void borrowTheBook();
	void sellTheBook();
	void removeBook(Book& book1, vector <Book> books);

	string getName() {
		return nameOfBook;
	}
	string getAuthor() {
		return author;
	}
	string getBorrowerName() {
		return borrowerName;
	}
	void setBorrowerName(string borrowerName) {
		this->borrowerName = borrowerName;
	}

	string getBuyerName() {
		return buyerName;
	}
	void setBuyerName(string buyerName) {
		this->buyerName = buyerName;
	}

	int getNumberOfPages() const {
		return numberOfPages;
	}
	int getAvailableBooks() {
		return availableBooks;
	}
	void setAvailableBooks(Book& book1, vector<Book>& books, int i, int index) {
		int num = book1.availableBooks;
		if (num + i < 0) {
			cout << "There are not enough books in the library." << endl;
		}
		else {
			books[index].availableBooks += i;
			cout << "Stock updated!" << endl;
		}
	}
	void increaseAvailableBooks(Book& book1) const {
		book1.availableBooks++;
	}
	void decreaseAvailableBooks(Book& book1) const {
		book1.availableBooks--;
	}
	int getCapacity() const {
		return capacity;
	}
	void printInfoOfBook(Book& book1) {
		cout << "Name of book: " << book1.getName() << endl;
		cout << "Name of author: " << book1.getAuthor() << endl;
		cout << "Number of pages: " << book1.getNumberOfPages() << endl;
		cout << "How many books the library have? :" << book1.getAvailableBooks() << endl;
	}
};
class Library {
private:
	vector <Book> books;
public:
	void addBook(Book& book1) {
		if (book1.getAvailableBooks() == book1.getCapacity()) {
			cout << "Library full!" << endl;
			return;
		}
		int index = indexOfBooks(book1, books);
		if (index == -1) {
			books.push_back(book1);
			cout << book1.getName() << " added to the library." << endl;
			return;
		}
		books[index].increaseAvailableBooks(books[index]);
		cout << book1.getName() << " added to the library." << endl;
	}
	void removeBook(Book& book1) {
		int index = indexOfBooks(book1, books);
		if (index == -1) {
			cout << "The book does not found in the library" << endl;
			return;
		}
		cout << books[indexOfBooks(book1, books)].getName() << " removed!" << endl;
		books.erase(books.begin() + indexOfBooks(book1, books));
	}
	void borrowTheBook(Book& book1, string borrowerName) {
		for (int i = 0; i < books.size(); i++) {
			if (book1.getName() == books[i].getName()) {
				if (books[i].getAvailableBooks() == 0) {
					cout << books[i].getName() << " does not in the library." << endl;
					return;
				}
				books[i].decreaseAvailableBooks(books[i]);
				books[i].setBorrowerName(borrowerName);
				cout << books[i].getName() << " have borrowed by " << books[i].getBorrowerName() << endl;
				return;
			}
		}
		cout << book1.getName() << " not found in the Library." << endl;
	}
	void sellTheBook(Book& book1, string buyerName) {
		if (!(isIn(book1, books))) {
			cout << "The library does not have the book you want." << endl;
			return;
		}
		for (int i = 0; i < books.size();i++) {
			if (book1.getName() == books[i].getName()) {
				if (books[i].getAvailableBooks() == 0) {
					cout << "The library does not have " << books[i].getName() << "." << endl;
					return;
				}
				else {
					books[i].setBuyerName(buyerName);
					if (books[i].getAvailableBooks() == 1) {
						books[i].decreaseAvailableBooks(books[i]);
						cout << "The last " << books[i].getName() << " was sold by " << books[i].getBuyerName() << endl;
						return;
					}
					else {
						books[i].decreaseAvailableBooks(books[i]);
						cout << books[i].getName() << " was sold by " << books[i].getBuyerName() << endl;
						cout << "Number of " << books[i].getName() << ":" << books[i].getAvailableBooks() << endl;
						return;
					}
				}
			}
		}
	}
	void printLibrary() {
		if (books.size() == 0) {
			cout << "The library is empty." << endl;
		}
		else {
			for (int i = 0;i < books.size();i++) {
				books[i].printInfoOfBook(books[i]);
				cout << endl;
			}
		}
	}
	int indexOfBooks(Book& book1, vector<Book>& books) {
		for (int i = 0;i < books.size();i++) {
			if (book1.getName() == books[i].getName()) {
				return i;
			}
		}
		return -1;
	}
	bool isIn(Book& book1, vector<Book>& books) {
		int index = indexOfBooks(book1, books);
		if (index > -1) {
			return true;
		}
		else {
			return false;
		}
	}
	void setOfBooks(Book& book1, int i) {
		int index = indexOfBooks(book1, books);
		if (index == -1) {
			cout << "The book does not found in the library." << endl;
			return;
		}
		books[index].setAvailableBooks(book1, books, i, index);
		cout << endl;
	}
};
int main() {

	Library library;
	Book book1("Life of Pi", "Yann Martel", 100);
	Book book2("The Great Gatsby", "F. Scott Fitzgerald", 180);

	library.addBook(book1);
	library.addBook(book2);
	cout << endl;

	library.printLibrary();

	library.borrowTheBook(book1, "Yagmur");
	cout << endl;

	library.printLibrary();
	cout << endl;

	library.sellTheBook(book2, "buyer1");
	cout << endl;

	library.printLibrary();
	cout << endl;

	library.addBook(book1);
	cout << endl;

	library.printLibrary();
	cout << endl;

	library.sellTheBook(book1, "buyer2");
	cout << endl;

	library.borrowTheBook(book1, "Ebru");
	cout << endl;

	library.printLibrary();
	cout << endl;

	library.setOfBooks(book1, 5);
	library.setOfBooks(book2, -5);

	library.printLibrary();
	cout << endl;

	return 0;
}

