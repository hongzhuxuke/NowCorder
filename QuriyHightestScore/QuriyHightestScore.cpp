
/*
老师想知道从某某同学当中，分数最高的是多少，现在请你编程模拟老师的询问。当然，老师有时候需要更新某位同学的成绩.

输入描述:
每组输入第一行是两个正整数N和M（0 < N <= 30000, 0 < M < 5000）, 分别代表学生的数目和操作的数目。
	学生ID编号从1编到N。
	第二行包含N个整数，代表这N个学生的初始成绩，其中第i个数代表ID为i的学生的成绩
	接下来又M行，每一行有一个字符C（只取‘Q’或‘U’），和两个正整数A, B, 当C为'Q'的时候, 表示这是一条询问操作，假设A < B，他询问ID从A到B（包括A, B）的学生当中，成绩最高的是多少
	当C为‘U’的时候，表示这是一条更新操作，要求把ID为A的学生的成绩更改为B。

	注意：输入包括多组测试数据。

	输出描述 :
对于每一次询问操作，在一行里面输出最高成绩.

输入例子1:
5 7
1 2 3 4 5
Q 1 5
U 3 6
Q 3 4
Q 4 5
U 4 5
U 2 9
Q 1 5

输出例子1:
5
6
5
9

输入例子2:
3 2
1 2 3
U 2 8
Q 3 1

输出例子2:
8

*/
#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main()
{
	int iStuN = 0;
	int iOpN = 0;
	while (scanf("%d %d", &iStuN, &iOpN) != EOF)
	{
		getchar();
		int *iStudent = new int[iStuN + 1]{ 0 };
		for (int i = 0; i < iStuN; i++)
		{
			scanf("%d", &iStudent[i]);
			getchar();
		}
		for (int i = 0; i < iOpN; i++)
		{
			char strOp;
			int iStuId;
			int iOpB;
			scanf("%c %d %d", &strOp, &iStuId, &iOpB);
			getchar();

			if ('Q' == strOp)
			{
				int iMax = 0;
				int iS = 0;
				int iE = 0;
				if (iStuId <= iOpB)//开始并没有考虑    学号1（iStuId） > 学号2的情况（iOpB）
				{
					iS = iStuId - 1;
					iE = iOpB;
				}
				else
				{
					iS = iOpB - 1;
					iE = iStuId;
				}

				for (int i = iS; i < iE; i++)
				{
					if (iStudent[i] > iMax)
					{
						iMax = iStudent[i];
					}
				}
				cout << iMax << endl;
			}
			else if ('U' == strOp)
			{
				if (iStuId >= 1 && iStuId <= iStuN)
				{
					iStudent[iStuId - 1] = iOpB;
				}
			}
		}
		delete[]iStudent;
	}

	return 0;
}