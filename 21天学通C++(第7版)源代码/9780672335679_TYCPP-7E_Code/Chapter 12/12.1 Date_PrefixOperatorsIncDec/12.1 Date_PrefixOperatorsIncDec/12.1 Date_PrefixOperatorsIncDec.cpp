// also contains postfix increment and decrement

#include <iostream>
using namespace std;

class Date
{
private:
   int Day;  // Range: 1 - 30 (lets assume all months have 30 days!
   int Month;
   int Year;

public:

   // Constructor that initializes the object to a day, month and year
   Date (int InputDay, int InputMonth, int InputYear)
      : Day (InputDay), Month (InputMonth), Year (InputYear) {};

   // Unary increment operator (prefix)
   Date& operator ++ ()
   {
      ++Day;

      return *this;
   }

   // Unary decrement operator (prefix)
   Date& operator -- ()
   {
      --Day;

      return *this;
   }

   // postfix increment operator: differs from prefix in return-type and input param
   Date operator ++ (int)
   {
      // Store a copy of the current state of the object, before incrementing day
      Date Copy (Day, Month, Year);

      ++Day;

      // Return the state before increment was performed
      return Copy;
   }

   Date operator -- (int)
   {
      Date Copy (Day, Month, Year);

      --Day;

      return Copy;
   }

   void DisplayDate ()
   {
      cout << Day << " / " << Month << " / " << Year << endl;
   }
};

int main ()
{
   // Instantiate and initialize a date object to 25 Dec 2011
   Date Holiday (25, 12, 2011);

   cout << "The date object is initialized to: ";
   Holiday.DisplayDate ();

   // Applying the prefix increment operator
   Holiday++;

   cout << "Date after prefix-increment is: ";

   // Display date after incrementing
   Holiday.DisplayDate ();

   Holiday--; 
   Holiday--;

   cout << "Date after two prefix-decrements is: ";
   Holiday.DisplayDate ();

   return 0;
}