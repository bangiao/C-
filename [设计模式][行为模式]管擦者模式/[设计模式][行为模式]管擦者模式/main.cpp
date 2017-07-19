#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <list>
using namespace std;

class PlayserObserver
{
public:
	void update(string info)
	{
		cout << "快跑, 老板来了, 秘书说: " << info << endl;
	}
};

class Secretary
{
public:
	Secretary()
	{
		_list = new list<PlayserObserver *>;
		_list->clear();
	}
	~Secretary()
	{
		delete _list;
	}
	void setPlayserObserver(PlayserObserver *node)
	{
		_list->push_back(node);
	}
	void Notify(string info)
	{
		for (list<PlayserObserver *>::iterator it = _list->begin(); _list->end() != it; it++)
		{
			(*it)->update(info);
		}
	}
protected:
private:
	list<PlayserObserver *> *_list;
};

int main(int argc, char *argv[])
{
	int ret = 0;
	Secretary *secretary = NULL;
	PlayserObserver *playserobserver1 = NULL;
	PlayserObserver *playserobserver2 = NULL;

	secretary = new Secretary;
	playserobserver1 = new PlayserObserver;
	playserobserver2 = new PlayserObserver;

	secretary->setPlayserObserver(playserobserver1);
	secretary->setPlayserObserver(playserobserver2);

	secretary->Notify("经理来了, 不要玩游戏了");

	delete playserobserver2;
	delete playserobserver1;
	delete secretary;
	system("pause");
	return ret;
}