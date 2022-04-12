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
	string solve(string IP) {
		if (isIp4(IP)) return "IPv4";
		else if (isIp6(IP)) return "IPv6";
		else return "Neither";
	}

	vector<string> split(string ip, char c) {
		vector<string> ref;
		string str;
		char temp[2]{ '\0' };
		for (int i = 0; i < ip.length(); i++) {
			temp[0] = ip.at(i);
			//逻辑判断清楚
			if (temp[0] == c) {
				if (i == 0) return ref;
				else if ((i + 1 < ip.length() && ip.at(i + 1) == c) || i == ip.length() - 1) {
					vector<string> ref2;
					return ref2;
				}
				else {
					ref.push_back(str);
					str = "";
				}
			}
			else {
				str.append(temp);
			}
			//i++;//重复++
		}
		if (str.length() > 0) {
			ref.push_back(str);
			str = "";
		}

		return ref;
	}

	bool  isIp4(string IP) {
		bool bRef = false;
		vector<string> strV = split(IP, '.');
		string strT = "";
		if (strV.size() == 4) {
			for (int i = 0; i < 4; i++) {
				int iN = 0;
				strT = strV[i];
				if (strT[0] == '0' && strT.length() > 0) return bRef;
				for (int j = 0; j < strT.length(); j++) {
					if (strT.at(j) >= '0' && strT.at(j) <= '9') {
						iN *= 10;
						iN += (strT.at(j) - '0');//取数坐标 是 j 不是 i
					}
					else return bRef;
				}
				if (iN < 0 || iN > 255) return bRef;
			}

		}
		else return false;
		return true;
	}

	bool  isIp6(string IP) {
		bool bRef = false;
		vector<string> strV = split(IP, ':');
		string strT = "";
		if (strV.size() == 8) {
			for (int i = 0; i < 8; i++) {
				strT = strV[i];
				int iN = 0;
				if (strT.length() > 4) return false;
				for (int j = 0; j < strT.length(); j++) {
					if (
						(strT.at(j) >= '0' && strT.at(j) <= '9')
						|| (strT.at(j) >= 'a' && strT.at(j) <= 'f')
						|| (strT.at(j) >= 'A' && strT.at(j) <= 'F')) {
						continue;
					}
					else return bRef;
				}

			}

		}
		else return false;
		return true;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}