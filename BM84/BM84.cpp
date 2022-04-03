/*描述
给你一个大小为 n 的字符串数组 strs ，其中包含n个字符串 , 编写一个函数来查找字符串数组中的最长公共前缀，返回这个公共前缀。

数据范围： 0 \le n \le 50000≤n≤5000， 0 \le len(strs_i) \le 50000≤len(strs
i
​
 )≤5000
进阶：空间复杂度 O(n)O(n)，时间复杂度 O(n)O(n)
示例1
输入：
["abca","abc","abca","abc","abcc"]
复制
返回值：
"abc"
复制
示例2
输入：
["abc"]
复制
返回值：
"abc"
*/

#include <iostream>
#include <string>
#include <vector>

using namespace  std;

class Solution {
public:
	/**
	 *
	 * @param strs string字符串vector
	 * @return string字符串
	 */
	string longestCommonPrefix(vector<string>& strs) {
		// write code here
		string strComp = "";
		if (strs.size() > 0)
		{
			int index = 0;
			int iMinLen = -1;
			strComp = strs[0];
			for (int i = 1; i < strs.size(); i++)
			{
				strComp = CalPreFix(strComp, strs[i]);
			}
		}

		return strComp;
	}

	string CalPreFix(string& str1, string& str2)
	{
		int iMinL = str1.length() > str2.length() ? str2.length() : str1.length();
		int i = 0;
		char* temp = new char[iMinL+1] {'\0'};//忘记考虑越界问题
		while (i < iMinL)
		{
			if (str1.at(i) != str2.at(i)) break;
			temp[i] = str1.at(i);
			i++;
		}

		string strRef(temp);
		delete[]temp;
		return strRef;


	}
};
int main()
{
	for (int i = 1; i < 2; i++)
	{
		std::cout << "xkdddkkk" << endl;
	}
	for (int i = 1; i < 0; i++)
	{
		std::cout << "xkkkk" << endl;
	}
	Solution sl;
	vector<string> vec;
	vec.push_back("abca");
	vec.push_back("abc");
	vec.push_back("abca");
	vec.push_back("abc");
	vec.push_back("abcc");

	std::cout << sl.longestCommonPrefix(vec) << endl;
	vector<string> vec1;
	vec1.push_back("abc");
	std::cout << sl.longestCommonPrefix(vec1) << endl;
	vector<string> vec2;
	std::cout << sl.longestCommonPrefix(vec2) << endl;
}

