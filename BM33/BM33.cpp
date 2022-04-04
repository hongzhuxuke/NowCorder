/*
BM33 二叉树的镜像
数据范围：二叉树的节点数 0 \le n \le 10000≤n≤1000 ， 二叉树每个节点的值 0\le val \le 10000≤val≤1000
要求： 空间复杂度 O(n)O(n) 。本题也有原地操作，即空间复杂度 O(1)O(1) 的解法，时间复杂度 O(n)O(n)

比如：
源二叉树

镜像二叉树

示例1
输入：
{8,6,10,5,7,9,11}
复制
返回值：
{8,10,6,11,9,7,5}
复制
说明：
如题面所示
示例2
输入：
{}
复制
返回值：
{}

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

	TreeNode* Mirror(TreeNode* pRoot) {
		if (pRoot == NULL) return NULL;
		else {
			TreeNode* t = new TreeNode(pRoot->val);
			t->left = Mirror(pRoot->right);
			t->right = Mirror(pRoot->left);
			return t;
		}
	}
};

int main()
{
    std::cout << "Hello World!\n";
}
