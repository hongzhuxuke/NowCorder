
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 * 计算两个数之和
	 * @param s string字符串 表示第一个整数
	 * @param t string字符串 表示第二个整数
	 * @return string字符串
	 */
	string solve(string s, string t) {
		// write code here
		int iL = s.length() > t.length() ? s.length() : t.length();
		char* temp = new char[iL + 1]{ '\0' };
		int is = s.length() - 1;
		int it = t.length() - 1;
		int ic = iL - 1;
		int iBig = 0;
		char *c = new char[2]{ '\0' };
		for (; ic >= 0; is--, it--, ic--)
		{
			int iNum = iBig;
			if (it >= 0)
			{
				c[0] = t.at(it);
				iNum += atoi(c);//开始忘记累加进位数据了
			}
			if (is >= 0)
			{
				c[0] = s.at(is);
				iNum += atoi(c);
			}

			iBig = iNum / 10;
			iNum %= 10;
			if (ic >= 0 && ic < iL)
				temp[ic] = ('0' + iNum);
		}

		delete[]c;
		string strRef;
		if (iBig > 0)
			strRef = "1";

		strRef.append(temp);
		delete[]temp;
		return strRef;
	}
};
int main()
{
    std::cout << "Hello World!\n";
}

