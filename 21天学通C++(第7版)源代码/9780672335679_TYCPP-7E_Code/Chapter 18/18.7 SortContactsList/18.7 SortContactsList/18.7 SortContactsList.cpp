#include <list>
#include <string>
#include <iostream>
using namespace std;

template <typename T>
void DisplayContents (const T& Input)
{
   for(auto iElement = Input.cbegin() // auto, cbegin and cend: c++11 
     ; iElement != Input.cend()
     ; ++ iElement )
     cout << *iElement << endl;

   cout << endl;
}

struct ContactItem
{
   string strContactsName;
   string strPhoneNumber; 
   string strDisplayRepresentation;

   // Constructor and destructor
   ContactItem (const string& strName, const string & strNumber)
   {
      strContactsName = strName;
      strPhoneNumber = strNumber;
      strDisplayRepresentation = (strContactsName + ": " + strPhoneNumber);
   }

   // used by list::remove() given contact list item
   bool operator == (const ContactItem& itemToCompare) const
   {
      return (itemToCompare.strContactsName == this->strContactsName);
   }

   // used by list::sort() without parameters
   bool operator < (const ContactItem& itemToCompare) const
   {
      return (this->strContactsName < itemToCompare.strContactsName);
   }

   // Used in DisplayContents via cout
   operator const char*() const
   {
     return strDisplayRepresentation.c_str();
   }
};

bool SortOnPhoneNumber (const ContactItem& item1, 
                           const ContactItem& item2)
{
   return (item1.strPhoneNumber < item2.strPhoneNumber);
}

int main ()
{
   list <ContactItem> Contacts;
   Contacts.push_back(ContactItem("Jack Welsch", "+1 7889 879 879"));
   Contacts.push_back(ContactItem("Bill Gates", "+1 97 7897 8799 8"));
   Contacts.push_back(ContactItem("Angela Merkel", "+49 23456 5466"));
   Contacts.push_back(ContactItem("Vladimir Putin", "+7 6645 4564 797"));
   Contacts.push_back(ContactItem("Manmohan Singh", "+91 234 4564 789"));
   Contacts.push_back(ContactItem("Barack Obama", "+1 745 641 314"));

   cout << "List in initial order: " << endl;
   DisplayContents(Contacts);

   Contacts.sort();
   cout << "After sorting in alphabetical order via operator<:" << endl;
   DisplayContents(Contacts);

   Contacts.sort(SortOnPhoneNumber);
   cout << "After sorting in order of phone numbers via predicate:" << endl;
   DisplayContents(Contacts);

   cout << "After erasing Putin from the list: ";
   Contacts.remove(ContactItem("Vladimir Putin", ""));
   DisplayContents(Contacts);

   return 0;
}