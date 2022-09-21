//------------------------------------------------------------------------------
#pragma once
class Date;
#include <iostream>
//used final keyword to prevent inheritance of this class
//since I used setters in the body of my constructor this
//way makes it a safe practice. Otherwise it could be dangerous in the case
//of having this class inherited later, as it might mess up and use
//sub-classes methods instead of the intended setters
class Date final {
public:
  //Attributes
  static const std::string MONTHS[12];
  static const std::string DAYS[7];
  static const int DAYS_IN_MONTHS[13];
  //Constructors
  Date(int, int, int);
  Date(const Date &);
  //Methods
  bool isLeapYear(int);
  bool isValidDate(int, int, int);
  static int getDayOfWeek(int, int, int);
  static int getDayOfWeek(Date);
  //Setters
  void setDate(int, int, int);
  void setDay(int);
  void setMonth(int);
  void setYear(int);
  //Getters
  int getDay(void) const;
  int getMonth(void) const;
  int getYear(void) const;
  //Methods
  std::string toString(void);
  Date nextDay(void);
  Date nextMonth(void);
  Date nextYear(void);
  Date previousDay(void);
  Date previousMonth(void);
  Date previousYear(void);
private:
  int mYear, mMonth, mDay;
  friend std::ostream &operator<<(std::ostream &, const Date &);
};
//------------------------------------------------------------------------------
const std::string Date::MONTHS[12] = {
  "Jan",
  "Feb",
  "Mar",
  "Apr",
  "May",
  "Jun",
  "Jul",
  "Aug",
  "Sep",
  "Oct",
  "Nov",
  "Dec"
};
//------------------------------------------------------------------------------
const std::string Date::DAYS[7] = {
  "Sunday",
  "Monday",
  "Tuesday",
  "Wednesday",
  "Thursday",
  "Friday",
  "Saturday"
};
//------------------------------------------------------------------------------
const int Date::DAYS_IN_MONTHS[13] = {
  0,
  31,
  28,
  31,
  30,
  31,
  30,
  31,
  31,
  30,
  31,
  30,
  31
};
//------------------------------------------------------------------------------
Date::Date(int day = 1, int month = 1, int year = 2022) {
  setYear(year);
  setMonth(month);
  setDay(day);
}
//------------------------------------------------------------------------------
Date::Date(const Date &date) {
  mDay = date.mDay;
  mMonth = date.mMonth;
  mYear = date.mYear;
}
//------------------------------------------------------------------------------
bool Date::isLeapYear(int year) {
  return ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)));
}
//------------------------------------------------------------------------------
bool Date::isValidDate(int year, int month, int day) {
  return (month > 0 && month <= 12 && ((day > 0 && day <= DAYS_IN_MONTHS[month - 1]) || (month == 2 && day == 29 && year % 4 == 0)));
}
//------------------------------------------------------------------------------
int Date::getDayOfWeek(int day, int month, int year) {
  static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
  year -= month < 3;
  return (year + year / 4 - year / 100 + year / 400 + t[month - 1] + day) % 7;
}
//------------------------------------------------------------------------------
int Date::getDayOfWeek(Date date) {
  static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
  date.mYear -= date.mMonth < 3;
  return (date.mYear + date.mYear / 4 - date.mYear / 100 + date.mYear / 400 + t[date.mMonth - 1] + date.mDay) % 7;
}
//------------------------------------------------------------------------------
void Date::setDate(int day, int month, int year) {
  setDay(day);
  setMonth(month);
  mYear = year;
}
//------------------------------------------------------------------------------
void Date::setDay(int day) {
  try {
    if (day > 0 && day <= DAYS_IN_MONTHS[mMonth])
      mDay = day;
    else if (mMonth == 2 && day == 29 && isLeapYear(mYear))
      mDay = day;
    else
      throw "Error Invalid Day";
  }
  catch (const char *msg) {
    std::cerr << msg << std::endl;
    exit(0);
  }
}
//------------------------------------------------------------------------------
void Date::setMonth(int month) {
  try {
    if (month > 0 && month <= 12)
      mMonth = month;
    else
      throw "Error, Invalid Month";
  }
  catch (const char *msg) {
    std::cerr << msg << std::endl;
    exit(0);
  }
}
//------------------------------------------------------------------------------
void Date::setYear(int year) {
  mYear = year;
}
//------------------------------------------------------------------------------
int Date::getDay(void) const { return mDay; }
//------------------------------------------------------------------------------
int Date::getMonth(void) const { return mMonth; }
//------------------------------------------------------------------------------
int Date::getYear(void) const { return mYear; }
//------------------------------------------------------------------------------
std::string Date::toString(void) {
  return DAYS[getDayOfWeek(*this)] + ", " + std::to_string(mDay) + ' ' + MONTHS[mMonth - 1] + ' ' + std::to_string(mYear);
}
//------------------------------------------------------------------------------
Date Date::nextDay(void) {
  if (mDay > 0 && mDay < DAYS_IN_MONTHS[mMonth]) {
    mDay++;
  }
  else if (mDay == 31 && mMonth == 12) {
    mMonth = 1;
    mDay = 1;
    mYear += 1;
  }
  else if (DAYS_IN_MONTHS[mMonth] == mDay || mMonth == 2 && mDay == 29 && isLeapYear(mYear)) {
    mDay = 1;
    mMonth += 1;
  }
  return *this;
}
//------------------------------------------------------------------------------
Date Date::nextMonth(void) {
  if (mMonth == 1 && mDay == 29 && !isLeapYear(mYear))
    mDay--;

  if (mMonth > 0 && mMonth < 12) {
    mMonth++;
  }
  else if (mMonth == 12) {
    mMonth = 1;
    mYear += 1;
  }

  return *this;
}
//------------------------------------------------------------------------------
Date Date::nextYear(void) {
  //check if the current year is leap and month is feb and day is the last
  //in feb which is 29 on leap years, for the next year it must be 28
  if (mMonth == 2 && mDay == 29 && isLeapYear(mYear))
    mDay--;

  mYear++;
  return *this;
}
//------------------------------------------------------------------------------
Date Date::previousDay(void) {
  if (mDay <= 1 && mDay <= DAYS_IN_MONTHS[mMonth])
    mDay--;
  else if (mDay == 1 && mMonth == 1) {
    mMonth = 12;
    mDay = 31;
    mYear -= 1;
  }
  else if (DAYS_IN_MONTHS[mMonth] == mDay || mMonth == 2 && mDay == 29 && isLeapYear(mYear)) {
    mDay = 1;
    mMonth += 1;
  }

  return *this;
}
//------------------------------------------------------------------------------
Date Date::previousMonth(void) {
  if (mMonth == 3 && mDay > 28 && !isLeapYear(mYear))
    mDay--;

  if (mMonth > 1 && mMonth <= 12) {
    mMonth--;
  }
  else if (mMonth == 1) {
    mMonth = 12;
    mDay = 31;
    mYear -= 1;
  }
  return *this;
}
//------------------------------------------------------------------------------
Date Date::previousYear(void) {
  if (mMonth == 2 && mDay == 28 && isLeapYear(mYear - 1))
    mDay++;


  if (mMonth == 2 && mDay == 28 && isLeapYear(mYear - 1))
    mDay++;
  else if (mMonth == 2 && mDay == 29 && isLeapYear(mYear))
    mDay--;

  mYear--;
  return *this;
}
//------------------------------------------------------------------------------
std::ostream &operator<<(std::ostream &out, const Date &date) {
  out << Date::DAYS[Date::getDayOfWeek(date)] << ", "
    << std::to_string(date.mDay) << ' ' << date.MONTHS[date.mMonth - 1]
    << ' ' << std::to_string(date.mYear);
  return out;
}
//------------------------------------------------------------------------------