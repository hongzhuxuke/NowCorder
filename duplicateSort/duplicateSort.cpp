
#if 0

#include <iostream>

using namespace std;
int main()
{
	int iN = 0;
	if (scanf("%d", &iN)) {
		int i = 0;
		int *iArrary = new int[501] {0};
		while (i < iN)
		{
			int iTemp = 0;
			scanf("%d", &iTemp);
			iArrary[iTemp] = iTemp;
			i++;
		}

		for (i = 0; i < 501; i++)
		{
			if (iArrary[i] > 0)
				printf("%d\n", iArrary[i]);
		}

		delete[]iArrary;
	}

	return 0;
}

#else

#include <iostream>
using namespace std;
void CountSort(int iArray[], int iStart, int iLen)
{
	int *iArrayTemp = new int[100]{ 0 };
	int bitNum = 100;
	//此处第一次并未考虑100 以内的数据
	if(iArray[iStart]>100)
		bitNum  = iArray[iStart] / 100 * 100;

	for (int i = iStart; i < iLen; i++)
	{
		int iTemp = iArray[i] % bitNum;
		iArrayTemp[iTemp] = iArray[i];
	}

	//此处第一次并没有考虑iArrayTemp和iArray存放数组坐标不一致问题
	int iCur = 0;
	for (int i = 0; i<100; i++)
	{
		if (iArrayTemp[i]>0)
		{
			iArray[iStart+iCur++] = iArrayTemp[i];
		}
	}
	for (int i = iStart + iCur; i < iLen; i++)
	{
		iArray[i] = 0;
	}
	delete[]iArrayTemp;
}
void buckSort(int iArray[], int iLen)
{
	int* iTempArray = new int[iLen] {0};
	int *iCount = new int[6]{ 0 };
	for (int i = 0; i < iLen; i++)
	{
		int iTemp = iArray[i] / 100;
		//iTemp %= 10;
		iCount[iTemp]++;
	}

	for (int i = 1; i < 6; i++)
	{
		iCount[i] += iCount[i - 1];
	}

	int iCur = 0;
	for (int i = 0; i < iLen; i++)
	{
		int iTemp = iArray[i] / 100;
		//iTemp %= 10;//此处计算多余了
		if (iTemp > 0)
		{
			iTempArray[iCount[iTemp - 1]++] = iArray[i];
		}
		else
		{
			iTempArray[iCur++] = iArray[i];
		}
	}

	for (int i = 0; i < 6; i++)
	{
		iCount[i] = 0;
	}

	for (int i = 0; i < iLen; i++)
	{
		int iTemp = iArray[i] / 100;
		//iTemp %= 10;
		iCount[iTemp]++;
	}

	for (int i = 1; i < 6; i++)
	{
		iCount[i] += iCount[i - 1];
	}
	for (int i = 0; i < iLen; i++)
	{
		iArray[i] = iTempArray[i];
	}

	CountSort(iArray, 0, iCount[0]);
	for (int i = 0; i < 4; i++)
	{
		CountSort(iArray, iCount[i], iCount[i + 1]);
	}
	delete[]iCount;
	delete[]iTempArray;
}

int main()
{
	int iN = 0;
	scanf_s("%d", &iN);
	int i = 0;
	int *iNumArray = new int[iN];
	while (i < iN)
	{
		scanf_s("%d", &iNumArray[i]);
		i++;
	}
	buckSort(iNumArray, iN);

	for (i = 0; i < iN; i++)
	{
		if (iNumArray[i] > 0)
		{
			printf("%d\n", iNumArray[i]);
		}
	}

	delete[]iNumArray;
	return 0;
}
#endif