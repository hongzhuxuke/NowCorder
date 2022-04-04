/*
BM36 判断是不是平衡二叉树

描述
输入一棵节点数为 n 二叉树，判断该二叉树是否是平衡二叉树。
在这里，我们只需要考虑其平衡性，不需要考虑其是不是排序二叉树
平衡二叉树（Balanced Binary Tree），具有以下性质：它是一棵空树或它的左右两个子树的高度差的绝对值不超过1，并且左右两个子树都是一棵平衡二叉树。
样例解释：

样例二叉树如图，为一颗平衡二叉树
注：我们约定空树是平衡二叉树。

数据范围：n \le 100n≤100,树上节点的val值满足 0 \le n \le 10000≤n≤1000
要求：空间复杂度O(1)O(1)，时间复杂度 O(n)O(n)
输入描述：
输入一棵二叉树的根节点
返回值描述：
输出一个布尔类型的值
示例1
输入：
{1,2,3,4,5,6,7}
复制
返回值：
true
复制
示例2
输入：
{}
复制
返回值：
true

*/

#include <iostream>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:
	bool IsBalanced_Solution(TreeNode* pRoot) {
		if (pRoot == NULL) return true;
		else
		{
			int iL = calDep(pRoot->left);
			int iR = calDep(pRoot->right);
			iL = iL - iR;
			if (IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right) && iL >= -1 && iL <= 1)
			{
				return true;
			}
			else
				return false;

		}
		return true;
	}

	int calDep(TreeNode* t)
	{
		if (NULL == t) return 0;
		else if (t->left == NULL && t->right == NULL)
		{
			return 1;
		}
		else
		{
			int l = calDep(t->left) + 1;
			int r = calDep(t->right) + 1;
			if (l > r) return l;
			else return r;
		}
	}

};

int main()
{
    std::cout << "Hello World!\n";
}
