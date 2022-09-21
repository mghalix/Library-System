/**
 * @file main.cpp
 * @author Mohanad Ghali mghalix@gmail.com
 * @brief This is the main file
 * @version 0.1
 * @date 2022-09-12
 * @details This file has the entry programming point main()
 */
#include "../classes/library/library.h"
#include "../classes/library/Library_runner.h"
using namespace std;
int main() {
  // Client c1("Mohanad", 21, 'M');
  // Client c2("Eslam", 19, 'M');
  // // c1.borrowBook("book 3");
  // c1.borrowBook("book 4");
  // c1.borrowBook("book 4");
  // c2.borrowBook("book 3");
  // c2.borrowBook("book 1");
  // c2.borrowBook("book 2");
  // c1.borrowBook("Book 5");
  // Library::showAllBooks();
  // Book newBook("book 3");
  // Library::addBook(newBook);
  // Library::showAvailableBooks();
  // Library::showAllBooks(); 

  LibraryRunner::runApp();






  // Library::showUnreturnedBooks();
  // c1.borrowBook("book 2");
  // c1.borrowBook("book 1");
  // c1.borrowBook("book 4");
  // c1.showBorrowedBooks();
  // c2.borrowBook("Book 4");
  // c2.borrowBook("book 5");
  // c2.showBorrowedBooks();
  // Library::showUnreturnedBooks();
  // c1.borrowBook("boOk 1");
  // Library::showAvailableBooks();
  // Library::showAllBooks();
  // LibraryBooksManagement::showAllBooks();
  // //--------------------------------------------------------------------------//
  // // c1.borrowBook("Book 3");
  // // c1.borrowBook("Book 1", lib);
  // // c1.borrowBook("book 2", lib);
  // /*//test case for borrowing more than 3 books
  // c1.borrowBook("Book 4", lib);
  // // c1.showInfo();
  // //--------------------------------------------------------------------------//
  // c1.borrowBook("book 4");
  // //--------------------------------------------------------------------------//
  // // c2.showBorrowedBooks();
  // c2.returnBook("book 5");
  // // c2.showBorrowedBooks();
  // // c2.showInfo();
  // c2.returnBook("book 4");
  // // lib.showUnreturnedBooks();
  // Library::showAvailableBooks();
  // // c1.borrowBook("book 5");
}