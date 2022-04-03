/*
BM51 数组中出现次数超过一半的数字
描述
给一个长度为 n 的数组，数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组[1,2,3,2,2,2,5,4,2]。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。

数据范围：n \le 50000n≤50000，数组中元素的值 0 \le val \le 100000≤val≤10000
要求：空间复杂度：O(1)O(1)，时间复杂度 O(n)O(n)
输入描述：
保证数组输入非空，且保证有解
示例1
输入：
[1,2,3,2,2,2,5,4,2]
复制
返回值：
2
复制
示例2
输入：
[3,3,3,3,2,2,2]
复制
返回值：
3
复制
示例3
输入：
[1]
复制
返回值：
1
复制
*/

#include <iostream>


class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		int iRef = 0;
		unordered_map<int, int> um;
		for (int i = 0; i < numbers.size(); i++)
		{
			um[numbers[i]]++;
		}


		unordered_map<int, int>::iterator it = um.begin();//此处忘记初始化it
		while (it != um.end())
		{
			if (it->second > numbers.size() / 2)
			{
				iRef = it->first;
				break;
			}
			it++;
		}
		return iRef;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}
