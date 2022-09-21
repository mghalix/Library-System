//------------------------------------------------------------------------------
#pragma once
#include "../abstract/person.h"
class Author;
class Author : public Person {
public:
  //Constructors
  Author(std::string, int, char, std::string, std::string);
  //Setters
  void setEmail(std::string);
  //Getters
  std::string getEmail(void) const;
  //Methods
  void showInfo(void) override;
private:
  //Attributes
  std::string mEmail, mNationality;
  friend std::istream &operator>>(std::istream &, Author &);
  friend std::ostream &operator<<(std::ostream &, const Author &);
};
//------------------------------------------------------------------------------
Author::Author(std::string name = "unknown", int age = 1, char gender = 'M', std::string email = "abc@mEmail.com", std::string nationality = "earth")
  :Person(name, age, gender), mEmail(email), mNationality(Helper::punctuationWordCorrector(nationality)) {}
//------------------------------------------------------------------------------
void Author::setEmail(std::string email) { mEmail = email; }
//------------------------------------------------------------------------------
std::string Author::getEmail(void) const { return mEmail; }
//------------------------------------------------------------------------------
void Author::showInfo(void) {
  std::cout << "Author's Name: " << getName() << std::endl
    << getName() << "'s Age: " << getAge() << std::endl
    << getName() << "'s Gender: " << getGender() << std::endl
    << getName() << "'s Email: " << mEmail << std::endl
    << getName() << "'s Nationality: " << mNationality << std::endl;
}
//------------------------------------------------------------------------------
std::istream &operator>>(std::istream &inp, Author &a) {
  inp >> a.mEmail;
  return inp;
}
//------------------------------------------------------------------------------
std::ostream &operator<<(std::ostream &out, const Author &a) {
  out << "Author's Name: " << a.getName() << std::endl
    << a.getName() << "'s Age: " << a.getAge() << std::endl
    << a.getName() << "'s Gender: " << a.getGender() << std::endl
    << a.getName() << "'s Email: " << a.mEmail << std::endl
    << a.getName() << "'s Nationality: " << a.mNationality;
  return out;
}
//------------------------------------------------------------------------------