//------------------------------------------------------------------------------
#pragma once
#include "book.h"
#include "../assets/helpers_methods.h"
#include <vector>
class LibraryBooksManagement {
public:
  LibraryBooksManagement(void);
  ~LibraryBooksManagement(void);
  static void findBook(const std::string &);
  static int getBookIndex(const std::string &);
  static Book getBook(const std::string &);
  static void showAllBooks(void);
  static void showAvailableBooks(void);
  static void showUnavailableBooks(void);
  static void getBookDescription(std::string);
  static void deleteBook(int);
  static void addBook(Book);
  static void requestingReturn(const Book &);
};
//------------------------------------------------------------------------------
LibraryBooksManagement::LibraryBooksManagement(void) {
  for (int iBook = 0; iBook < 5; iBook++) {
    std::string name = "Book " + std::to_string(iBook + 1);
    addBook(Book(name));
  }
}
//------------------------------------------------------------------------------
LibraryBooksManagement::~LibraryBooksManagement(void) {}
//------------------------------------------------------------------------------
void LibraryBooksManagement::findBook(const std::string &name) {
  int iBook = getBookIndex(name);
  if (iBook != -1) {
    std::cout << '{' << Book::sBooks[iBook].getBookName() << "} book is available!\n";
    return;
  }
  std::cout << '{' << name << "} book is not found\n";
}
//------------------------------------------------------------------------------
int LibraryBooksManagement::getBookIndex(const std::string &name) {
  for (int iBook = 0; iBook < Book::sBooks.size(); iBook++)
    if (Helper::toUpper(Book::sBooks[iBook].getBookName()) == Helper::toUpper(name))
      return iBook;

  return -1;
}
//------------------------------------------------------------------------------
Book LibraryBooksManagement::getBook(const std::string &name) {
  int iBook = getBookIndex(name);
  if (iBook == -1)
    throw 0;

  if (!Book::sBooks[iBook].isAvailable())
    throw "This book is currently unavailable.";

  Book::borrowedABook();
  Book::sBooks[iBook].setAvailability(0);
  return Book::sBooks[iBook];
}
//------------------------------------------------------------------------------
void LibraryBooksManagement::showAllBooks(void) {
  if (Book::sBooks.empty()) {
    std::cout << "No available books right now, please update the library.\n";
    return;
  }

  for (int iBook = 0; iBook < Book::sBooks.size(); iBook++) {
    std::cout << "Book[" << iBook + 1 << "]: " << Book::sBooks[iBook].getBookName();

    (!(Book::sBooks[iBook].isAvailable())) ? std::cout << " <- Currently Unavailable.\n" : std::cout << std::endl;
  }
}
//------------------------------------------------------------------------------
void LibraryBooksManagement::showAvailableBooks(void) {
  if (Book::sBooks.empty()) {
    std::cout << "No books have been added, please update the library.\n";
    return;
  }


  for (int iBook = 0; iBook < Book::sBooks.size(); iBook++) {
    if (Book::sBooks[iBook].isAvailable())
      std::cout << Book::sBooks[iBook].getBookName() << std::endl;
  }
}
//------------------------------------------------------------------------------
void LibraryBooksManagement::showUnavailableBooks(void) {
  if (Book::sBooks.empty()) {
    std::cout << "No unavailable books right now.\n";
    return;
  }

  for (int iBook = 0; iBook < Book::getBooksAmount(); iBook++) {
    if (!(Book::sBooks[iBook].isAvailable()))
      std::cout << Book::sBooks[iBook].getBookName() << std::endl;
  }
}
//------------------------------------------------------------------------------
void LibraryBooksManagement::getBookDescription(std::string name) {
  int iBook = getBookIndex(name);
  if (iBook == -1)
    return;
  const Book b = Book::sBooks[iBook];
  std::cout << "\t{" << b.getBookName() << '}' << " was published in: " << b.getPublishDate() << std::endl
    << "\t{" << b.getBookName() << "} is written by " << b.getAuthor().getName() << ", who was born in " << (2022 - b.getAuthor().getAge()) << '.' << std::endl
    << "\tRight now there are x" << b.isAvailable() << " of {" << b.getBookName() << "} book available in this library." << std::endl;
}
//------------------------------------------------------------------------------
void LibraryBooksManagement::deleteBook(int pos) {
  Book::sBooks.erase(Book::sBooks.begin() + pos);
}
//------------------------------------------------------------------------------
void LibraryBooksManagement::requestingReturn(const Book &book) {
  Book::sBooks.at(book.getBookID()).setAvailability(1);
}
//------------------------------------------------------------------------------
void LibraryBooksManagement::addBook(Book newBook) {
  if (getBookIndex(newBook.getBookName()) != -1) {
    std::cout << "This book already exists in the library but currently unavailable, please add another book.\n";
    return;
  }

  Book::sBooks.push_back(newBook);
  Book::addedABook();
}
//------------------------------------------------------------------------------