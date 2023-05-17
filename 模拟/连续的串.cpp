#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct substring {
	string s="";
	int num = 0;
};
vector <substring> sstring;
bool compnum(substring i, substring j)
{
	return i.num < j.num;
}
bool comps(substring i, substring j)
{
	return i.s < j.s;
}
int main()
{
	int n;
	string s;
	cin >> n >> s;
	int typeofsubstr = 0;
	for (int i = 0;i < n - 1;i++)//长度为n的字符串有n-1个长度为2的子串
	{
		string temp= s.substr(i, 2);
		int flag = 0;
		for (int j = 0;j < sstring.size();j++)
		{
			if (sstring[j].s == temp)
			{
				sstring[j].num++;
				flag = 1;
				break;
			}
				
		}
		if(flag==0) {
			sstring.push_back({ temp,0 });
		}	
	}
	sort(sstring.begin(), sstring.end(), compnum);
	sort(sstring.begin(), sstring.end(), comps);
	cout << sstring[0].s;
	return 0;
}