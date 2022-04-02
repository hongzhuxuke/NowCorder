/*描述
对于一个长度为 n 字符串，我们需要对它做一些变形。

首先这个字符串中包含着一些空格，就像"Hello World"一样，然后我们要做的是把这个字符串中由空格隔开的单词反序，同时反转每个字符的大小写。

比如"Hello World"变形后就变成了"wORLD hELLO"。

数据范围: 1\le n \le 10^61≤n≤10
6
  , 字符串中包括大写英文字母、小写英文字母、空格。
进阶：空间复杂度 O(n)O(n) ， 时间复杂度 O(n)O(n)
输入描述：
给定一个字符串s以及它的长度n(1 ≤ n ≤ 10^6)
返回值描述：
请返回变形后的字符串。题目保证给定的字符串均由大小写字母和空格构成。
示例1
输入：
"This is a sample",16
复制
返回值：
"SAMPLE A IS tHIS"
复制
示例2
输入：
"nowcoder",8
复制
返回值：
"NOWCODER"
复制
示例3
输入：
"iOS",3
复制
返回值：
"Ios"
*/

#include <iostream>
#include <string>
#include <stack>
using namespace  std;

class Solution {
public:
	string trans(string s, int n) {
		stack<string> stckStr;

		string str = "";
		for (int i = 0; i < s.length(); i++)
		{
			char temp[2]{'\0'};//开始未考虑temp的结尾符号直接赋值给str，导致str数组越界
			temp[0]= s.at(i);
			if (temp[0] >= 'a' && temp[0] <= 'z')
			{
				temp[0] = (temp[0] - 'a' + 'A');
				str.append(temp);
				str.append("\0");
			}
			else if (temp[0] >= 'A' && temp[0] <= 'Z')
			{
				temp[0] = (temp[0] - 'A' + 'a');
				str.append(temp);
				str.append("\0");
			}
			else
			{
				stckStr.push(str);
				stckStr.push(temp);
				str = "";
				continue;
			}
			if (i == s.length() - 1)
			{
				stckStr.push(str);
			}
		}
		string strRef;
		while (!stckStr.empty())
		{
			string str1;
			str1 = stckStr.top();
			stckStr.pop();
			strRef += str1;

		}
		strRef.append("\0");
		return strRef;
	}
};

int main()
{
	Solution sl;

	std::cout << sl.trans("This is a sample", 16) << endl;
	std::cout << sl.trans("nowcoder", 8) << endl;
	std::cout << sl.trans("iOS", 3) << endl;
}
