//用dfs会超时
#include<iostream>
using namespace std;
const int N = 3009;
int map[N][N] = {};
int dp[N][N] = {};//dp[i][j]表示从起点到i，j的路径条数
long int ans = 0;
int main()
{
	int m, n;
	cin >> m >> n;
	dp[m][1] = 1;
	for (int i = 1;i <= m;i++)
	{
		for (int j = 1;j <= n;j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = m;i >= 1;i--)
	{
		for (int j = 1;j <= n;j++)
		{
			if (map[i][j] != 1)
			{
				dp[i][j] += dp[i][j - 1] + dp[i + 1][j];
				dp[i][j] %= 2333;
			}
		}
	}
	ans = dp[1][n];
	cout << ans;
	return 0;
}