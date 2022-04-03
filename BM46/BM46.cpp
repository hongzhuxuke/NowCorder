/*BM46 最小的K个数
描述
给定一个长度为 n 的可能有重复值的数组，找出其中不去重的最小的 k 个数。例如数组元素是4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4(任意顺序皆可)。
数据范围：0\le k,n \le 100000≤k,n≤10000，数组中每个数的大小0 \le val \le 10000≤val≤1000
要求：空间复杂度 O(n)O(n) ，时间复杂度 O(nlogn)O(nlogn)

示例1
输入：
[4,5,1,6,2,7,3,8],4
复制
返回值：
[1,2,3,4]
复制
说明：
返回最小的4个数即可，返回[1,3,2,4]也可以
示例2
输入：
[1],0
复制
返回值：
[]
复制
示例3
输入：
[0,1,2,1,2],3
复制
返回值：
[0,1,1]

*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		//int ia[1001]{0};
		vector<int> ref;
		Sort(input, 0, input.size() - 1);
		for (int i = 0; i < k; i++)
			ref.push_back(input[i]);
		return ref;
	}

private:
	void swap(vector<int>& a, int i, int j)//参数类型忘记 引用
	{
		if (i >= 0 && i < a.size() && j >= 0 && j < a.size())
		{
			int iT = a[i];
			a[i] = a[j];
			a[j] = iT;
		}
	}
	void Sort(vector<int>& a, int s, int e)//参数类型忘记 引用
	{
		if (e > s)
		{
			if (e == s + 1)
			{
				if (a[s] > a[e]) swap(a, s, e);
			}
			else
			{
				vector<int> ta;
				Sort(a, s, (s + e) / 2);
				Sort(a, (s + e) / 2 + 1, e);
				int i = s;
				int j = (s + e) / 2 + 1; //开始笔误 写成了   （s+2） +1 ，忘记除以 2了
				while (i <= (s + e) / 2 || j <= e)
				{
					if (i <= (s + e) / 2 && j <= e)
					{
						if (a[i] < a[j]) ta.push_back(a[i++]);
						else ta.push_back(a[j++]);
						continue;
					}

					while (i <= (s + e) / 2) ta.push_back(a[i++]);
					while (j <= e) ta.push_back(a[j++]);
				}

				for (int k = 0; k < ta.size(); k++)
					a[s + k] = ta[k];
			}
		}

	}
};

int main()
{
	return 0;
}