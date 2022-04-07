/*
BM50 两数之和

描述
给出一个整型数组 numbers 和一个目标值 target，请在数组中找出两个加起来等于目标值的数的下标，返回的下标按升序排列。
（注：返回的数组下标从1开始算起，保证target一定可以由数组里面2个数字相加得到）

数据范围：2\leq len(numbers) \leq 10^52≤len(numbers)≤10
5
 ，-10 \leq numbers_i \leq 10^9−10≤numbers
i
​
 ≤10
9
 ，0 \leq target \leq 10^90≤target≤10
9

要求：空间复杂度 O(n)O(n)，时间复杂度 O(nlogn)O(nlogn)
示例1
输入：
[3,2,4],6
复制
返回值：
[2,3]
复制
说明：
因为 2+4=6 ，而 2的下标为2 ， 4的下标为3 ，又因为 下标2 < 下标3 ，所以返回[2,3]
示例2
输入：
[20,70,110,150],90
复制
返回值：
[1,2]
复制
说明：
20+70=90

*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
	/**
	 *
	 * @param numbers int整型vector
	 * @param target int整型
	 * @return int整型vector
	 */
	vector<int> twoSum(vector<int>& numbers, int target) {
		// write code here
		unordered_map<int, int> um;
		vector<int> v;
		for (int i = 0; i < numbers.size(); i++)
		{
			unordered_map<int, int>::iterator it = um.find(target - numbers[i]);
			if (it != um.end())
			{
				v.push_back(it->second + 1);//注意下标以 1开始
				v.push_back(i + 1); ////注意下标以 1开始
				break;
			}
			else
			{
				um[numbers[i]] = i;//map 用法
			}
		}
		return v;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}

