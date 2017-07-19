#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "SeqList.cpp"
using namespace std;

class Teahcer
{
public:
	int age;
};

int mainOP()
{
	int ret = 0;
	Teahcer t1, t2, t3, t4, t5;

	t1.age = 11;
	t2.age = 22;
	t3.age = 33;
	t4.age = 44;
	t5.age = 55;

	SeqList<Teahcer> s(10);
	s.insert(t1, 0);
	s.insert(t2, 0);
	s.insert(t3, 0);
	s.insert(t4, 0);
	s.insert(t5, 0);

	cout << "len:" << s.getLen() << endl;
	cout << "Capacity:" << s.getCapacity() << endl;

	Teahcer tmp;

	for (int i = 0; i < 5; i++)
	{
		s.get(i, tmp);
		cout << tmp.age << endl;
	}
	

	while (s.getLen() > 0)
	{
		s.del(0, tmp);
		cout << tmp.age << endl;
	}

	cout << "len:" << s.getLen() << endl;

	return ret;
}

int mainOP1()
{
	int ret = 0;
	Teahcer t1, t2, t3, t4, t5;
	Teahcer *p1, *p2, *p3, *p4, *p5;

	t1.age = 11;
	t2.age = 22;
	t3.age = 33;
	t4.age = 44;
	t5.age = 55;

	p1 = &t1;
	p2 = &t2;
	p3 = &t3;
	p4 = &t4;
	p5 = &t5;

	SeqList<Teahcer *> s(10);
	s.insert(p1, 0);
	s.insert(p2, 0);
	s.insert(p3, 0);
	s.insert(p4, 0);
	s.insert(p5, 0);


// 	SeqList<Teahcer *> s(10);
// 	s.insert(&t1, 0);
// 	s.insert(&t2, 0);
// 	s.insert(&t3, 0);
// 	s.insert(&t4, 0);
// 	s.insert(&t5, 0);

	cout << "len:" << s.getLen() << endl;
	cout << "Capacity:" << s.getCapacity() << endl;

	Teahcer *tmp = NULL;

	for (int i = 0; i < 5; i++)
	{
		s.get(i, tmp);
		cout << tmp->age << endl;
	}


	while (s.getLen() > 0)
	{
		s.del(0, tmp);
		cout << tmp->age << endl;
	}

	cout << "len:" << s.getLen() << endl;

	return ret;
}

int main(int argc, char *argv[])
{
	int ret = 0;
	
	mainOP();
	system("pause");
	return ret;
}