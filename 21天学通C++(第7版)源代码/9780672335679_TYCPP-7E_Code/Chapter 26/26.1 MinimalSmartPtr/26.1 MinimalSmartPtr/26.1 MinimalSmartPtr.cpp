template <typename T>
class smart_pointer
{
private:
    T* m_pRawPointer;
public:
    smart_pointer (T* pData) : m_pRawPointer (pData) {}    // constructor
    ~smart_pointer () {delete pData;};                    // destructor

    // copy constructor
    smart_pointer (const smart_pointer & anotherSP);
    // copy assignment operator
    smart_pointer& operator= (const smart_pointer& anotherSP);    

    T& operator* () const        // dereferencing operator
    {
        return *(m_pRawPointer);
    }

    T* operator-> () const        // member selection operator
    {
        return m_pRawPointer;
    }
};

// empty stub to enable compilation
int main()
{
	return 0;
}