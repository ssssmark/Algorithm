//”√dfsª·≥¨ ±
#include<iostream>
using namespace std;
const int N = 3009;
int map[N][N];
long int ans = 0;
void dfs(int m,int n,int i,int j)
{
	if (i == 0 && j == n - 1)
	{
		ans++;
		return;
	}
		
	else {
		if (j+1<n&&map[i][j + 1] != 1)
		{
			dfs(m, n, i, j + 1);
		}
		if (i - 1 >= 0&&map[i - 1][j] != 1)
		{
			dfs(m, n, i - 1, j);
		}
	}
}
int main()
{
	int m, n;
	cin >> m >> n;
	for (int i = 0;i < m;i++)
	{
		for (int j = 0;j < n;j++)
		{
			cin >> map[i][j];
		}
	}
	dfs(m, n, m - 1, 0);
	cout << ans % 2333;
	return 0;
}