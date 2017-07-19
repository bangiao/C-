#pragma once

class _Tag_Array
{
public:
	_Tag_Array(int Length);
	_Tag_Array(const _Tag_Array &obj);
	~_Tag_Array();
	void setData(int Index, int Value);
	int getData(int Index);
	int getLength();
protected:
private:
	int *m_Data;
	int m_Length;
};