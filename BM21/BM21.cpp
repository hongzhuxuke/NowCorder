/*
BM21 旋转数组的最小数字
描述
有一个长度为 n 的非降序数组，比如[1,2,3,4,5]，将它进行旋转，即把一个数组最开始的若干个元素搬到数组的末尾，变成一个旋转数组，比如变成了[3,4,5,1,2]，或者[4,5,1,2,3]这样的。请问，给定这样一个旋转数组，求数组中的最小值。

数据范围：1 \le n \le 100001≤n≤10000，数组中任意元素的值: 0 \le val \le 100000≤val≤10000
要求：空间复杂度：O(1)O(1) ，时间复杂度：O(logn)O(logn)
示例1
输入：
[3,4,5,1,2]
复制
返回值：
1
复制
示例2
输入：
[3,100,200,3]
复制
返回值：
3

*/

#include <iostream>

class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		return calsMin(rotateArray, 0, rotateArray.size() - 1);//传入参数计算
	}

	int calsMin(vector<int> v, int s, int e)
	{
		if (s == e)    return v[s];
		else if (s == e - 1) {
			if (v[s] < v[e]) return v[s];
			else return v[e];
		}
		else
		{
			int iM = (s + e) / 2;
			int min1 = calsMin(v, iM, e);//都计算出来   没考虑到    22212的情况
			int min2 = calsMin(v, s, iM - 1);
			if (min1 <= min2) return min1;
			else return min2;
		}

		return 0;
	}
};


int main()
{
    std::cout << "Hello World!\n";
}
