/*给定一个长度为 n 的数组 nums 和滑动窗口的大小 size ，找出所有滑动窗口里数值的最大值。

例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。

数据范围： 1 \le size \le n \le 100001≤size≤n≤10000，数组中每个元素的值满足 |val| \le 10000∣val∣≤10000
要求：空间复杂度 O(n)O(n)，时间复杂度 O(n)O(n)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public://题目要求 O（n）的复杂度  所以，错误
	static vector<int> maxInWindows(const vector<int>& nums, int size) {
		vector<int> ref;
		//int cur = 0;
		for (int i = 0; i + size - 1 < nums.size(); i++)
		{
			int iMax = nums[i];
			for (int j = 0; j < size; j++)
			{
				if (i + j < nums.size() && iMax < nums[i + j])
					iMax = nums[i + j];
			}
			ref.push_back(iMax); //ref[cur] = iMax; 此处崩溃   cur还不存在
			//cur++;


		}
		return ref;
	}
};

int main()
{
	vector<int> iVe;
	iVe.push_back(10);
	iVe.push_back(2);
	iVe.push_back(3);
	iVe.push_back(1);
	iVe.push_back(4);
	vector<int> v = Solution::maxInWindows(iVe, 3);
	return 0;
}