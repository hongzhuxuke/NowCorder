/*
BM15 删除有序链表中重复的元素-I
描述
删除给出链表中的重复元素（链表中元素从小到大有序），使链表中的所有元素都只出现一次
例如：
给出的链表为1\to1\to21→1→2,返回1 \to 21→2.
给出的链表为1\to1\to 2 \to 3 \to 31→1→2→3→3,返回1\to 2 \to 31→2→3.

数据范围：链表长度满足 0 \le n \le 1000≤n≤100，链表中任意节点的值满足 |val| \le 100∣val∣≤100
进阶：空间复杂度 O(1)O(1)，时间复杂度 O(n)O(n)
示例1
输入：
{1,1,2}
复制
返回值：
{1,2}
复制
示例2
输入：
{}
复制
返回值：
{}

*/
#include <iostream>

struct ListNode {
	int val;
	struct ListNode *next;
 };
 

class Solution {
public:

	ListNode* deleteDuplicates(ListNode* head) {
		// write code here
		if (NULL == head) return NULL;
		unordered_map<int, int> um;
		ListNode* t = head;
		ListNode* dn;
		um.insert(unordered_map<int, int>::value_type(head->val, head->val));
		while (t && t->next)
		{
			if (um.find(t->next->val) != um.end())
			{
				dn = t->next;
				t->next = t->next->next;
				dn->next = NULL;
				delete dn;
			}
			else {//开始逻辑没有判断清楚
				t = t->next;
				um.insert(unordered_map<int, int>::value_type(t->val, t->val));
			}
		}

		return head;
	}
};
int main()
{
    std::cout << "Hello World!\n";
}

