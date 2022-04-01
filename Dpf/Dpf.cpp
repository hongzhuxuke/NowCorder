#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Node
{
public:
	Node(int iValue);
	~Node();

	Node* InsertLeftNode(int iValue);
	Node* InsertRightNode(int iValue);
public:
	int miValue;
	Node* mLeftNode;
	Node* mRightNode;
};

Node::Node(int iValue)
{
	miValue = iValue;
}

Node::~Node()
{
	delete mLeftNode;
	delete mRightNode;
	miValue = -1;
}


Node* Node::InsertLeftNode(int iValue)
{

	if (NULL!=mLeftNode)
	{
		delete mLeftNode;
	}
	mLeftNode = new Node(iValue);
	return mLeftNode;
}

Node* Node::InsertRightNode(int iValue)
{

	if (NULL!=mRightNode)
	{
		delete mRightNode;
	}
	mRightNode = new Node(iValue);

	return mRightNode;
}

void Dpf(Node* pNode);
void DpfByStack(Node* pNode);
void BpfByQueue(Node* pNode);
void ProssNode(Node* pNode);
//void ProssBpfNode(Node* pNode, bool bProssCur);
int main()
{
	Node* pRoot = new Node(1);
	Node* pCur2 = pRoot->InsertLeftNode(2);
	Node*  pCur4 = pCur2->InsertLeftNode(4);
	Node* pCur8 = pCur4->InsertLeftNode(8);
	pCur8->InsertLeftNode(16);
	pCur8->InsertRightNode(17);
	Node* pCur9 = pCur4->InsertRightNode(9);
	pCur9->InsertLeftNode(18);
	pCur9->InsertRightNode(19);

	Node*  pCur5 = pCur2->InsertRightNode(5);
	Node* pCur10 = pCur5->InsertLeftNode(10);
	pCur10->InsertLeftNode(20);
	pCur10->InsertRightNode(21);
	Node* pCur11 = pCur5->InsertRightNode(11);
	pCur11->InsertLeftNode(22);
	pCur11->InsertRightNode(23);

	Node*  pCur3 = pRoot->InsertRightNode(3);
	Node*  pCur6 = pCur3->InsertLeftNode(6);
	Node* pCur7 = pCur3->InsertRightNode(7);

	Node*  pCur12 = pCur6->InsertLeftNode(12);
	Node* pCur13 = pCur6->InsertRightNode(13);


	Node*  pCur14 = pCur7->InsertLeftNode(14);
	Node* pCur15 = pCur7->InsertRightNode(15);

	Dpf(pRoot);
	printf("\n");
	DpfByStack(pRoot);
	printf("\n");
	BpfByQueue(pRoot);
	return 0;
}



void ProssNode(Node* pNode)
{
	if (NULL == pNode)
	{
		return;
	}
	std::cout << pNode->miValue  << " ";
}



void BpfByQueue(Node* pNode)
{
	//广度搜索不能靠递归实现
	//if (NULL == pNode)
	//{
	//	return;
	//}

	//if (bProCur)
	//{
	//	ProssNode(pNode);
	//}
	//ProssNode(pNode->mLeftNode);
	//ProssNode(pNode->mRightNode);

	//Bpf(pNode->mLeftNode, false);
	//Bpf(pNode->mRightNode, false);

	if (pNode == NULL)
	{
		return;
	}
	queue<Node*> q;
	q.push(pNode);
	while (!q.empty())
	{
		Node* temp = q.front();
		q.pop();
		if (NULL==temp)
		{
			continue;//此处注意是continue  不是 break，也不是return
		}
		ProssNode(temp);
		q.push(temp->mLeftNode);
		q.push(temp->mRightNode);
		
	}
}



void Dpf(Node* pNode)
{

	if ( NULL== pNode)
	{
		return;
	}

	ProssNode(pNode);
	Dpf(pNode->mLeftNode);
	Dpf(pNode->mRightNode);
}



void DpfByStack(Node* pNode)
{
	if (!pNode)
	{
		return;
	}
	stack<Node*> stk;
	//ProssNode(pNode);//此处注意whil循环内部进行处理节点，此处不需要了
	stk.push(pNode);

	Node* ptempNode = pNode;

	while (!stk.empty())
	{
		Node* pNode = stk.top();
		stk.pop();
		if (pNode == NULL)
		{
			continue;//return;//注意不是 return ，而是continue
		}
		ProssNode(pNode);
		stk.push(pNode->mRightNode);
		stk.push(pNode->mLeftNode);
		
	}
}
