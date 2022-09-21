//------------------------------------------------------------------------------
/**
 * @file Client.h
 * @brief class that contains all attributes of a library visitor
 * @version 0.1
 * @date 2022-09-12
 */
#pragma once
#include "../abstract/person.h"
#include "book.h"
class Client : public Person {
public:
  //Constructors
  Client(std::string, int, char);
  // Deconstructor
  ~Client(void);
  // Setters
  void setAll(std::string, int, char);
  // Getters
  bool hasBorrowedBook(void) const;
  void showBorrowedBooks(void);
  int getBorrowedBooksAmount(void) const;
  void showInfo(void) override;
  void borrowBook(const std::string &bookName, const Library &lib);
  void returnBook(const std::string &bookName, const Library &lib);
  int getID(void) const;
private:
  // Attributes
  int mBorrowedBooksAmount, mClientID;
  std::vector<Book> mBorrowedBooks;
  static int sID;
};
//------------------------------------------------------------------------------
int Client::sID;
//------------------------------------------------------------------------------
Client::Client(std::string name = "unknown", int age = 1, char gender = 'm')
  : Person(name, age, gender), mBorrowedBooksAmount(0), mClientID(++sID) {}
//------------------------------------------------------------------------------
Client::~Client(void) {}
//------------------------------------------------------------------------------
void Client::setAll(std::string name, int age, char gender) {
  setName(name);
  setAge(age);
  setGender(gender);
}
//------------------------------------------------------------------------------
bool Client::hasBorrowedBook(void) const {
  return mBorrowedBooksAmount > 0;
}
//------------------------------------------------------------------------------
void Client::showBorrowedBooks(void) {
  if (mBorrowedBooksAmount < 1) {
    std::cout << "Client " << getName() << " has not borrowed any books.\n";
    return;
  }
  std::cout << "**** " << getName() << "'s Borrowed Books ****\n";
  for (auto i = mBorrowedBooks.begin(); i != mBorrowedBooks.end(); i++)
    std::cout << i->getBookName() << std::endl;
}
//------------------------------------------------------------------------------
void Client::showInfo(void) {
  std::cout << "\tClient #" << getID() << ":\tname: " << getName() << "\tage: "
    << getAge() << "\t\tamount of borrowed books: " << mBorrowedBooksAmount << std::endl;
}
//------------------------------------------------------------------------------
int Client::getBorrowedBooksAmount(void) const { return mBorrowedBooksAmount; }
//------------------------------------------------------------------------------
int Client::getID(void) const { return mClientID; }
//------------------------------------------------------------------------------