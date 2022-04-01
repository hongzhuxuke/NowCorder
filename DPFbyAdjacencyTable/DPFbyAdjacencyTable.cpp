// BPFbyAdjacencyTable.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
#define MAXNUM 100
struct ArcNode
{
	int  i; //指向顶点坐标
	ArcNode* nextArcNode = NULL; //下一条边
	int info; //权值

	~ArcNode()
	{
		if (nextArcNode)
		{
			delete nextArcNode;
			nextArcNode = NULL;
		}
	}
};

typedef struct VexNode
{
	char cData;  //当前节点值
	ArcNode* firstArcNode = NULL; //当前节点第一个编指针
	~VexNode()
	{
		if (firstArcNode)
		{
			delete firstArcNode;
			firstArcNode = NULL;
		}
	}
	
}VexNode,ADjList[MAXNUM];

 struct CALGraph
{
	 //struct VexNode vectes[MAXNUM];
	 ADjList ves;
	 int iVexN;
	 int iArcN;
};

int GetVexIndex(CALGraph& g, char v);
void buildGraph(CALGraph& g);
void visiteGraph(CALGraph& g, char v);
int *iVistRecode;

int main()
{
	CALGraph g;

	buildGraph(g);
	iVistRecode = new int[g.iVexN+1]{0};
	char v;
	printf("Enter:");
	cin >> v;
	visiteGraph(g, v);

	//delete []iVistRecode;
}


int GetVexIndex(CALGraph& g, char v)
{
	if (g.iVexN <= 0)
	{
		return -1;
	}

	for (int i = 0; i < g.iVexN; i++)
	{
		if (g.ves[i].cData == v)
		{
			return i;
		}
	}
	return -1;
}

void buildGraph(CALGraph& g)
{
	int iNum = 0;
	printf("Enter Vex Num:\n");

	cin >> iNum;
	
	g.iVexN = iNum;
	for (int i = 0; i < iNum; i++)
	{
		cin >>g.ves[i].cData;
		
	}

	cin >> g.iArcN;
	
	char v1, v2;
	int iX, iY;

	for (int i = 0; i < g.iArcN; i++)
	{
		cin >> v1;
		cin >> v2;
		
		iX = GetVexIndex(g, v1);
		iY = GetVexIndex(g, v2);
		
		ArcNode* p1 = new ArcNode;
		p1->nextArcNode = g.ves[iX].firstArcNode;
		g.ves[iX].firstArcNode = p1;
		p1->i = iY;

		ArcNode* p2 = new ArcNode;
		p2->nextArcNode = g.ves[iY].firstArcNode;
		g.ves[iY].firstArcNode = p2;
		p2->i = iX;
	}
}


void visiteGraph(CALGraph& g, char v)
{
	int iStartI = GetVexIndex(g, v);
	if (iStartI < 0)
	{
		return;
	}

	iVistRecode[iStartI] = 1;
	printf("%c ", g.ves[iStartI].cData);

	 ArcNode* pTemp = g.ves[iStartI].firstArcNode;
	for (; pTemp; pTemp = pTemp->nextArcNode)
	{

		int iCur = pTemp->i;
		

		if (iCur>=0 && iCur<=MAXNUM && !iVistRecode[iCur])
		{
			visiteGraph(g, g.ves[iCur].cData);
		}
		
	}
}