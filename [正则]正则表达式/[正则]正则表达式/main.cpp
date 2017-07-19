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


	cout << "找到了" << std::distance(begin, end) << "个邮件地址" << endl;
	for (auto start = begin; start != end; start++)
	{
		smatch match = *start;
		cout << match.str() << endl;
	}
}

// 数据替换
void RegexReplace(const string &src, const string &sPattern, const string &sReplace)
{
	regex searchPattern(sPattern);
	// 第一个参数是需要替换的字符串
	// 第二个参数替换的规则
	// 第三个参数替换成什么内容
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
		printf("是一个邮件地址\n");
	}
	else
	{
		printf("不是一个邮件地址\n");
	}

	regexSearch(src, "\\w*_?\\w*@\\w*(\\.\\w*)+");
	system("pause");
	return 0;
}