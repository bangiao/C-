#include <iostream>
using namespace std; 
   
class Fish
{
public:
   void Swim()
   {
	   cout << "Fish swims... !" << endl;
   }

   void Swim(bool FreshWaterFish)
   {
      if (FreshWaterFish)
         cout << "Swims in lake" << endl;
      else
         cout << "Swims in sea" << endl;
   }
};

class Tuna: public Fish
{
public:
   void Swim(bool FreshWaterFish)
   {
	   Fish::Swim(FreshWaterFish);
   }

   void Swim()
   {
      cout << "Tuna swims real fast" << endl;
   }
};

int main()
{
   Tuna myDinner;

   cout << "Getting my food to swim" << endl;
   
   myDinner.Swim(false); // compile failure: Fish::Swim(bool) is hidden by Tuna::Swim()

   myDinner.Swim();

   return 0;
}