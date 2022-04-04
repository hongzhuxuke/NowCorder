/*
BM32 合并二叉树
描述
已知两颗二叉树，将它们合并成一颗二叉树。合并规则是：都存在的结点，就将结点值加起来，否则空的位置就由另一个树的结点来代替。例如：
两颗二叉树是:
																	Tree 1


																		Tree 2

																	合并后的树为

数据范围：树上节点数量满足 0 \le n \le 5000≤n≤500，树上节点的值一定在32位整型范围内。
进阶：空间复杂度 O(1)O(1) ，时间复杂度 O(n)O(n)
示例1
输入：
{1,3,2,5},{2,1,3,#,4,#,7}
复制
返回值：
{3,4,5,5,4,#,7}
复制
说明：
如题面图
示例2
输入：
{1},{}
复制
返回值：
{1}

*/

#include <iostream>


  struct TreeNode {
 	int val;
 	struct TreeNode *left;
	struct TreeNode *right;
 };
 

class Solution {
public:

#if 1  //牛人解体法
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		if (t1 == NULL) return t2;
		else if (t2 == NULL) return t1;
		else {
			TreeNode* pt = new TreeNode(t1->val + t2->val);
			pt->left = mergeTrees(t1->left, t2->left);
			pt->right = mergeTrees(t1->right, t2->right);
			return pt;
		}

	}
#else
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		// write code here
		//TreeNode* pp = new TreeNode;
		TreeNode* pT;
		buildT(&pT, t1, t2);
		return pT;
	}

	void buildT(TreeNode** T, TreeNode* t1, TreeNode* t2)
	{
		if (t1 == NULL && t2 == NULL)
		{
		}
		if (t1 == NULL)
		{
			*T = t2;
		}
		else if (t2 == NULL)
		{
			*T = t1;
		}
		else
		{
			*T = t1;
			(*T)->val = t1->val + t2->val;
			buildT(&(*T)->left, t1->left, t2->left);
			buildT(&(*T)->right, t1->right, t2->right);
		}
	}
#endif
};

int main()
{
    std::cout << "Hello World!\n";
}
