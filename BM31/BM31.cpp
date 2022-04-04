/*
BM31 对称的二叉树
描述
给定一棵二叉树，判断其是否是自身的镜像（即：是否对称）
例如：                                 下面这棵二叉树是对称的

下面这棵二叉树不对称。

数据范围：节点数满足 0 \le n \le 10000≤n≤1000，节点上的值满足 |val| \le 1000∣val∣≤1000
要求：空间复杂度 O(n)O(n)，时间复杂度 O(n)O(n)
备注：
你可以用递归和迭代两种方法解决这个问题
示例1
输入：
{1,2,2,3,4,4,3}
复制
返回值：
true
复制
示例2
输入：
{8,6,9,5,7,7,5}
复制
返回值：
false

*/

#include <iostream>


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
	bool isSymmetrical(TreeNode* pRoot) {
		if (pRoot == NULL) return true;
		return calc(pRoot->left, pRoot->right);
	}

	bool calc(TreeNode* t1, TreeNode* t2)//此题开始并没思路，或者思路错误
	{
		if (t1 == NULL && t2 == NULL) return true;
		else if (t1 == NULL || t2 == NULL || t1->val != t2->val) return false;
		else
		{
			return calc(t1->left, t2->right) && calc(t2->left, t1->right);
		}


	}

};

int main()
{
    std::cout << "Hello World!\n";
}
