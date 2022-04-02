
#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int iNum = 0;
	while (cin >> iNum) {//此处ctrl+z可以退出才行
		queue<int> q;
		if (iNum <= 1)
		{
			iNum = 1;
		}
		else if (iNum >= 1000)
		{
			iNum = 1000;
		}

		for (int i = 0; i < iNum; i++)
		{
			q.push(i);
		}

		int index = 0;

		while (q.size() > 1)
		{
			if (2 == index)
			{
				q.pop();
				index = 0;
			}
			else
			{
				int temp = q.front();
				q.push(temp);
				q.pop();
				index++;
			}
		}

		//if (q.size() == 1)
		{
			int temp = q.front();
			cout << temp << endl;
			q.pop();

		}
	}

	return 0;
}



/*
//双端队列实现
#include <iostream>
#include <queue>

using namespace std;
int main()
{
	int iLen = 0;
	while (cin>>iLen)
	{
		if (iLen<1)
		{
			iLen = 1;
		}
		else if (iLen>1000)
		{
			iLen = 1000;
		}

		queue<int> q;
		for (int i = 0; i<iLen; i++)
		{
			q.push(i);
		}

		int Cont = 0;
		while (q.size()>1)
		{
			if (Cont == 2)
			{
				q.pop();
				Cont = 0;
			}
			else
			{
				int iTemp = q.front();
				q.pop();
				q.push(iTemp);
				Cont++;
			}
		}

		int iTemp = q.front();
		q.pop();
		cout << iTemp << endl;

	}
}


//
//
////普通数组模拟
//
//#include <iostream>
//#include <string>
//using namespace std;
//
//int  main()
//{
//	int iLen = 0;
//	char ccstr[5];
//	cin.getline(ccstr, 5);
//	iLen = atoi(ccstr);
//	int *iArray = new int[iLen];
//	for (int i = 0; i < iLen; i++)
//	{
//		iArray[i] = i;
//	}
//	int iCurPos = 0;
//	int CurLen = iLen;
//	for (int i = 0; CurLen > 0; iCurPos++, i++)
//	{
//		if (CurLen == 1)
//		{
//			i = 0;
//			cout << iArray[i];
//			iArray[i] = -1;
//			CurLen--;
//			iCurPos = 0;
//			break;
//		}
//		if (i >= CurLen)
//		{
//			i = 0;
//		}
//
//		if (2 == iCurPos)
//		{
//			for (int j = i; j < CurLen; j++)
//			{
//				if (j + 1 < CurLen)
//				{
//					iArray[j] = iArray[j + 1];
//				}
//				else {
//					iArray[j] = -1;
//				}
//			}
//			//开始的时候并没有考虑到这种情况
//			if(iCurPos == CurLen-1)
//			{
//				i = 0;
//			}
//			--CurLen;
//			iCurPos = 0;
//		}
//	}
//
//	delete[]iArray;
//	iArray = NULL;
//}
*/