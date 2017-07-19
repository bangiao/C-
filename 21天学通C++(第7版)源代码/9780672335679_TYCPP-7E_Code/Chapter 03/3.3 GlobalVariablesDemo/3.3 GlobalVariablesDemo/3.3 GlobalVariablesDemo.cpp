#include <iostream>
using namespace std;

// Declare three global integers
int FirstNumber = 0;
int SecondNumber = 0;
int Result = 0;

void MultiplyNumbers ()
{
   cout << "Enter the first number: ";
   cin >> FirstNumber;

   cout << "Enter the second number: ";
   cin >> SecondNumber;

   // Multiply two numbers, store result in a variable
   Result = FirstNumber * SecondNumber;

   // Display result
   cout << "Displaying from MultiplyNumbers(): ";
   cout << FirstNumber << " x " << SecondNumber << " = " << Result << endl;
}

int main ()
{
   cout << "This program will help you multiply two numbers" << endl;

   // Call the function that does all the work
   MultiplyNumbers();

   cout << "Displaying from main(): ";

   // This line will now compile and work!
   cout << FirstNumber << " x " << SecondNumber << " = " << Result << endl;

   return 0;
}