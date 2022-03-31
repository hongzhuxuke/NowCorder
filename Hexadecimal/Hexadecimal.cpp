#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	char temp[32];
	while (cin.getline(temp, 31))
	{
		int iLe = strlen(temp);
		int iNum = 0;
		int BigN = 1;
		for (int i = iLe - 1; i >= 0; i--)
		{
			char c = temp[i];
			int iCurN = 0;

			if ('A' <= c && c <= 'F')
			{
				iCurN = 10 + c - 'A';
			}
			else if ('a' <= c && c <= 'f')
			{
				iCurN = 10 + c - 'a';
			}
			else if ('0' <= c &&  c<= '9')
			{
				iCurN = c - '0';
			}
			else
			{
				break;
			}
			iNum += (iCurN*BigN);
			BigN *= 16;
		}
		printf("%d\n", iNum);
	}

	return 0;
}