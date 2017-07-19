#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>
using namespace std;

class Doctor
{
public:
	void Treat_eye()
	{
		cout << "医生 治疗 眼科" << endl;
	}
	void Treat_nose()
	{
		cout << "医生 治疗 鼻科" << endl;
	}
};

class AbsCommand
{
public:
	virtual void Treat() = 0;
protected:
	Doctor *_doctor;
};

class CommndTreatEye : public AbsCommand
{
public:
	CommndTreatEye(Doctor *doctor)
	{
		_doctor = doctor;
	}
	virtual void Treat()
	{
		_doctor->Treat_eye();
	}
};

class CommndTreatNose : public AbsCommand
{
public:
	CommndTreatNose(Doctor *doctor)
	{
		_doctor = doctor;
	}
	virtual void Treat()
	{
		_doctor->Treat_nose();
	}
};

class BeautifulNorse
{
public:
	BeautifulNorse(AbsCommand *commnd)
	{
		_command = commnd;
	}
	void SubmittedCase() //提交病例 下单命令
	{
		_command->Treat();
	}
private:
	AbsCommand *_command;
};

class HeadNorse
{
public:
	HeadNorse()

	{
		_list.clear();
	}
	void setCommand(AbsCommand *commnd)
	{
		_list.push_back(commnd);
	}
	void SubmittedCase() //提交病例 下单命令
	{
		for (list<AbsCommand *>::iterator it = _list.begin(); _list.end() != it; it++)
		{
			(*it)->Treat();
		}
	}
protected:
private:
	list<AbsCommand *> _list;
};

int main(int argc, char *argv[])
{
	int ret = 0;
	
	Doctor *doctor = NULL;
	BeautifulNorse *BeauNorse = NULL;
	AbsCommand *pComBase = NULL;
	AbsCommand *pComBase1 = NULL;
	HeadNorse *headNorse = NULL;

	doctor = new Doctor;
	pComBase = new CommndTreatEye(doctor);
	BeauNorse = new BeautifulNorse(pComBase);

	BeauNorse->SubmittedCase();

	delete BeauNorse;
	BeauNorse = NULL;
	delete pComBase;
	pComBase = NULL;
	delete doctor;
	doctor = NULL;

	puts("advNorse:");
	doctor = new Doctor;
	pComBase = new CommndTreatNose(doctor);
	pComBase1 = new CommndTreatEye(doctor);
	headNorse = new HeadNorse();
	headNorse->setCommand(pComBase);
	headNorse->setCommand(pComBase1);

	headNorse->SubmittedCase();

	delete headNorse;
	headNorse = NULL;
	delete pComBase;
	pComBase = NULL;
	delete doctor;
	doctor = NULL;



	system("pause");
	return ret;
}