#include<iostream>
#include<string.h>
using namespace std;
int a[1009][1009];
int dp[1009];//dp[i]��ʾ�ӵ�i��վ�㵽�յ����С�÷�
int main()
{

	int n;
	cin >> n;//���������յ�һ����n+2��վ��
	n++;
	for (int i = 0;i <n;i++)
	{
		for (int j = i+1;j <=n;j++)
		{
			cin >> a[i][j];
			
		}
		dp[i] = 99999;
	}
	for (int i = n - 1;i >= 0;i--)
	{
		for (int j = i + 1;j <= n;j++)
		{
			dp[i] = min(dp[i], dp[j] + a[i][j]);
		}
	}
	cout << dp[0];
	return 0;
}