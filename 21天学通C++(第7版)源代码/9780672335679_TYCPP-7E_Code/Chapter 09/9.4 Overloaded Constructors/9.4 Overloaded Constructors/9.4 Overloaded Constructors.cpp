#include <iostream>
#include <string>
using namespace std;

class Human
{
private:
   // Private member data:
   string Name;
   int Age;
   
public:
   // constructor
   Human() 
   {
      Age = 0; // initialized to ensure no junk value
      cout << "Default constructor creates an instance of Human" << endl;
   }

   // overloaded constructor that takes Name
   Human(string HumansName) 
   {
      Name = HumansName;
      Age = 0; // initialized to ensure no junk value
      cout << "Overloaded constructor creates " << Name << endl;
   }

   // overloaded constructor that takes Name and Age
   Human(string HumansName, int HumansAge) 
   {
      Name = HumansName;
      Age = HumansAge;
      cout << "Overloaded constructor creates ";
	  cout << Name << " of " << Age << " years" << endl;
   }

   void SetName (string HumansName)
   {
      Name = HumansName;
   }

   void SetAge(int HumansAge)
   {
      Age = HumansAge;
   }

   void IntroduceSelf()
   {
      cout << "I am " + Name << " and am ";
     cout << Age << " years old" << endl;
   }
};

int main()
{
   Human FirstMan; // use default constructor
   FirstMan.SetName("Adam");
   FirstMan.SetAge(30);

   Human FirstWoman ("Eve"); // use overloaded constructor
   FirstWoman.SetAge (28);

   Human FirstChild ("Rose", 1);
   
   FirstMan.IntroduceSelf();
   FirstWoman.IntroduceSelf();
   FirstChild.IntroduceSelf();
}