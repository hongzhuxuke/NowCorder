// PrintCharArrray.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

//输入一个字符串，求出该字符串包含的字符集合，按照字母输入的顺序输出。
//数据范围：输入的字符串长度满足  ，且只包含大小写字母，区分大小写。
//1<=n<=1000
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
			if (iFlages[cTemp - 'A' ] & 2)
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
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
