// BM37.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;
struct TreeNode {
 	int val;
 	struct TreeNode *left;
 	struct TreeNode *right;
 	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  };
 
class Solution {
public:
	int lowestCommonAncestor(TreeNode* root, int p, int q) {
		int ip = -1;
		int iq = -1;
		queue<TreeNode*> qu;
		qu.push(root);
		queue<int> qui;
		qui.push(1);
		vector<TreeNode*> v;
		TreeNode* t;
		int it;
		while (!qu.empty())
		{
			t = qu.front();
			qu.pop();
			it = qui.front();
			qui.pop();
			if (t != NULL)
			{
				if (v.capacity() < it) v.resize(2 * it);//用下表或者insert的时候 需要保证容量足够
				v[it - 1] = t;
				if (t->val == q) {
					iq = it;//此处记录赋值的坐标，  38行
				}
				else if (t->val == p)
				{
					ip = it;//此处记录赋值的坐标，  38行
				}

				if (ip >= 0 && iq >= 0) break;

				qu.push(t->left);
				qu.push(t->right);
				qui.push(2 * it);
				qui.push(2 * it + 1);
			}
		}

		stack<int> sp, sq;
		sp.push(ip);
		while (ip / 2 > 0)
		{
			sp.push(ip /= 2);
		}

		sq.push(iq);
		while (iq / 2 > 0) sq.push(iq /= 2);
		while (!sq.empty() && !sp.empty())
		{
			if (sq.top() == sp.top()) it = sq.top();
			else break;
			if (!sq.empty()) sq.pop();
			if (!sp.empty()) sp.pop();
		}

		if (it > 0 && it <= v.size())
		{
			it = v[it - 1]->val;
		}
		return it;
	}
};
int main()
{
    std::cout << "Hello World!\n";
}

