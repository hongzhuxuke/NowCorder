/*
BM17 二分查找-I
给定一个 元素升序的、无重复数字的整型数组 nums 和一个目标值 target ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标（下标从 0 开始），否则返回 -1

数据范围：0 \le len(nums) \le 2\times10^50≤len(nums)≤2×10
5
  ， 数组中任意值满足 |val| \le 10^9∣val∣≤10
9

进阶：时间复杂度 O(\log n)O(logn) ，空间复杂度 O(1)O(1)

示例1
输入：
[-1,0,3,4,6,10,13,14],13
复制
返回值：
6
复制
说明：
13 出现在nums中并且下标为 6
示例2
输入：
[],3
复制
返回值：
-1
复制
说明：
nums为空，返回-1
示例3
输入：
[-1,0,3,4,6,10,13,14],2
复制
返回值：
-1
复制
说明：
2 不存在nums中因此返回 -1
*/
#include <iostream>
#include <concurrent_priority_queue.h>
#include <queue>
using namespace std;
class Solution {
public:

	int search(vector<int>& nums, int target) {
		return search(nums, 0, nums.size() - 1, target);
	}

	int search(vector<int>& nums, int s, int e, int t)
	{
		int iR = -1;
		if (s < 0 || e < 0 || s >= nums.size() || e >= nums.size())
		{
			iR = -1;
		}
		else if (s == e && nums[s] != t)
		{
			iR = -1;
		}
		else if (e - s == 1)//开始没考虑到数组中就俩数会死循环
		{
			if (nums[s] == t) iR = s;
			else if (nums[e] == t) iR = e;
			else iR = -1;
		}
		else
		{
			int iM = (s + e) / 2;
			if (nums[iM] == t) iR = iM;
			else if (nums[iM] > t) iR = search(nums, s, iM, t);
			else
			{
				iR = search(nums, iM, e, t);
			}
		}
		return iR;
	}
};

int main()
{
	vector< vector<int>> v;
	v.push_back({2,3,4,7});

	priority_queue<int,vector<int>, greater<int>> iq;
	iq.push(2);
	iq.push(3);
	iq.push(5);
	iq.push(4);
	iq.push(1);

    std::cout << "Hello World!\n";
}

