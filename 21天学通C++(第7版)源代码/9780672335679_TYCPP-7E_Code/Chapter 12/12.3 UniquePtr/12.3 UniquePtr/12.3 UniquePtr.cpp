#include <iostream>
#include <memory>
using namespace std;

class Date
{
private:
   int Day;
   int Month;
   int Year;

   string DateInString;

public:
   // Constructor that initializes the object to a day, month and year
   Date (int InputDay, int InputMonth, int InputYear)
      : Day (InputDay), Month (InputMonth), Year (InputYear) {};

   void DisplayDate()
   {
      cout << Day << " / " << Month << " / " << Year << endl;
   }
};

int main()
{
   unique_ptr<int> pDynamicAllocInteger(new int);
   *pDynamicAllocInteger = 42;

   // Use smart pointer type like an int*
   cout << "Integer value is: " << *pDynamicAllocInteger << endl;

   unique_ptr<Date> pHoliday (new Date(25, 11, 2011));
   cout << "The new instance of date contains: ";

   // use pHoliday just as you would a Date*
   pHoliday->DisplayDate();

   // no need to do the following when using unique_ptr:
   // delete pDynamicAllocInteger;
   // delete pHoliday; 

   return 0;
}