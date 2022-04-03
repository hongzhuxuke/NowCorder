﻿/*描述
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的 min 函数，输入操作时保证 pop、top 和 min 函数操作时，栈中一定有元素。

此栈包含的方法有：
push(value):将value压入栈中
pop():弹出栈顶元素
top():获取栈顶元素
min():获取栈中最小元素

数据范围：操作数量满足 0 \le n \le 300 \0≤n≤300  ，输入的元素满足 |val| \le 10000 \∣val∣≤10000 
进阶：栈的各个操作的时间复杂度是 O(1)\O(1)  ，空间复杂度是 O(n)\O(n) 

示例:
输入:    ["PSH-1","PSH2","MIN","TOP","POP","PSH1","TOP","MIN"]
输出:    -1,2,1,-1
解析:
"PSH-1"表示将-1压入栈中，栈中元素为-1
"PSH2"表示将2压入栈中，栈中元素为2，-1
“MIN”表示获取此时栈中最小元素==>返回-1
"TOP"表示获取栈顶元素==>返回2
"POP"表示弹出栈顶元素，弹出2，栈中元素为-1
"PSH1"表示将1压入栈中，栈中元素为1，-1
"TOP"表示获取栈顶元素==>返回1
“MIN”表示获取此时栈中最小元素==>返回-1

示例1
输入：
 ["PSH-1","PSH2","MIN","TOP","POP","PSH1","TOP","MIN"]
复制
返回值：
-1,2,1,-1
*/
class Solution {
public:
	void push(int value) {
		stack1.push(value);
	}
	void pop() {
		stack1.pop();
	}
	int top() {
		return stack1.top();
	}
	int min() {
		stack<int> stack2;
		int ref = -10000;
		if (stack1.size() > 0)
		{
			ref = stack1.top();
			stack2.push(ref);
			stack1.pop();
			while (stack1.size() > 0)
			{
				int itp = stack1.top();
				ref = itp < ref ? itp : ref;
				stack1.pop();
				stack2.push(itp);
			}

			while (stack2.size() > 0)
			{
				stack1.push(stack2.top());
				stack2.pop();
			}
		}
		return ref;
	}
private:
	stack<int> stack1;
};