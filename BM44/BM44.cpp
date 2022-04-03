/*
BM44 有效括号序列
描述
给出一个仅包含字符'(',')','{','}','['和']',的字符串，判断给出的字符串是否是合法的括号序列
括号必须以正确的顺序关闭，"()"和"()[]{}"都是合法的括号序列，但"(]"和"([)]"不合法。

数据范围：字符串长度 0\le n \le 100000≤n≤10000
要求：空间复杂度 O(n)O(n)，时间复杂度 O(n)O(n)
示例1
输入：
"()[]{}"
复制
返回值：
true
复制
示例2
输入：
"[]"
复制
返回值：
true
复制
示例3
输入：
"([)]"
复制
返回值：
false
*/

class Solution {
public:
	/**
	 *
	 * @param s string字符串
	 * @return bool布尔型
	 */
	class Solution {
	public:
		/**
		 *
		 * @param s string字符串
		 * @return bool布尔型
		 */
		bool isValid(string s) {
			// write code here
			stack<char> stc;
			bool bRef = true;
			if (s.length() <= 0) return true;

			for (int i = 0; i < s.length() && i <= 10000; i++)
			{
				if (s.at(i) == '(' || s.at(i) == '{' || s.at(i) == '[')
				{
					stc.push(s.at(i));
				}
				else if (s.at(i) == ')')
				{
					//段错误
				//段错误:您的程序发生段错误，可能是数组越界，堆栈溢出（比如，递归调用层数太多）等情况引起
					if (!stc.empty() && stc.top() == '(') {//if (stc.top() == '(') { 不判断栈是否为空，直接获取top 可能会引起越界
						stc.pop();
					}
					else {
						bRef = false;
						break;
					}
				}
				else if (s.at(i) == '}')
				{
					if (!stc.empty() && stc.top() == '{') {
						stc.pop();
					}
					else {
						bRef = false;
						break;
					}
				}
				else if (s.at(i) == ']')
				{
					if (!stc.empty() && stc.top() == '[') {
						stc.pop();
					}
					else {
						bRef = false;
						break;
					}
				}
			}
			if (bRef)
				bRef = stc.empty();
			while (!stc.empty()) stc.pop();
			return bRef;
		}
	};