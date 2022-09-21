//------------------------------------------------------------------------------
#pragma once
#include <iostream>
#include "../assets/helpers_methods.h"
class Person {
public:
  // Constructors
  Person(std::string, int, char);
  // Deconstructor
  ~Person(void);
  // Setters
  void setName(std::string);
  void setAge(int);
  void setGender(char);
  void setID(int);
  // Getters
  std::string getName(void) const;
  int getAge(void) const;
  int getID(void) const;
  char getGender(void) const;
  virtual void showInfo(void) = 0;
  // Operator overloading
  bool operator<(const Person &);
private:
  // Attributes
  std::string mName;
  int mAge;
  static int sID;
  int mPersonID;
  char mGender;
  //Helpers
  int check(int);
};
//------------------------------------------------------------------------------
int Person::sID;
//------------------------------------------------------------------------------
Person::Person(std::string name = "unknown", int age = 1, char gender = 'M') : mName("unknown"), mAge(1), mGender(gender), mPersonID(sID++) {
  try {
    check(age);
    mName = Helper::correctNamePunctuation(name);
    mAge = age;
    mGender = toupper(gender);
  }
  catch (const char *msg) {
    std::cerr << msg << std::endl;
  }
}
//------------------------------------------------------------------------------
Person::~Person() {
  sID--;
}
//------------------------------------------------------------------------------
void Person::setName(std::string name) {
  mName = Helper::correctNamePunctuation(name);
}
//------------------------------------------------------------------------------
void Person::setAge(int age) {
  check(age);
  mAge = age;
}
//------------------------------------------------------------------------------
void Person::setID(int id) { mPersonID = id; }
//------------------------------------------------------------------------------
void Person::setGender(char gender) {
  if (toupper(gender) != 'M' && toupper(gender) != 'F') {
    throw "Invalid Gender";
  }

  mGender = gender;
}
//------------------------------------------------------------------------------
std::string Person::getName(void) const { return mName; }
//------------------------------------------------------------------------------
int Person::getAge(void) const { return mAge; }
//------------------------------------------------------------------------------
int Person::getID(void) const { return mPersonID; }
//------------------------------------------------------------------------------
char Person::getGender(void) const { return mGender; }
//------------------------------------------------------------------------------
int Person::check(int age) {
  if (age <= 0 || age > 120) {
    throw "Invalid Age";
  }
  return 0;
}
//------------------------------------------------------------------------------
bool Person::operator<(const Person &person) {
  return (mName < person.mName);
}
//------------------------------------------------------------------------------