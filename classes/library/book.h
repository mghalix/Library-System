//------------------------------------------------------------------------------
/**
 * @file Book.h
 * @author Mohanad Ghali mghalix@gmail.com
 * @brief class Book attributes
 * @version 0.1
 * @date 2022-09-12
 */
#pragma once
#include "../assets/helpers_methods.h"
#include "../assets/author.h"
#include "../assets/date.h"
#include <memory>
#include <functional>
class Book {
public:
  //Constructors
  static std::vector <Book> sBooks;
  Book(std::string, std::string, Author, int, Date);
  Book(std::string, std::string, int, int, int, int,
    std::string, int, char, std::string);
  //Destructor
  ~Book(void);
  //Setters
  void setBookName(std::string);
  void setCategory(std::string);
  void setID(int);
  void setNumberOfPages(int);
  void setPublishDate(Date);
  void setAuthor(Author);
  void setAuthor(std::string, int, char, std::string);
  //Getters
  std::string getBookName(void) const;
  Author getAuthor(void) const;
  Date getPublishDate(void) const;
  bool isAvailable(void) const;
  static int getBooksAmount(void);
  static void borrowedABook(void);
  static void addedABook(void);
  int getBookID() const;
  //Methods
  void setAvailability(const bool &);
  bool operator<(const Book &) const;
  static void bookHasReturned(void);
private:
  //Attributes
  std::string mBookName, mCategory;
  int mNumberOfPages, mBookID;
  static int sID;
  static int mBooksAmount;
  Date mPublishDate;
  Author mAuthor;
  bool mIsAvailable;
  friend std::istream &operator>>(std::istream &inp, Book &b);
  friend std::ostream &operator<<(std::ostream &out, const Book &b);
};
//------------------------------------------------------------------------------
int Book::sID;
//------------------------------------------------------------------------------
std::vector<Book> Book::sBooks;
//------------------------------------------------------------------------------
int Book::mBooksAmount;
//------------------------------------------------------------------------------
Book::Book(std::string name = "none", std::string category = "Sci-Fi", Author author = Author(), int pages = 0, Date publish = Date()) : mBookID(sID++) {
  mBookName = name;
  mCategory = category;
  mAuthor = author;
  mNumberOfPages = pages;
  mIsAvailable = true;

  // mBooksAmount++;
  // sBooks.push_back(*this);
}
//------------------------------------------------------------------------------
Book::Book(std::string name, std::string category, int pages, int publishDay, int publishMonth, int publishYear, std::string authorName, int authorAge, char authorGender, std::string authorEmail) : mBookID(sID++) {
  mBookName = name;
  mCategory = category;
  mNumberOfPages = pages;
  mIsAvailable = true;
  mAuthor = Author(authorName, authorAge, authorGender, authorEmail);
  mPublishDate = Date(publishDay, publishMonth, publishYear);

  // mBooksAmount++;
  // sBooks.push_back(*this);
}
//------------------------------------------------------------------------------
Book::~Book() {
  // mBooksAmount--;
}
//------------------------------------------------------------------------------
void Book::setBookName(std::string name) { mBookName = name; }
//------------------------------------------------------------------------------
void Book::setCategory(std::string category) { mCategory = category; }
//------------------------------------------------------------------------------
void Book::setNumberOfPages(int pages) { mNumberOfPages = pages; }
//------------------------------------------------------------------------------
void Book::setPublishDate(Date d) { mPublishDate = d; }
//------------------------------------------------------------------------------
void Book::setAuthor(Author author) { mAuthor = author; }
//------------------------------------------------------------------------------
void Book::setAuthor(std::string name, int age, char gender, std::string email) {
  mAuthor.setName(name);
  mAuthor.setAge(age);
  mAuthor.setGender(gender);
  mAuthor.setEmail(email);
}
//------------------------------------------------------------------------------
std::string Book::getBookName(void) const { return mBookName; }
//------------------------------------------------------------------------------
Author Book::getAuthor(void) const { return mAuthor; }
//------------------------------------------------------------------------------
Date Book::getPublishDate(void) const { return mPublishDate; }
//------------------------------------------------------------------------------
int Book::getBooksAmount(void) { return mBooksAmount; }
//------------------------------------------------------------------------------
bool Book::isAvailable(void) const { return mIsAvailable; }
//------------------------------------------------------------------------------
void Book::setAvailability(const bool &b) {
  mIsAvailable = b;
}
//------------------------------------------------------------------------------
std::istream &operator>>(std::istream &inp, Book &b) {
  inp >> b.mBookName >> b.mAuthor;
  return inp;
}
//------------------------------------------------------------------------------
std::ostream &operator<<(std::ostream &out, const Book &b) {
  out << "Book's Name: " << b.mBookName << std::endl
    << "Book's Publish Date: " << b.mPublishDate
    << "\n------\n"
    << "Book's Author Detail: \n" << b.getAuthor()
    << "\n------\n"
    << "Book's Number of Pages: " << b.mNumberOfPages << '$' << std::endl
    << "Amount of Book {" << b.mBookName << "} left in this library: x" <<
    b.mIsAvailable << " book" << std::endl;

  return out;
}
//------------------------------------------------------------------------------
bool Book::operator<(const Book &book) const {
  return (mBookName < book.mBookName);
}
//------------------------------------------------------------------------------
void Book::bookHasReturned(void) {
  mBooksAmount++;
}
//------------------------------------------------------------------------------
int Book::getBookID(void) const { return mBookID; }
//------------------------------------------------------------------------------
void Book::borrowedABook(void) { mBooksAmount--; }
//------------------------------------------------------------------------------

void Book::addedABook(void) { mBooksAmount++; }