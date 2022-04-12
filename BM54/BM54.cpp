/*
BM54 三数之和
描述
给出一个有n个元素的数组S，S中是否有元素a,b,c满足a+b+c=0？找出数组S中所有满足条件的三元组。

数据范围：0 \le n \le 30000≤n≤3000，数组中各个元素值满足 |val | \le 100∣val∣≤100
空间复杂度：O(n^2)O(n
2
 )，时间复杂度 O(n^2)O(n
2
 )

注意：
三元组（a、b、c）中的元素可以按任意顺序排列。
解集中不能包含重复的三元组。
示例1
输入：
[-10,0,10,20,-10,-40]
复制
返回值：
[[-10,-10,20],[-10,0,10]]
复制
示例2
输入：
[-2,0,1,1,2]
复制
返回值：
[[-2,0,2],[-2,1,1]]
复制
示例3
输入：
[0,0]
复制
返回值：
[]
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int> > threeSum(vector<int>& num) {
		vector<vector<int> > ref;
		if (num.size() < 3) return ref;
		sort(num.begin(), num.end());
		for (int i = 0; i < num.size(); i++) {
			//if (num[i] == num[i + 1])  continue;
			int ileft = i + 1;
			int iRight = num.size() - 1;
			int targe = -1 * num[i];
			while (ileft < iRight) {
				if (targe == num[ileft] + num[iRight]) {
					ref.push_back({ num[i], num[ileft], num[iRight] });
					while (i + 1 < num.size() && num[i] == num[i + 1]) i++; //去重
					while (ileft + 1 < iRight && num[ileft] == num[ileft + 1]) ileft++;
					while (iRight - 1 > ileft && num[iRight] == num[iRight - 1]) iRight--;

					ileft++;
					iRight--;
				}
				else if (targe < num[ileft] + num[iRight]) {
					iRight--;
				}
				else {
					ileft++;
				}

			}

		}

		return ref;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
