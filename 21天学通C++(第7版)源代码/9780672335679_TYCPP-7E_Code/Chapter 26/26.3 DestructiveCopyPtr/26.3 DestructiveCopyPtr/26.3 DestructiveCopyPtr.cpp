template <typename T>
class destructivecopy_pointer
{
private:
   T* pObject;
public:
	destructivecopy_pointer(T* pInput):pObject(pInput) {}
	~destructivecopy_pointer() { delete pObject; }

   // copy constructor
   destructivecopy_pointer(destructivecopy_pointer& source)
   {
      // Take ownership on copy
      pObject = source.pObject;

      // destroy source
      source.pObject = 0;
   }

   // assignment operator
   destructivecopy_pointer& operator= (destructivecopy_pointer& rhs)
   {
      if (pObject != source.pObject)
      {
         delete pObject;
         pObject = source.pObject;
         source.pObject = 0;
      }
   }
};

int main()
{
   destructivecopy_pointer<int> pNumber (new int);
   destructivecopy_pointer<int> pCopy = pNumber;

   // pNumber is now invalid 
   return 0;
}