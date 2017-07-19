#include <iostream>
using namespace std;


int main()
{
   enum COLORS
   {
      VIOLET = 0,
      INDIGO,
      BLUE,
      GREEN,
      YELLOW,
      ORANGE,
      RED,
      CRIMSON,
      BEIGE,
      BROWN,
      PEACH,
      PINK,
      WHITE,
   };

   cout << "Here are the available colors: " << endl;
   cout << "Violet: " << VIOLET << endl;
   cout << "Indigo: " << INDIGO << endl;
   cout << "Blue: " << BLUE << endl;
   cout << "Green: " << GREEN << endl;
   cout << "Yellow: " << YELLOW << endl;
   cout << "Orange: " << ORANGE << endl;
   cout << "RED: " << RED << endl;
   cout << "Crimson: " << CRIMSON << endl;
   cout << "Beige: " << BEIGE << endl;
   cout << "Brown: " << BROWN << endl;
   cout << "Peach: " << PEACH << endl;
   cout << "Pink: " << PINK << endl;
   cout << "White: " << WHITE << endl;

   cout << "Choose one by entering code: ";
   int YourChoice = BLUE; // initial
   cin >> YourChoice;

   switch (YourChoice)
   {
   case VIOLET:
   case INDIGO:
   case BLUE:
   case GREEN:
   case YELLOW:
   case ORANGE:
   case RED:
      cout << "Bingo, your choice is a Rainbow color!" << endl;
      break;

   default:
      cout << "The color you chose is not in the rainbow" << endl;
      break;
   }

   return 0;
}