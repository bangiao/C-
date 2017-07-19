#include <iostream>
using namespace std;

class MyString
{
private:
   char* Buffer;

public:
   // constructor
   MyString(const char* InitialInput)
   {
      cout << "Default constructor: creating new MyString" << endl;
      if(InitialInput != NULL)
      {
         Buffer = new char [strlen(InitialInput) + 1];
         strcpy(Buffer, InitialInput);

         // Display memory address pointed by local buffer
         cout << "Buffer points to: 0x" << hex;
         cout << (unsigned int*)Buffer << endl;
      }
      else 
         Buffer = NULL;
   }

   // Copy constructor
   MyString(const MyString& CopySource)
   {
      cout << "Copy constructor: copying from MyString" << endl;

      if(CopySource.Buffer != NULL)
      {
         // ensure deep copy by first allocating own buffer 
         Buffer = new char [strlen(CopySource.Buffer) + 1];

         // copy from the source into local buffer
         strcpy(Buffer, CopySource.Buffer);

         // Display memory address pointed by local buffer
         cout << "Buffer points to: 0x" << hex;
         cout << (unsigned int*)Buffer << endl;
      }
      else 
         Buffer = NULL;
   }
   
   // Destructor
   ~MyString()
   {
      cout << "Invoking destructor, clearing up" << endl;
      if (Buffer != NULL)
         delete [] Buffer;
   }

   int GetLength() 
   {
      return strlen(Buffer);
   }

   const char* GetString()
   {
      return Buffer;
   }
};

void UseMyString(MyString Input)
{
   cout << "String buffer in MyString is " << Input.GetLength();
   cout << " characters long" << endl;

   cout << "Buffer contains: " << Input.GetString() << endl;
   return;
}

int main()
{
   MyString SayHello("Hello from String Class");

   // Pass SayHello by value (will be copied)
   UseMyString(SayHello);

   return 0;
}