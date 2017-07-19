#include <iostream>
using namespace std;

void Area (double Radius, double &Area, double &Circumference)
{
   Area = 3.14 * Radius * Radius;
   Circumference = 2 * 3.14 * Radius;
}

int main()
{
	return 0;
}