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
			while (stack2.size() >= )
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