// BM47.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

//class Solution {
//public:
//	int findKth(vector<int> a, int n, int K) {
//		// write code here
//		quicksort(a, 0, n - 1, K);
//		return a[n - K];
//	}
//private:
//	void swap(vector<int>&a, int i, int j)
//	{
//		if (i >= 0 && i < a.size() && j >= 0 && j < a.size() && i != j)
//		{
//			int t = a[i];
//			a[i] = a[j];
//			a[j] = t;
//		}
//	}
//
//
//	int quicksort(vector<int>&a, int s, int e, int k)
//	{
//		if (s < 0 || s >= e) return a[0];
//		int i = s;
//		int j = e + 1;
//		while (i <= j)
//		{
//			while (a[++i] < a[s]) if (i == e) break;
//			while (a[--j] > a[s]) if (j == s) break;
//			if (i >= j) break;
//			swap(a, i, j);
//		}
//
//		swap(a, s, j);
//		if (a.size() - k == j) return 0;
//		else if (j < a.size() - k) return quicksort(a, j + 1, e, k);
//		else return quicksort(a, s, j - 1, k);
//
//		return 0;
//	}
//};


class Solution {
public:
	int quickSort(vector<int> a, int s, int e, int K)
	{
		int t = a[s];
		int l = s+1;//左侧指针的开始位置  s+1即可
		int r = e;
		
		while (l < r)
		{
			while (l<=e && a[l] >= t)//前半部分排序的是大于等于的，数组越界考虑
			{
				l++;
			}
			if (l > r) break;
			while (r>s && a[r] < t)//数组越界考虑
			{
				r--;
			}
			if (l > r) break;
			swap(a[l], a[r]);
		}
		a[s] = a[r];
		a[r] = t;

		if (r == K - 1) return a[r];
		else if (r < K - 1)
		{
			return quickSort(a, r + 1, e, K);
		}
		else return quickSort(a, s, r - 1, K);
	}

	int findKth(vector<int> a, int n, int K) {
		return quickSort(a, 0, n - 1, K);
	}
};

int main()
{
	Solution  sl;
	vector<int> iV;

	iV.push_back(6);
	iV.push_back(6);
	iV.push_back(6);
	iV.push_back(8);
	iV.push_back(9);
	iV.push_back(9);
	iV.push_back(9);
	iV.push_back(12);
	iV.push_back(12);
	iV.push_back(12);
	iV.push_back(14);
	int a = sl.findKth(iV, 94875, 18674);
	a = 0;
}


