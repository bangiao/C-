#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <algorithm>
#include <functional>
#include <list>
#include <set>
#include <string>
#include <vector>


template <class T>
class IsDiv
{
public:
	IsDiv(T a)
	{
		this->a = a;
	}
	bool operator()(const T &a)
	{
		return(a % this->a == 0);
	}
protected:
private:
	T a;
};

void main11()
{
	vector<int> v;

	for (int i = 10; i < 33; i++)
	{
		v.push_back(i);
	}

	int a = 4;
	/*
	template<class _InIt,
	class _Pr> inline
	_InIt find_if(_InIt _First, _InIt _Last, _Pr _Pred)
	{	// find first satisfying _Pred
	_DEBUG_RANGE(_First, _Last);
	_DEBUG_POINTER(_Pred);
	return (_Rechecked(_First,
	_Find_if(_Unchecked(_First), _Unchecked(_Last), _Pred)));
	}
	*/

	/*
	template<class _InIt,
	class _Pr> inline
	_InIt _Find_if(_InIt _First, _InIt _Last, _Pr _Pred)
	{	// find first satisfying _Pred
	for (; _First != _Last; ++_First)
	if (_Pred(*_First))
	break;
	return (_First);
	}
	*/

	/*
	template<class _Myvec> inline
	_Vector_iterator<_Myvec>&
	_Rechecked(_Vector_iterator<_Myvec>& _Iter,
	typename _Vector_iterator<_Myvec>
	::_Unchecked_type _Right)
	{	// convert to checked
	return (_Iter._Rechecked(_Right));
	}
	*/

	/*
	_Myiter& _Rechecked(_Unchecked_type _Right)
	{	// reset from unchecked iterator
	this->_Ptr = _Right;
	return (*this);
	}
	*/
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		it = find_if(it, v.end(), IsDiv<int>(a));
		if (it == v.end())
		{
			cout << "ÕÒ²»µ½" << endl;
		}
		else
		{
			cout << *it << endl;
		}
		it++;
	}
}

int main(int argv, char *args[])
{
	int ret = 0;
	main11();

	system("pause");
	return ret;
}