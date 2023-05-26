#include<iostream>
#include<algorithm>
#include<string> 
#include<iomanip>
#include<stdio.h>
using namespace std;
int dis[1000][1000] = {};//����¼
int shortest_path(string s1,string s2)
{
	int n1 = s1.length();
	int n2 = s2.length();
	//��ʼ������¼����Ϊ�մ�ת��ΪĿ�괮�ľ���ΪĿ�괮�ĳ���
	for (int i = 1;i <= n1;i++)
	{
		dis[i][0] = i;
	}
	for (int i = 1;i <= n2;i++)
	{
		dis[0][i] = i;
	}
	for (int i = 1;i <=n1;i++)
	{
		for (int j = 1;j <= n2;j++)
		{
			int flag = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
			dis[i][j] = min(dis[i - 1][j] + 2, min(dis[i][j - 1] + 2, dis[i - 1][j - 1] + flag));
		}
	}
	return dis[n1][n2];
}
int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	cout<<shortest_path(s1, s2);
	return 0;

}