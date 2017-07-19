#include<iostream>
using namespace std;

class Shape
{
public:
   virtual double Area() = 0;
   virtual void Print() = 0;
};

class Circle
{
   double Radius;
public:
   Circle(double inputRadius) : Radius(inputRadius) {}

   double Area()
   {
      return 3.1415 * Radius * Radius;
   }
   
   void Print()
   {
      cout << "Circle says hello!" << endl;
   }
};

class Triangle
{
   double Base, Height;
public:
   Triangle(double inputBase, double inputHeight) : Base(inputBase), Height(inputHeight) {}

   double Area()
   {
      return 0.5 * Base * Height;
   }
   
   void Print()
   {
      cout << "Triangle says hello!" << endl;
   }
};

int main()
{
   Circle myRing(5);
   Triangle myWarningTriangle(6.6, 2);

   cout << "Area of circle: " << myRing.Area() << endl; 
   cout << "Area of triangle: " << myWarningTriangle.Area() << endl; 

   myRing.Print();
   myWarningTriangle.Print();

   return 0;
}
