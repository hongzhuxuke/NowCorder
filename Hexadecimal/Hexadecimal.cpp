#include <iostream>
using namespace std;
#include <string>
int main()
{
	char str[32];

	int iNum = 0;
	//while(true)
	{
		iNum = 0;

		cin >> str;

		int iL = string(str).length();


		int ibit = 1;
		for (int i = iL - 1; i >= 0; i--)
		{
			char temp = str[i];
			if ('0' <= temp && temp <= '9')
			{
				iNum += ((temp - '0')*ibit);
			}
			else if ('a' <= temp && temp <= 'f')
			{
				iNum += ((temp - 'a' + 10)*ibit);
			}
			else if ('A' <= temp && temp <= 'F')
			{
				iNum += ((temp - 'A' + 10)*ibit);
			}
			else break;
			ibit *= 16;
		}
		cout << iNum << endl;
	}
	return 0;
}

//#include <iostream>
//#include <string.h>
//using namespace std;
//
//int main()
//{
//	char temp[32];
//	while (cin.getline(temp, 31))
//	{
//		int iLe = strlen(temp);
//		int iNum = 0;
//		int BigN = 1;
//		for (int i = iLe - 1; i >= 0; i--)
//		{
//			char c = temp[i];
//			int iCurN = 0;
//
//			if ('A' <= c && c <= 'F')
//			{
//				iCurN = 10 + c - 'A';
//			}
//			else if ('a' <= c && c <= 'f')
//			{
//				iCurN = 10 + c - 'a';
//			}
//			else if ('0' <= c &&  c<= '9')
//			{
//				iCurN = c - '0';
//			}
//			else
//			{
//				break;
//			}
//			iNum += (iCurN*BigN);
//			BigN *= 16;
//		}
//		printf("%d\n", iNum);
//	}
//
//	return 0;
//}