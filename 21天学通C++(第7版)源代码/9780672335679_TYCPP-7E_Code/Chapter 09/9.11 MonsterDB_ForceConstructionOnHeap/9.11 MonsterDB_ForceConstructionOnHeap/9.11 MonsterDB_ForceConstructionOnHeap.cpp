#include <iostream>
using namespace std;

class MonsterDB
{
private:
   ~MonsterDB() {};

public:
   static void DestroyInstance(MonsterDB* pInstance)
   {
      // static member can access private destructor
      delete pInstance;
   }

   // ... imagine a few other methods
};

int main()
{
   MonsterDB* pMyDatabase = new MonsterDB();

   // pMyDatabase -> member methods (....);

   // uncomment next line to see compile failure 
   // delete pMyDatabase; // private destructor cannot be invoked

   // use static member to deallocate
   MonsterDB::DestroyInstance(pMyDatabase);

   return 0;
}