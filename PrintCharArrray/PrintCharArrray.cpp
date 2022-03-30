
//输入一个字符串，求出该字符串包含的字符集合，按照字母输入的顺序输出。
//数据范围：输入的字符串长度满足  ，且只包含大小写字母，区分大小写。
//1<=n<=1000


#if 1
#include <iostream>
using namespace std;
int main()
{
	char* str = new char[101];
	while (cin.getline(str, 100))//scanf("%s", str);
	{
		int *Num = new int[256]{0};
		char tempC;
		int i = 0;
		while (tempC = str[i++])
		{
			
			if (0== Num[tempC]++)
			{
				cout << tempC;
			}
		}  
	}
	delete []str;
	return 0;
}


#else

#include <iostream>
#include <string>
using namespace std;

int main()
{
	char* inputStr = new char[100];
	cin.get(inputStr, 100);
	int *iFlages = new int['z' - 'a' + 1]{ 0 };
	int iCurPos = 0;
	for (int i = 0; i < 100; i++)
	{
		char cTemp = inputStr[i];
		if (cTemp >= 'a' && cTemp <= 'z')
		{
			if (iFlages[cTemp - 'a'] & 1)
			{
				continue;
			}
			iFlages[cTemp - 'a'] |= 1;
		}

		if (cTemp >= 'A' && cTemp <= 'Z')
		{
			if (iFlages[cTemp - 'A'] & 2)
			{
				continue;
			}
			iFlages[cTemp - 'A'] |= 2;
		}
		inputStr[iCurPos++] = inputStr[i];
	}
	inputStr[iCurPos] = '\0';
	cout << inputStr << endl;
	delete[]iFlages;
	delete[]inputStr;
}


#endif
