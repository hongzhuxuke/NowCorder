// BM47.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

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
			swap(a[index], a[e]);//随机挑选一个数字作为划分依据。以免出现复杂度过高的情况

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
