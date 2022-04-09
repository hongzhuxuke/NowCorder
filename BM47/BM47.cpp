/*
BM47 寻找第K大
描述
有一个整数数组，请你根据快速排序的思路，找出数组中第 k 大的数。

给定一个整数数组 a ,同时给定它的大小n和要找的 k ，请返回第 k 大的数(包括重复的元素，不用去重)，保证答案存在。
要求：时间复杂度 O(nlogn)O(nlogn)，空间复杂度 O(1)O(1)
数据范围：0\le n \le 10^50≤n≤10
5
 ， 1 \le K \le n1≤K≤n，数组中每个元素满足 0 \le val \le 100000000≤val≤10000000
示例1
输入：
[1,3,5,2,2],5,3
复制
返回值：
2
复制
示例2
输入：
[10,10,9,9,8,7,5,6,4,3,4,2],12,3
复制
返回值：
9
复制
说明：
去重后的第3大是8，但本题要求包含重复的元素，不用去重，所以输出9
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int findKth(vector<int> a, int n, int K) {
		// write code here
		quicksort(a, 0, n - 1, K);
		return a[K - 1];
	}
private:

	int quicksort(vector<int>&a, int s, int e, int k)
	{
		while (true)
		{
			int i = s;
			int j = e;

			int index = i + rand() % (j - i + 1);
			swap(a[index], a[e]);//随机挑选一个数字作为划分依据。以免出现复杂度过高的情况，不然40亿条数据堆栈崩溃

			int temp = a[s];

			while (i < j)
			{
				while (i < j&& a[j] <= temp)
				{
					j--;
				}
				a[i] = a[j];
				while (i < j && a[i] >= temp)
				{
					i++;
				}
				a[j] = a[i];
			}

			a[j] = temp;

			if (k == j + 1) return a[j];
			else if (j + 1 > k)
			{
				e = j - 1;
				//return quicksort(a, s, j - 1, k); 
			}
			else
			{
				s = j + 1;
				//quicksort(a, j + 1, e, k);
			}
		}

	}
};
//
//class Solution {
//public:
//	int findKth(vector<int> a, int n, int K) {
//		// write code here
//		quicksort(a, 0, n - 1, K);
//		return a[K-1];
//	}
//private:
//
//	int quicksort(vector<int>&a, int s, int e, int k)
//	{
//		int i = s;
//		int j = e;
//		int temp = a[s];
//		while (i < j)
//		{
//			while (i < j&& a[j] <= temp)
//			{
//				j--;
//			}
//			a[i] = a[j];
//			while (i < j && a[i] >= temp)
//			{
//				i++;
//			}
//			a[j] = a[i];
//		}
//
//		a[j] = temp;
//
//		if (k == j + 1) return a[j];
//		else if (j + 1 > k) return quicksort(a, s, j - 1, k); 
//		else return quicksort(a, j + 1, e, k);
//	}
//};

int main()
{
	Solution  sl;
	vector<int> iV;

	iV.push_back(10);
	iV.push_back(10);
	iV.push_back(9);
	iV.push_back(9);
	iV.push_back(8);
	iV.push_back(7);
	iV.push_back(5);
	iV.push_back(6);
	iV.push_back(4);
	iV.push_back(3);
	iV.push_back(4);
	iV.push_back(2);
	int a = sl.findKth(iV, 12, 3);
	a = 0;
}
