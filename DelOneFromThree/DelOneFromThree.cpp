// DelOneFromThree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
using namespace std;

//有一个数组 a[N] 顺序存放 0 ~N - 1 ，要求每隔两个数删掉一个数，到末尾时循环至开头继续进行，求最后一个被删掉的数的原始下标位置。以 8 个数(N = 7) 为例 :｛ 0，1，2，3，4，5，6，7 ｝，0 -> 1 -> 2 (删除) -> 3 -> 4 -> 5 (删除) -> 6 -> 7 -> 0 (删除), 如此循环直到最后一个数被删除。
//数据范围： 1<= n <= 1000

void BuildArray(int iArray[],int iLen);

void DelNum(int iArray[], int iLen);

int main()
{
	int iLen = 0;
	//char cLen = getchar();
	//string strLen(&cLen);
	string strLen;
	cin >> strLen;
	iLen = atoi(strLen.c_str());
	int *iArray = new int[iLen];

	BuildArray(iArray, iLen);
	DelNum(iArray, iLen);

	delete []iArray;
	iArray = NULL;
    std::cout << "Hello World!\n";
}

void BuildArray(int iArray[], int iLen)
{
	for (int i = 0; i<iLen; i++)
	{
		iArray[i] = i;
	}
}

void DelNum(int iArray[], int iLen)
{
	int iCount = 0;
	int iCurLen = iLen;
	for (int i = 0; iCurLen>0; iCount++,i++)
	{
		if (iCurLen==1)
		{
			std::cout << iArray[0] << endl;
			iArray[0] = -1;
			iCurLen--;
			iCount = 0;
		}
		if (i >= iCurLen)
		{
			i = 0;
		}

		if (2==iCount)
		{
			for (int j = i; j< iCurLen;j++)
			{
				if (j+1<iCurLen)
				{
					iArray[j] = iArray[j + 1];
				}
				else
				{
					iArray[j] = -1;
				}
			}
			iCount = 0;
			--iCurLen;
			--i;
		}
	}
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
