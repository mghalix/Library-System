//------------------------------------------------------------------------------
/**
 * @file Library.h
 * @brief The library that has all the books
 * @version 0.1
 * @date 2022-09-12
 */
#pragma once
class Library;
#include "client.h"
#include "employee.h"
#include "book_management.h"
#include <map>
class Library {
public:
  // Constructors
  Library(void);
  ~Library(void);
  //Getters
  static LibraryBooksManagement enterBooksDepartment(void);
  //Methods
  // shows borrowed books and their borrower info
  static void showUnreturnedBooks(void);
  // shows all books that aren't borrowed
  static void showAvailableBooks(void);
  // show all books borrowed or not
  static void showAllBooks(void);
  // starts a main menu on the console for the clients to perform all operations
  // available (ex. search for a book / borrow)
  // static LibraryRunner runApp(void);
  static void showAvailableBooksAmount(void);
  static void addBook(Book);
  static std::map<Book, Client> sDueReturnBooks;
protected:
private:
  //Attributes
  static LibraryBooksManagement mBooksDepartment;
  Client mClient;
  // static LibraryOps mOps;
  // Employee mEmployee;
};
//------------------------------------------------------------------------------
std::map <Book, Client> Library::sDueReturnBooks;
//------------------------------------------------------------------------------
LibraryBooksManagement Library::mBooksDepartment;
//------------------------------------------------------------------------------
Library::Library(void) {}
//------------------------------------------------------------------------------
Library::~Library(void) {}
//------------------------------------------------------------------------------
LibraryBooksManagement Library::enterBooksDepartment(void) {
  return mBooksDepartment;
}
//------------------------------------------------------------------------------
void Library::showAvailableBooks(void) {
  std::cout << "***** Available Books in the Library *****" << std::endl;
  if (Book::getBooksAmount() == 0) {
    std::cout << "No available books in the library right now, please come back later\n";
    return;
  }
  LibraryBooksManagement::showAvailableBooks();
}
//------------------------------------------------------------------------------
void Library::showUnreturnedBooks(void) {
  if (sDueReturnBooks.empty()) {
    std::cout << "No Books Were Borrowed.\n";
    return;
  }
  std::cout << "**** Books Due Return ****" << std::endl
    << "Book Name" << "\tBorrower" << std::endl;
  //auto equivalent to -> std::_Rb_tree_iterator<std::pair<const Book, Client>> 
  for (std::_Rb_tree_iterator<std::pair<const Book, Client>> iUnreturned = sDueReturnBooks.begin(); iUnreturned != sDueReturnBooks.end(); iUnreturned++) {
    std::cout << iUnreturned->first.getBookName()
      << "\t\tclient#" << iUnreturned->second.getID() << ": "
      << iUnreturned->second.getName() << std::endl;
  }
}
//------------------------------------------------------------------------------
void Client::borrowBook(const std::string &bookName, const Library &lib = Library()) {
  try {
    if (mBorrowedBooksAmount > 2)
      throw "You cannot borrow more than three books, please return some books first.";
    Book book = Library::enterBooksDepartment().getBook(bookName);
    mBorrowedBooks.push_back(book);
    std::cout << "Congrats " << getName() << " you have borrowed " << Helper::correctNamePunctuation(bookName) << " book successfully!\n";
    mBorrowedBooksAmount++;
    Library::sDueReturnBooks[book] = *this;
  }
  catch (int a) {
    std::cerr << bookName + " is not found" << std::endl;;
  }
  catch (const char *msg) {
    std::cerr << msg << std::endl;
  }
  // catch (...) {
    // std::cerr << bookName << " is unavailable" << std::endl;
  // }
}
//------------------------------------------------------------------------------
void Client::returnBook(const std::string &bookName, const Library &lib = Library()) {

  try {
    if (mBorrowedBooksAmount < 1)
      throw "You have not borrowed a book to return.";

    int iBook;
    for (iBook = 0; iBook < Book::getBooksAmount(); iBook++) {
      if (Helper::toUpper(mBorrowedBooks[iBook].getBookName()) == Helper::toUpper(bookName)) {
        break;
      }
    }

    Book book = mBorrowedBooks[iBook];
    LibraryBooksManagement::requestingReturn(book);
    mBorrowedBooksAmount--;
    mBorrowedBooks.erase(mBorrowedBooks.begin() + iBook);
    Library::sDueReturnBooks.erase(Library::sDueReturnBooks.find(book));
    book.setAvailability(1);
    Book::bookHasReturned();
  }
  catch (const char *msg) {
    std::cerr << msg << std::endl;
  }
}
//------------------------------------------------------------------------------
void Library::showAllBooks(void) {
  mBooksDepartment.showAllBooks();
}
//------------------------------------------------------------------------------
void Library::showAvailableBooksAmount(void) {
  std::cout << Book::getBooksAmount() << std::endl;
}
//------------------------------------------------------------------------------
void Library::addBook(Book newBook) {
  mBooksDepartment.addBook(newBook);
}
//------------------------------------------------------------------------------



