/*某商店规定：三个空汽水瓶可以换一瓶汽水，允许向老板借空汽水瓶（但是必须要归还）。
小张手上有n个空汽水瓶，她想知道自己最多可以喝到多少瓶汽水。
数据范围：输入的正整数满足  1<=n<=100

注意：本题存在多组输入。输入的 0 表示输入结束，并不用输出结果。
*/

#if 1

#include <iostream>
using namespace  std;

//通过数学分析，最后获得的饮料数是总空瓶数整除2 。
int main()
{
	int iN = 0;
	while (scanf_s("%d", &iN) && iN>0)
	{
		printf("%d\n", iN / 2);
	}
	return 0;
}


#else
#include <iostream>
using namespace std;
int main()
{
	int iNum;
	char strNum[5];
	while (true)
	{
		cin.getline(strNum, 5);
		iNum = atoi(strNum);
		if (iNum <= 1)
		{
			iNum = 1;
		}
		else if (iNum >= 100)
		{
			iNum = 100;
		}

		int iNewN = 0;
		while (iNum >= 2)
		{
			if (2 == iNum)
			{
				iNewN += 1;
				break;
			}
			else if (iNum < 2)
			{
				break;
			}
			else
			{
				int iNewTemp = (iNum / 3);
				iNewN += iNewTemp;
				iNum %= 3;
				iNum += iNewTemp;
			}
		}
		std::cout << iNewN << std::endl;
	}
	return 0;
}
#endif
