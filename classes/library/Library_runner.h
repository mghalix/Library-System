//------------------------------------------------------------------------------
#pragma once
#include "library.h"
#include <limits>
class LibraryRunner {
public:
  static void runApp(void);
private:
  static void mainMenu(int &);
  static void moderatorMode(int &);
  static void employeeMenu(int &);
  static void newEmployeeMenu(int &);
  static void moderatorMenu(int &);
  static void visitorMode(int &);
  static void managerMode(int &);
};
//------------------------------------------------------------------------------
void LibraryRunner::mainMenu(int &choice) {
  std::system("clear");
  std::cout << "\t\t**** Welcome To The Library! ****\nAre you a:\n"
    << "1.Visitor\n" << "2.Moderator\n" << "3.Manager\n"
    << "0.Quit\n\n> ";
  do {
    std::cin >> choice;
    switch (choice) {
    case 1:
      visitorMode(choice);
      break;
    case 2:
      moderatorMode(choice);
      break;
    case 3:
      managerMode(choice);
      break;
    case 0:
      return;
      break;
    default:
      std::cout << "There is no such option\n";
    }
  } while (choice != 0);
}
//------------------------------------------------------------------------------
void LibraryRunner::visitorMode(int &choice) {
  std::system("clear");
  std::cout << "\tWelcome to our library visitor, please fill your info\n";
}
//------------------------------------------------------------------------------
void LibraryRunner::moderatorMode(int &choice) {
  moderatorMenu(choice);
}
//------------------------------------------------------------------------------
void LibraryRunner::employeeMenu(int &choice) {
  std::string name;
  int id, age;
  char gender;

  std::cout << "Please Enter Your ID: #";
  //validate the id
  while (choice != 0)
    switch (choice) {
    case 1:
      std::cout << "Press ESC to go back";
      break;
    case 2:
      std::system("clear");
      std::cout << "Please Fill your info:\n1.Name: ";
      std::cin >> name;
      std::cout << "2.Age: ";
      std::cin >> age;
      std::cout << "3.Gender: ";
      std::cin >> gender;
      break;
    case 3:
      mainMenu(choice);
      break;
    case 0:
      choice = 0;
      break;
    default:
      std::cout << "Invalid Option\n";
    }
}
//------------------------------------------------------------------------------
void LibraryRunner::newEmployeeMenu(int &choice) {
  std::system("clear");
  std::cout << "\t\t----Please fill your info below----\n";
  Employee newEmployee;
  std::string name;
  int age;
  char gender;

  std::cout << "Name: ";
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::getline(std::cin, name);
  newEmployee.setName(name);

  while (true) {
    try {
      std::cout << "Age: ";
      std::cin >> age;
      newEmployee.setAge(age);

      break;
    }
    catch (const char *msg) {
      std::cout << msg << ", please try again\n";
    }
  }
  while (true) {
    try {
      std::cout << "Gender: ";
      std::cin >> gender;
      newEmployee.setGender(gender);

      break;
    }
    catch (const char *msg) {
      std::cerr << msg << ", please type M for male or F for Female\n";
    }
  }

  std::cout << "You have registered successfully, here's your new ID: #" << newEmployee.getID() << "\nGood Luck Champ.\n";

}
//------------------------------------------------------------------------------
void LibraryRunner::moderatorMenu(int &choice) {
  std::system("clear");
  std::cout << "\t\t**** Hello Employee ****\n" <<
    "Are you:\n" << "1.An old Employee\n" << "2.A new Employee\n"
    << "3.Go back to main menu\n\n> ";
  do {
    std::cin >> choice;
    switch (choice) {
    case 1:
      employeeMenu(choice);
    case 2:
      newEmployeeMenu(choice);
    case 3:
      mainMenu(choice);
    case 0:
      return;
    default:
      std::cout << "Invalid Option, please select again\n> ";
    }
  } while (choice != 0);
}
//------------------------------------------------------------------------------
void LibraryRunner::managerMode(int &choice) {
  std::system("clear");
  std::cout << "\t\tWelcome Mohanad, what would you like to do today\n";
}
//------------------------------------------------------------------------------
void LibraryRunner::runApp(void) {
  int choice;
  do {
    mainMenu(choice);
  } while (choice != 0);

}
//------------------------------------------------------------------------------