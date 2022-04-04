/*BM1 反转链表

描述
给定一个单链表的头结点pHead(该头节点是有值的，比如在下图，它的val是1)，长度为n，反转该链表后，返回新链表的表头。

数据范围： 0\leq n\leq10000≤n≤1000
要求：空间复杂度 O(1)O(1) ，时间复杂度 O(n)O(n) 。

如当输入链表{1,2,3}时，
经反转后，原链表变为{3,2,1}，所以对应的输出为{3,2,1}。
以上转换过程如下图所示：

示例1
输入：
{1,2,3}
复制
返回值：
{3,2,1}
复制
示例2
输入：
{}
复制
返回值：
{}
复制
说明：
空链表则输出空
关联企业

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
	ListNode* ReverseList(ListNode* pHead) {
		ListNode* t = pHead;
		ListNode* l = NULL;
		ListNode* n = NULL;
		while (t)
		{
			n = t->next;
			t->next = l;
			l = t;
			t = n;
		}
		return l;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}

