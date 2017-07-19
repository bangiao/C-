#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <vector>
using namespace std;

typedef struct pointTag 
{
	int x;
	int y;
	pointTag(){}
	pointTag(int a, int b)
	{
		x = a;
		y = b;
	}

	bool operator<(const pointTag &other) const
	{
		if (x < other.x)
		{
			return true;
		}
		else if (x == other.x)
		{
			return y < other.y;
		}
		return false;
	}
}POINT;

typedef enum PiceColorTag
{
	BLACK,
	WHITE
}PIECECOLOR;

class CPiece
{
public:
	CPiece(PIECECOLOR color) : m_color(color)
	{

	}
	PIECECOLOR GetColor()
	{
		return m_color;
	}

	void SetPoint(POINT point)
	{
		m_point = point;
	}
	POINT getPoint()
	{
		return m_point;
	}
protected:
	PIECECOLOR m_color;
	POINT m_point;
private:
};

class CGmoku : public CPiece
{
public:
	CGmoku(PIECECOLOR color) : CPiece(color)
	{

	}
};

class CPieceFactory
{
public:
	CPiece *GetPiece(PIECECOLOR color)
	{
		CPiece *pPiece = NULL;
		if (m_vecPiece.empty())
		{
			pPiece = new CGmoku(color);
			m_vecPiece.push_back(pPiece);
		}
		else
		{
			for (vector<CPiece *>::iterator it = m_vecPiece.begin(); it != m_vecPiece.end(); it++)
			{
				if ((*it)->GetColor() == color)
				{
					pPiece = *it;
					break;
				}
			}
			if (NULL == pPiece)
			{
				pPiece = new CGmoku(color);
				m_vecPiece.push_back(pPiece);
			}
		}
		return pPiece;
	}
	~CPieceFactory()
	{
		for (vector<CPiece *>::iterator it = m_vecPiece.begin(); it != m_vecPiece.end(); ++it)
		{
			if (NULL != *it)
			{
				delete *it;
				*it = NULL;
			}
		}
	}
private:
	vector<CPiece *> m_vecPiece;
};

class CChessborad
{
public:
	void Draw(CPiece *piece)
	{
		if (piece->GetColor())
		{
			cout << "Draw a White" << "at(" << piece->getPoint().x << piece->getPoint().y << ")" << endl;
		}
		else
		{
			cout << "Draw a Black" << "at(" << piece->getPoint().x << piece->getPoint().y << ")" << endl;
		}
		m_mapPieces.insert(pair<POINT, CPiece *>(piece->getPoint(), piece));
	}
	void ShowAllPieces()
	{
		for (map<POINT, CPiece *>::iterator it = m_mapPieces.begin(); it != m_mapPieces.end(); ++it)
		{
			if (it->second->GetColor())
			{
				cout << "(" << it->first.x << "," << it->first.y << ") has a White chese." << endl;
			}
			else
			{
				cout << "(" << it->first.x << "," << it->first.y << ") has a Black chese." << endl;
			}
		}
	}
protected:
private:
	map<POINT, CPiece *> m_mapPieces;
};


int main(int argc, char *argv[])
{
	int ret = 0;
	CPieceFactory *pPieseFactory = new CPieceFactory();
	CChessborad *pCheseborad = new CChessborad();

	CPiece *pPiese = pPieseFactory->GetPiece(WHITE);
	pPiese->SetPoint(POINT(2, 3));
	pCheseborad->Draw(pPiese);
	
	pPiese = pPieseFactory->GetPiece(BLACK);
	pPiese->SetPoint(POINT(4, 5));
	pCheseborad->Draw(pPiese);

	pPiese = pPieseFactory->GetPiece(WHITE);
	pPiese->SetPoint(POINT(2, 4));
	pCheseborad->Draw(pPiese);

	pPiese = pPieseFactory->GetPiece(BLACK);
	pPiese->SetPoint(POINT(3, 5));
	pCheseborad->Draw(pPiese);

	cout << "Show all chese" << endl;

	pCheseborad->ShowAllPieces();

	if (NULL != pCheseborad)
	{
		delete pCheseborad;
		pCheseborad = NULL;
	}
	if (NULL != pPieseFactory)
	{
		delete pPieseFactory;
		pPieseFactory = NULL;
	}

	system("pause");
	return ret;
}