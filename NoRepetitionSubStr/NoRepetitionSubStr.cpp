#include <iostream>
#include <unordered_set>

using namespace std;
//给定字符串，请找出其中不含有重复字符的最长字串的长度.

int CalSubStrLenth(char arrayStr[], int ilen);


int main()
{
	char arrayStr[] = {'a','b','c','b','d','f','d', '\0'};
	std::cout << CalSubStrLenth(arrayStr, strlen(arrayStr));
	return 0;
}

int CalSubStrLenth(char arrayStr[], int ilen)
{
	unordered_set<char> occ;//滑动数组
	int iCk = -1;
	int max = 0;
	for (int i= 0; i<ilen; i++)
	{
		if (i!=0)
		{
			occ.erase(arrayStr[i-1]);//有重复的 就从第一个位置开始删除
		}

		while (iCk + 1 < ilen && occ.count(arrayStr[iCk+1]) <=0)
		{
			occ.insert(arrayStr[iCk + 1]);//没有重复的就插入滑动数组
			iCk++;
		}

		if (max<occ.size())//有重复的时候，跳出插入，进行计算当前最大值并保存
		{
			max = occ.size();
		}
	}

	return max;
}
