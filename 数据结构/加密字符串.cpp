#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int main()
{
	string s1, s2;
	int str1[30] = {};
	int str2[30] = {};
	while (cin >> s1 >> s2)
	{
		memset(str1, 0, sizeof(str1));
		memset(str2, 0, sizeof(str2));
		if (s1.length() != s2.length())
		{
			cout << "NO" << endl;
			continue;
		}
		for (int i = 0;i < s1.length();i++)
		{
			str1[s1[i] - 'A']++;
			str2[s2[i] - 'A']++;
		}
		sort(str1, str1 + 26);
		sort(str2, str2 + 26);
		bool flag = true;
		for (int i = 0;i < 26;i++)
		{
			if (str1[i] != str2[i])
			{
				flag = false;
				cout << "NO" << endl;
				break;
			}
		}
		if (flag == true)
		{
			cout << "YES" << endl;
		}

	}
	return 0;
}