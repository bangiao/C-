#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <regex>
#include <string>
using namespace std;

// \w*_?\w*@\w*(\.\w*)+

bool isMail(const string &src)
{
	regex emailPattern("\\w*_?\\w*@\\w*(\\.\\w*)+");
	return regex_match(src, emailPattern);
}

void regexSearch(const string &src, const string &sPattern)
{
	regex searchPattern(sPattern);

	sregex_iterator begin(src.begin(), src.end(), searchPattern);
	sregex_iterator end;


	cout << "�ҵ���" << std::distance(begin, end) << "���ʼ���ַ" << endl;
	for (auto start = begin; start != end; start++)
	{
		smatch match = *start;
		cout << match.str() << endl;
	}
}

// �����滻
void RegexReplace(const string &src, const string &sPattern, const string &sReplace)
{
	regex searchPattern(sPattern);
	// ��һ����������Ҫ�滻���ַ���
	// �ڶ��������滻�Ĺ���
	// �����������滻��ʲô����
	string newText = regex_replace(src, searchPattern, sReplace);
	cout << newText << endl;

}

int main()
{
	string src = "zhazha@qq.com wangyi@163.com    xxx@gmail.com";
	RegexReplace(src, "zhazha", "kankan");
	cout << src << endl;
	cout << __cplusplus << endl;
	if (isMail("zhazha@163.com"))
	{
		printf("��һ���ʼ���ַ\n");
	}
	else
	{
		printf("����һ���ʼ���ַ\n");
	}

	regexSearch(src, "\\w*_?\\w*@\\w*(\\.\\w*)+");
	system("pause");
	return 0;
}