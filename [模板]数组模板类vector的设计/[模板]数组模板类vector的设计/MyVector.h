#pragma once
template <typename T>
class MyVector
{
public:
	MyVector(int Size);
	MyVector(const MyVector &obj);
	~MyVector();

	int getLen();

	T &operator[](int Index);
	MyVector &operator=(const MyVector &obj);
private:
	int m_Size;
	T *m_Space;
};
