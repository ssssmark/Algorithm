#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
int dp[100];//dp[i]表示有i个盘子的需要移动次数
int inf =0x3f3f3f3f;
int main()
{
	memset(dp, inf, sizeof(dp));
	int f;
	cin >> f;
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 3;
	cout << 1 << endl << 3 << endl;
	for (int i = 3;i <= f;i++)
	{
		for (int k = 1;k < i;k++)
		{
			if (dp[i] > 2 *dp[i - k] + pow(2, k) - 1)
				dp[i] = 2 *dp[i - k] + pow(2, k) - 1;
		}
		cout << dp[i] << endl;
	}
	return 0;
}