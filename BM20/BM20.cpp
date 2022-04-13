/*
BM20 数组中的逆序对
描述
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P mod 1000000007

数据范围：  对于 50\%50% 的数据, size\leq 10^4size≤10
4

对于 100\%100% 的数据, size\leq 10^5size≤10
5

数组中所有数字的值满足 0 \le val \le 10000000≤val≤1000000

要求：空间复杂度 O(n)O(n)，时间复杂度 O(nlogn)O(nlogn)
输入描述：
题目保证输入的数组中没有的相同的数字
示例1
输入：
[1,2,3,4,5,6,7,0]
复制
返回值：
7
复制
示例2
输入：
[1,2,3]
复制
返回值：
0

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int InversePairs(vector<int> data) {
		return mergeOrderPair(data, 0, data.size() - 1);
	}

	int mergeOrderPair(vector<int>& data, int left, int right)
	{
		if (left == right) return 0;
		else if (left + 1 == right) {
			if (data.at(left) > data.at(right))
			{
				swap(data[left], data[right]);
				return 1;
			}
			else return 0;
		}
		else
		{
			int i = left;
			int min = (left + right) / 2;
			int j = min + 1;
			int iRef = mergeOrderPair(data, i, min) + mergeOrderPair(data, j, right);
			vector<int> temp;
			temp.resize(right - left + 1);
			int iC = right - left + 1;
			int iL = min;
			int iR = right;

			for (; iL >= left && iR > min; iL--)//此处 用iL和iR
			{
				for (; iL >= left && iR > min; iR--)
				{
					if (data[iL] > data[iR])
					{
						temp[--iC] = data[iL];
						iRef += (iR - min);//注意是iR减去
						break;
					}
					else
					{
						temp[--iC] = data[iR];
					}
				}
			}

			while (iR > min)
			{
				temp[--iC] = data[iR--];
			}

			while (iC <= right - left)
			{
				//data[left+iC] = temp[iC++];//本行先计算“=”号右侧取temp的值，使得iC++后赋值给data的时候，iC已经计算过++操作了
				data[left + iC++] = temp[iC];
			}
			return iRef;
		}


	}
};

int main()
{
    std::cout << "Hello World!\n";
}