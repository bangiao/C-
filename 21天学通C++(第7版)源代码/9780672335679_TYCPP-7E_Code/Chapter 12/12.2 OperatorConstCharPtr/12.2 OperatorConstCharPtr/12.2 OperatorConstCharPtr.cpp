#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Date
{
private:
   int Day;  // Range: 1 - 30 (lets assume all months have 30 days!
   int Month;
   int Year;

   string DateInString;

public:

   // Constructor that initializes the object to a day, month and year
   Date (int InputDay, int InputMonth, int InputYear)
      : Day (InputDay), Month (InputMonth), Year (InputYear) {};

   operator const char*()
   {
      ostringstream formattedDate;
      formattedDate << Day << " / " << Month << " / " << Year;
     
      DateInString = formattedDate.str();
      return DateInString.c_str();
   }
};
   
int main ()
{
   // Instantiate and initialize a date object to 25 Dec 2011
   Date Holiday (25, 12, 2011);

   cout << "Holiday is on: " << Holiday << endl;

   //string strHoliday (Holiday); // OK!
   //strHoliday = Date(11, 11, 2011); // also OK!

   return 0;
}