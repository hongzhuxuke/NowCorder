/*
BM49 表达式求值
描述
请写一个整数计算器，支持加减乘三种运算和括号。

数据范围：0\le |s| \le 1000≤∣s∣≤100，保证计算结果始终在整型范围内

要求：空间复杂度： O(n)O(n)，时间复杂度 O(n)O(n)
示例1
输入：
"1+2"
复制
返回值：
3
复制
示例2
输入：
"(2*(3-4))*5"
复制
返回值：
-10
复制
示例3
输入：
"3+2*3*4-1"
复制
返回值：
26

*/
#include <string>
#include <stack>

using namespace std;

class Solution {
public:

	int solve(string s) {
		return function(s);
	}

private:
	void appStk(stack<int>& stk, int& iN, char temp[]) {
		if (temp[0] == '-') {
			stk.push(-1 * iN);
		}
		else if (temp[0] == '*') {
			stk.top() *= iN;
		}
		else {
			stk.push(iN);
		}
		iN = 0;
	}

	int function(string s) {
		int iNum = 0;
		stack<int> stk;
		int tN = 0;
		int i = 0;
		char Cal[2]{ '\0' };
		int iBrakets = 0;
		string st = "";
		char temp[2]{ '\0' };

		while (i < s.length()) {
			if (iBrakets > 0) {
				if (s.at(i) == ')') {
					--iBrakets;
					if (0 == iBrakets) {
						tN = function(st);
						st = "";
						continue;
					}
				}
				else if (s.at(i) == '(') {
					++iBrakets;
				}
				temp[0] = s.at(i);
				st.append(temp);
			}
			else if (s.at(i) >= '0' && s.at(i) <= '9') {
				tN *= 10;
				tN += (s.at(i) - '0');
			}
			else if (s.at(i) == '(') {
				//appStk(stk, tN, Cal);//括号前边不会是数字，不然   2*（）  会引起 2*0  等于0 了
				st = "";
				++iBrakets;
			}
			else if (s.at(i) == '+' || s.at(i) == '-' || s.at(i) == '*') {
				appStk(stk, tN, Cal);
				Cal[0] = s.at(i);
			}
			i++;
		}
		appStk(stk, tN, Cal);

		while (!stk.empty()) {
			iNum += stk.top();
			stk.pop();
		}
		return iNum;
	}


};

int main()
{
    //std::cout << "Hello World!\n";
}
