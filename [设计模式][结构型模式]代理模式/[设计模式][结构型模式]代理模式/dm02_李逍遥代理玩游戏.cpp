#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class PlayGame
{
public:
	virtual void Play() = 0;
};

class RealPlay : public PlayGame
{
public:
	virtual void Play()
	{
		cout << "真实玩家玩游戏" << endl;
	}
};

class ProxyPlay : public PlayGame
{
public:
	virtual void Play()
	{
		cout << "代理玩家玩游戏" << endl;
		real.Play();
	}
protected:
private:
	RealPlay real;
};

int main(int argc, char *argv[])
{
	int ret = 0;
	PlayGame *playBase = NULL;

	playBase = new ProxyPlay;

	playBase->Play();

	delete playBase;
	
	system("pause");
	return ret;
}