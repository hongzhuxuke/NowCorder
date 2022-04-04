/*
BM4 合并两个排序的链表
描述
输入两个递增的链表，单个链表的长度为n，合并这两个链表并使新链表中的节点仍然是递增排序的。
数据范围： 0 \le n \le 10000≤n≤1000，-1000 \le 节点值 \le 1000−1000≤节点值≤1000
要求：空间复杂度 O(1)O(1)，时间复杂度 O(n)O(n)

如输入{1,3,5},{2,4,6}时，合并后的链表为{1,2,3,4,5,6}，所以对应的输出为{1,2,3,4,5,6}，转换过程如下图所示：


或输入{-1,2,4},{1,3,4}时，合并后的链表为{-1,1,2,3,4,4}，所以对应的输出为{-1,1,2,3,4,4}，转换过程如下图所示：

示例1
输入：
{1,3,5},{2,4,6}
复制
返回值：
{1,2,3,4,5,6}
复制
示例2
输入：
{},{}
复制
返回值：
{}
复制
示例3
输入：
{-1,2,4},{1,3,4}
复制
返回值：
{-1,1,2,3,4,4}

*/
#include <iostream>


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
		ListNode* ref = NULL;
		if (pHead1 == NULL) return pHead2;
		if (pHead2 == NULL) return pHead1;

		ListNode* l1 = NULL;
		ListNode* l2 = NULL;

		if (pHead1->val < pHead2->val)
		{
			ref = pHead1;
			l1 = pHead1->next;
			l2 = pHead2;
		}
		else
		{
			ref = pHead2;
			l2 = pHead2->next;
			l1 = pHead1;
		}
		ListNode* c = ref;

		while (l1 != NULL || l2 != NULL) {

			if (l1 != NULL && l2 != NULL && l1->val < l2->val) {
				c->next = l1;
				c = c->next;
				l1 = l1->next;
			}
			else if (l1 != NULL && l2 != NULL) {
				c->next = l2;
				c = c->next;
				l2 = l2->next;
			}
			else if (l1 == NULL)
			{
				c->next = l2;
				break;
			}
			else {
				c->next = l1;
				break;
			}

		}

		return ref;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}
