/*
BM14 链表的奇偶重排

描述
给定一个单链表，请设定一个函数，将链表的奇数位节点和偶数位节点分别放在一起，重排后输出。
注意是节点的编号而非节点的数值。

数据范围：节点数量满足 0 \le n \le 10^50≤n≤10
5
 ，节点中的值都满足 0 \le val \le 10000≤val≤1000
要求：空间复杂度 O(n)O(n)，时间复杂度 O(n)O(n)
示例1
输入：
{1,2,3,4,5,6}
复制
返回值：
{1,3,5,2,4,6}
复制
说明：
1->2->3->4->5->6->NULL
重排后为
1->3->5->2->4->6->NULL

示例2
输入：
{1,4,6,3,7}
复制
返回值：
{1,6,7,4,3}
复制
说明：
1->4->6->3->7->NULL
重排后为
1->6->7->4->3->NULL
奇数位节点有1,6,7，偶数位节点有4,3。重排后为1,6,7,4,3

备注：
链表长度不大于200000。每个数范围均在int内。
*/

#include <iostream>


 struct ListNode {
 	int val;
 	struct ListNode *next;
 	ListNode(int x) : val(x), next(nullptr) {}
  };
 
class Solution {
public:
	ListNode* oddEvenList(ListNode* head) {

		ListNode* fNode = head;
		ListNode* NewHead = head;
		ListNode* sNode = NULL;
		if (head)
			sNode = head->next;
		ListNode* NewHead2 = sNode;
		ListNode* cur = NULL;
		if (sNode)
			cur = sNode->next;
		bool bF = true;
		while (cur)
		{
			if (bF)
			{
				fNode->next = cur;
				fNode = fNode->next;
			}
			else {
				sNode->next = cur;
				sNode = sNode->next;
			}
			cur = cur->next;
			bF = !bF;
		}

		if (fNode)//{}为空的时候 fNode 为Null
			fNode->next = NewHead2;
		if (sNode)//{1}只有一个节点的时候 sNode为空了
			sNode->next = NULL;

		return NewHead;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}
