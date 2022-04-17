/*
BM11 链表相加(二)
描述
假设链表中每一个节点的值都在 0 - 9 之间，那么链表整体就可以代表一个整数。
给定两个这种链表，请生成代表两个整数相加值的结果链表。
数据范围：0 \le n,m \le 10000000≤n,m≤1000000，链表任意值 0 \le val \le 90≤val≤9
要求：空间复杂度 O(n)O(n)，时间复杂度 O(n)O(n)

例如：链表 1 为 9->3->7，链表 2 为 6->3，最后生成新的结果链表为 1->0->0->0。

示例1
输入：
[9,3,7],[6,3]
复制
返回值：
{1,0,0,0}
复制
说明：
如题面解释
示例2
输入：
[0],[6,3]
复制
返回值：
{6,3}
复制
备注：
1 \leq n, m \leq 10^61≤n,m≤10
6

0 \leq a_i, b_i \leq 90≤a
i
​
 ,b
i
​
 ≤9
*/

#include <iostream>


 Definition for singly - linked list.
 struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};


class Solution {
public:
	ListNode* addInList(ListNode* head1, ListNode* head2) {
		if (head1 == NULL) return head2;
		if (head2 == NULL) return head1;

		ListNode* t1 = ReverseOrder(head1);
		ListNode* t2 = ReverseOrder(head2);

		ListNode* temp1 = t1;
		ListNode* temp2 = t2;

		ListNode* head = new ListNode(0);
		ListNode* temp = head;
		int iN = 0;
		while (temp1 || temp2 || iN > 0)//temp1,temp2为NULL，有可能iN还有进位未显示
		{
			if (temp1)
			{
				iN += temp1->val;
				temp1 = temp1->next;//别忘记指针向前移动
			}
			if (temp2)
			{
				iN += temp2->val;
				temp2 = temp2->next;
			}
			temp->next = new ListNode(iN % 10);
			iN /= 10;
			temp = temp->next;
		}

		head1 = ReverseOrder(t1);
		head2 = ReverseOrder(t2);
		ListNode* ref = ReverseOrder(head->next);
		head->next = NULL;
		delete head;
		head = NULL;
		return ref;
	}
	ListNode* ReverseOrder(ListNode* head)
	{
		if (NULL == head) return head;
		ListNode* curNode = head;
		ListNode* preCur = NULL;
		while (curNode)
		{
			if (curNode->next)
			{
				ListNode* temp = curNode->next;
				curNode->next = preCur;
				preCur = curNode;
				curNode = temp;
			}
			else {//必不可少，最后一个节点没有显示
				ListNode* temp = curNode->next;
				curNode->next = preCur;
				preCur = curNode;
				curNode = temp;
			}
		}
		return preCur;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}