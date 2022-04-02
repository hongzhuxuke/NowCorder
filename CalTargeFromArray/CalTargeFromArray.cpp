
#include <iostream>
#include <vector>
//#include <array>
#include <unordered_map>

using namespace std;
vector<int> CalTarge(int iArray[], int iMaxN, int iTarge);

int main()
{
	int iArray[] = {1,3,4,2,5,1,7,3,7};
	vector<int> vec = CalTarge(iArray, sizeof(iArray)/sizeof(int), 10);
	
	for (int i = 0; i< vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << endl;
	return 0;
}

std::vector<int> CalTarge(int iArray[], int iMaxN, int iTarge)
{
	vector<int> iRef;
	unordered_map<int, int> Result;
	for (int i = 0; i< iMaxN; i++)
	{
		if (iArray[i]< iTarge)
		{
			unordered_map<int, int>::iterator it = Result.find(iTarge - iArray[i]);
			if (it!= Result.end())
			{
				iRef.push_back(it->second);
				iRef.push_back(i);
				return iRef;
			}
			Result[iArray[i]] =  i;
		}

	}

	return iRef;
}