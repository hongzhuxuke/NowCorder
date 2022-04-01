
#include <iostream>
#include <queue>
using namespace std;

#define MXNUM 100

struct CALGraph
{
	char mVex[MXNUM];
	int miArc[MXNUM][MXNUM];
	int miVexCount;
	int miArcCount;
};

int GetVexIndex(CALGraph& g, char v);
void buildGraph(CALGraph& g);
void visiteGraph(CALGraph& g, char v);
int main()
{

	CALGraph g;
	buildGraph(g);
	char v;
	scanf("%c", &v);
	visiteGraph(g, v);
    //std::cout << "Hello World!\n";
}

int GetVexIndex(CALGraph& g, char v)
{
	if (g.miVexCount<=0)
	{
		return -1;
	}

	for (int i=0; i<g.miVexCount; i++)
	{
		if (g.mVex[i] == v)
		{
			return i;
		}
	}
	return -1;
}

void buildGraph(CALGraph& g)
{
	int iNum = 0;
	printf("Enter Vex Num:");
	//getchar();
	scanf("%d", &iNum);
	//getchar();
	g.miVexCount = iNum;
	for (int i=0; i<iNum; i++)
	{
		scanf("%c", &g.mVex[i]);
	}
	//getchar();
	printf("Enter Air Num:");
	//getchar();
	scanf("%d", &g.miArcCount);
	getchar();
	for (int i = 0; i< MXNUM; i++)
	{
		for (int j = 0; j < MXNUM; j++)
			g.miArc[i][j] = 0;
	}
	char v1, v2;
	int iX, iY;
	for (int i = 0; i < g.miArcCount; i++)
	{
		scanf("%c%c", &v1, &v2);
		getchar();
		iX = GetVexIndex(g, v1);
		iY = GetVexIndex(g, v2);
		if (iX>=0 && iY>=0)
		{
			g.miArc[iX][iY] = 1;
			g.miArc[iY][iX] = 1;
		}
	}
}


void visiteGraph(CALGraph& g, char v)
{
	int iStartI = GetVexIndex(g, v);
	if (iStartI<0)
	{
		iStartI = 0;
	}
	
	int *iVistRecode = new int[g.miVexCount]{0};
	iVistRecode[iStartI] = 1;
	printf("%c ", g.mVex[iStartI]);

	queue<char> q;
	q.push(g.mVex[iStartI]);
	while (!q.empty())
	{
		char temp = q.front();
		q.pop();
		int iCV = GetVexIndex(g, temp);
		if (iCV>=0)
			for (int i = 0; i < g.miArcCount; i++)
			{
				if (g.miArc[iCV][i] && !iVistRecode[i])
				{
					printf("%c ", g.mVex[i]);
					iVistRecode[i] = 1;
					q.push(g.mVex[i]);
				}
			}
	}




	delete[]iVistRecode;
}


