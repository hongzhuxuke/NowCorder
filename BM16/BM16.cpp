/*
BM16 删除有序链表中重复的元素-II
描述
给出一个升序排序的链表，删除链表中的所有重复出现的元素，只保留原链表中只出现一次的元素。
例如：
给出的链表为1 \to 2\to 3\to 3\to 4\to 4\to51→2→3→3→4→4→5, 返回1\to 2\to51→2→5.
给出的链表为1\to1 \to 1\to 2 \to 31→1→1→2→3, 返回2\to 32→3.

数据范围：链表长度 0 \le n \le 100000≤n≤10000，链表中的值满足 |val| \le 1000∣val∣≤1000
要求：空间复杂度 O(n)O(n)，时间复杂度 O(n)O(n)
进阶：空间复杂度 O(1)O(1)，时间复杂度 O(n)O(n)
示例1
输入：
{1,2,2}
复制
返回值：
{1}
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
		ListNode* hT = head;
		ListNode* delHead = NULL;
		ListNode* del = NULL;
		while (hT)
		{
			if (hT->next && hT->val == hT->next->val)
			{
				if (delHead == NULL) delHead = hT;
				hT = hT->next;
			}
			else if (/*hT->val!=hT->next->val && */delHead)//hT->next 有可能为NULL
			{
				ListNode* temp = hT->next;
				if (hT)//避免死循环
					hT->next = NULL;
				hT = temp;
				head = hT;
				delete delHead;
				delHead = NULL;
			}
			else if (hT->next && hT->next->next && hT->next->val == hT->next->next->val)//hT->next 合法性校验  
			{
				ListNode* t = hT->next->next;
				hT->next->next = hT->next->next->next;
				t->next = NULL;
				delete t;
				t = NULL;
				if (NULL == del)
					del = hT->next;
			}
			else if (del)
			{
				ListNode* t = hT->next;
				if (hT && hT->next)//合法性校验
					hT->next = hT->next->next;
				t->next = NULL;
				delete t;
				t = NULL;
				del = NULL;
			}
			else {
				hT = hT->next;
			}
		}
		return head;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}
