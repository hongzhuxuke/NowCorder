/*
BM37 二叉搜索树的最近公共祖先
描述
给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
1.对于该题的最近的公共祖先定义:对于有根树T的两个节点p、q，最近公共祖先LCA(T,p,q)表示一个节点x，满足x是p和q的祖先且x的深度尽可能大。在这里，一个节点也可以是它自己的祖先.
2.二叉搜索树是若它的左子树不空，则左子树上所有节点的值均小于它的根节点的值； 若它的右子树不空，则右子树上所有节点的值均大于它的根节点的值
3.所有节点的值都是唯一的。
4.p、q 为不同节点且均存在于给定的二叉搜索树中。
数据范围:
3<=节点总数<=10000
0<=节点值<=10000

如果给定以下搜索二叉树: {7,1,12,0,4,11,14,#,#,3,5}，如下图:
*/
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

