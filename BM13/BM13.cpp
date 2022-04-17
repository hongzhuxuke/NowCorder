/*
BM13 判断一个链表是否为回文结构
描述
给定一个链表，请判断该链表是否为回文结构。
回文是指该字符串正序逆序完全一致。
数据范围： 链表节点数 0 \le n \le 10^50≤n≤10
5
 ，链表中每个节点的值满足 |val| \le 10^7∣val∣≤10
7

示例1
输入：
{1}
复制
返回值：
true
复制
示例2
输入：
{2,1}
复制
返回值：
false
复制
说明：
2->1
示例3
输入：
{1,2,2,1}
复制
返回值：
true
复制
说明：
1->2->2->1
*/
#include <iostream>
  struct ListNode {
 	int val;
 	struct ListNode *next;
  };
 
class Solution {
public:
	bool isPail(ListNode* head) {
		bool bRef = true;
		deque<int> q;
		ListNode* t = head;
		while (t) {
			q.push_back(t->val);
			t = t->next;
		}

		while (!q.empty())
		{
			if (q.front() != q.back()) {
				bRef = false;
				break;
			}
			else {
				q.pop_front();
				if (!q.empty()) q.pop_back();
			}
		}
		return bRef;
	}
};
int main()
{
    std::cout << "Hello World!\n";
}
