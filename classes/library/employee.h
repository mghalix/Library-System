//------------------------------------------------------------------------------
/**
 * @file Employee.h
 * @brief class that contains all attributes of a library employee
 */
#pragma once
#include "../abstract/person.h"
class Employee : public Person {
public:
  //Constructors
  Employee(std::string, int, char);
  Employee(std::string, int, char, double, double, double);
  //Setters
  void setSalary(double);
  void setBonus(double);
  void setTaxes(double);
  void setAll(std::string, int, char, double, double, double);
  //Getters
  int getID(void);
  double getSalary(void) const;
  double getBonus(void) const;
  double getTaxes(void) const;
  //Methods
  double calculateNetSalary(void);
  void showInfo(void) override;
private:
  //Attributes
  static int sID;
  int mEmpID;
  double mSalary, mBonus, mTaxes;
};
//------------------------------------------------------------------------------
int Employee::sID = 1000;
//------------------------------------------------------------------------------
Employee::Employee(std::string name, int age = 1, char gender = 'm') : Person(name, age, gender), mEmpID(sID++) {
  mSalary = 0;
  mBonus = 0;
  mTaxes = 0;
}
//------------------------------------------------------------------------------
Employee::Employee(std::string name = "no_name", int age = 1, char gender = 'M', double salary = 0, double bonus = 0, double taxes = 0) : Person(name, age, gender), mEmpID(sID++) {
  mSalary = salary;
  mBonus = bonus;
  mTaxes = taxes;
}
//------------------------------------------------------------------------------
void Employee::setSalary(double salary) { mSalary = salary; }
//------------------------------------------------------------------------------
void Employee::setBonus(double bonus) { mBonus = bonus; }
//------------------------------------------------------------------------------
void Employee::setTaxes(double taxes) { mTaxes = taxes; }
//------------------------------------------------------------------------------
void Employee::setAll(std::string name, int age, char gender, double salary, double bonus, double taxes) {
  setName(name);
  setAge(age);
  setGender(gender);
  mSalary = salary;
  mBonus = bonus;
  mTaxes = taxes;
}
//------------------------------------------------------------------------------
int Employee::getID(void) { return mEmpID; }
//------------------------------------------------------------------------------
double Employee::getSalary(void) const { return mSalary; }
//------------------------------------------------------------------------------
double Employee::getBonus(void) const { return mBonus; }
//------------------------------------------------------------------------------
double Employee::getTaxes(void) const { return mTaxes; }
//------------------------------------------------------------------------------
double Employee::calculateNetSalary(void) {
  return (mSalary + mBonus) - (mTaxes * mSalary);
}
//------------------------------------------------------------------------------
void Employee::showInfo(void) {
  std::cout << "Employee's Name: " << getName() << std::endl
    << "Employee's Age: " << getAge() << std::endl
    << "Employee's Gender: " << getGender() << std::endl
    << "Employee's ID: " << mEmpID << std::endl
    << "Employee's Salary: " << mSalary << std::endl
    << "Employee's Net Salary: " << std::to_string(calculateNetSalary()) << std::endl
    << "Employee's Taxes: " << mTaxes << std::endl;
}
//------------------------------------------------------------------------------
