#include <iostream>
using namespace std;
/*给您两个非空的链表，表示两非负整数.它们每位数字都是按照逆序的方式存储，
并且每个节点只能存一位数字。请你将两个数相加，并以相同的形式返回一个表示和的链表
*/
struct listNode 
{
	int Value;
	listNode* nextNode = NULL;

	~listNode()
	{
		if (nextNode)
		{
			delete nextNode;
			nextNode = NULL;
		}
	}
};

listNode* CalSum(listNode* l1, listNode* l2);
int main()
{
	//用连标配list1逆序表示数字343
	listNode*  list1 = new listNode;
	list1->Value = 3;
	listNode*  temp = new listNode;
	temp->Value = 4;
	list1->nextNode = temp;
	temp = new listNode;
	temp->Value = 5;
	list1->nextNode->nextNode = temp;


	//用连标配list1逆序表示数字264
	listNode*  list2 = new listNode;
	list2->Value =4;
	temp = new listNode;
	temp->Value = 6;
	list2->nextNode = temp;
	temp = new listNode;
	temp->Value = 2;
	list2->nextNode->nextNode = temp;

	listNode* l3 = CalSum(list1, list2);

	return 0;
}


listNode* CalSum(listNode* l1, listNode* l2)
{
	listNode* refList = new listNode;
	refList->Value = -1;
	listNode* temp = l1;
	listNode* temp2 = l2;
	
	int bit = 0 ;
	listNode* tempL3 = refList;

	while ( temp ||temp2 )
	{
		int iTempSum = 0;//注意此处清零
		if (temp)
		{
			iTempSum += temp->Value;
			temp = temp->nextNode;
		}
		if (temp2)
		{
			iTempSum += temp2->Value;
			temp2 = temp2->nextNode;
		}

		iTempSum += bit;
		bit = iTempSum / 10;
		tempL3->nextNode = new listNode;
		tempL3->nextNode->Value = iTempSum % 10;
		tempL3 = tempL3->nextNode;
	}
	return refList->nextNode;
}

