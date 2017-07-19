#include <string>
#include <iostream>

int main ()
{
   using namespace std;

   string strSample ("Good day String! Today is beautiful!");
   cout << "The sample string is: " << endl;
   cout << strSample << endl << endl;

   // Find substring "day" in it...
   size_t charPos = strSample.find ("day", 0);

   // Check if the substring was found...
   if (charPos != string::npos)
      cout << "First instance of \"day\" was found at position " << charPos;
   else
      cout << "Substring not found." << endl;

   cout << endl << endl;

   cout << "Locating all instances of substring \"day\"" << endl;
   size_t SubstringPos = strSample.find ("day", 0);

   while (SubstringPos != string::npos)
   {
      cout << "\"day\" found at position " << SubstringPos << endl;

      // Make the 'find' function search forward from the next character onwards
      size_t nSearchPosition = SubstringPos + 1;

      SubstringPos = strSample.find ("day", nSearchPosition);
   }

   cout << endl;

   cout << "Locating all instances of character 'a'" << endl;
   const char charToSearch = 'a';
   charPos = strSample.find (charToSearch, 0);

   while (charPos != string::npos)
   {
      cout << "'" << charToSearch << "' found";
      cout << " at position: " << charPos << endl;

      // Make the 'find' function search forward from the next character onwards
      size_t charSearchPos = charPos + 1;

      charPos = strSample.find (charToSearch, charSearchPos);
   }   

   return 0; 
}
