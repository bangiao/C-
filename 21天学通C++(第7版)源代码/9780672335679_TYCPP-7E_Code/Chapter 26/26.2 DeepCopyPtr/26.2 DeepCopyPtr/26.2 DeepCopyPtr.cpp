template <typename T>
class deepcopy_smart_pointer
{
private:
    T* m_pObject;
public:
    //... other functions

    // copy constructor of the deepcopy pointer
    deepcopy_smart_pointer (const deepcopy_smart_pointer& source)
    {
        // Clone() is virtual: ensures deep copy of Derived class object
        m_pObject = source->Clone ();
    }

	// copy assignment operator
    deepcopy_smart_pointer& operator= (const deepcopy_smart_pointer& source)
	{
		if (m_pObject)
			delete m_pObject;

        m_pObject = source->Clone ();
	}

};

// stub to ensure compilation
int main()
{
	return 0;
}