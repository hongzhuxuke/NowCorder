// BM85.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
	/**
	 * 验证IP地址
	 * @param IP string字符串 一个IP地址字符串
	 * @return string字符串
	 */
	enum eFlage
	{
		eFlage_IPv4 = 0,
		eFlage_IPv6,
		eFlage_Neither,
	};

	bool IsIPv4(vector<string> vec)
	{
		bool bRef = false;
		if (vec.size() == 4)
		{
			for (int i = 0; i < 4; i++)
			{
				string str = vec[i];
				if (str.at(0) == '0')
				{
					bRef = false;
					break;
				}
				else
				{
					int in = atoi(str.c_str());
					if (in > 0 && in <= 255)
					{
						bRef = true;
					}
					//第一次未考虑   1a1  这种情况
					for (int i = 0; i < str.length(); i++)
					{
						if (str.at(i) < '0' || str.at(i) > '9')
							return false;
					}
				}
			}
		}
		else
		{

		}
		return bRef;
	}

	bool IsIPv6(vector<string> vec)
	{
		bool bRef = false;
		if (vec.size() == 8)
		{
			for (int i = 0; i < 8; i++)
			{
				int iLen = vec[i].length();
				if (iLen > 0 && iLen <= 4)
					bRef = true;
				else
				{
					bRef = false;
					break;
				}
			}
		}
		else
		{

		}
		return bRef;
	}
	string solve(string IP) {
		// write code here
		vector<string> strIps;
		eFlage flage = eFlage::eFlage_Neither;
		string strIp = "";
		int LastSpit = -1;
		for (int i = 0; i < IP.length(); i++)
		{
			char temp[2]{ '\0' };
			temp[0] = IP.at(i);
			if ((temp[0] >= '0' && temp[0] <= '9'))
			{
				strIp.append(temp);
			}
			else if ((temp[0] >= 'a' && temp[0] <= 'f')
				|| (temp[0] >= 'A' && temp[0] <= 'F'))
			{
				if (flage == eFlage_IPv4)
				{
					return "Neither";
				}
				else
				{
					strIp.append(temp);
				}

			}
			else if (i > LastSpit + 1 && i < IP.length() - 1 && temp[0] == '.' && flage != eFlage_IPv6)
			{
				strIps.push_back(strIp);
				strIp = "";
				flage = eFlage_IPv4;
				LastSpit = i;
			}
			else if (i > LastSpit + 1 && i < IP.length() - 1 && temp[0] == ':' && flage != eFlage_IPv4)
			{
				strIps.push_back(strIp);
				strIp = "";
				flage = eFlage_IPv6;
				LastSpit = i;
			}
			else return "Neither";

			if (i == IP.length() - 1) strIps.push_back(strIp);//开始忘记最后一个数据保存
		}

		string ref = "Neither";
		if (flage == eFlage_IPv4 && IsIPv4(strIps))
		{
			ref = "IPv4";
		}
		else if (flage == eFlage_IPv6 && IsIPv6(strIps))
		{
			ref = "IPv6";
		}
		else
		{
			return "Neither";
		}
		return ref;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}