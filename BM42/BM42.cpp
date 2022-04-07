/*
BM42 用两个栈实现队列
描述
用两个栈来实现一个队列，使用n个元素来完成 n 次在队列尾部插入整数(push)和n次在队列头部删除整数(pop)的功能。 队列中的元素为int类型。保证操作合法，即保证pop操作时队列内已有元素。

数据范围： n\le1000n≤1000
要求：存储n个元素的空间复杂度为 O(n)O(n) ，插入与删除的时间复杂度都是 O(1)O(1)
示例1
输入：
["PSH1","PSH2","POP","POP"]
复制
返回值：
1,2
复制
说明：
"PSH1":代表将1插入队列尾部
"PSH2":代表将2插入队列尾部
"POP“:代表删除一个元素，先进先出=>返回1
"POP“:代表删除一个元素，先进先出=>返回2
*/

class Solution
{
public:
	void push(int node) {
		if (stack2.empty())
		{
			stack1.push(node);
		}
		else
		{
			while (stack2.size() >= 0)
			{
				stack1.push(stack2.top());
				stack2.pop;
			}

			stack1.push(node);
		}
	}

	int pop() {
		int iNode = 0;
		if (stack2.size() > 0) {
			iNode = stack2.top();
			stack2.pop();
		}
		else {
			while (stack1.size() > 0)
			{
				if (stack1.size() == 1)
				{
					iNode = stack1.top();
					stack1.pop();
				}
				else {
					int iN = stack1.top();
					stack1.pop();
					stack2.push(iN);
				}
			}
		}
		return iNode;
	}

private:
	stack<int> stack1;//push
	stack<int> stack2;//pop
};