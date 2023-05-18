//MT2068  高数考完了，又到了数学老师难办的时候。数学老师想捞同学一把，她总是要一遍遍地给某些同学增加分数(均为正整数)，又要注意最低分是多少。
//由于工作量很大，你能帮帮她吗 ?
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
const int N = 5e6 + 10;
int main()
{
	int n, p;
	int ans = 999999;
	cin >> n>>p;
	int grade[N];
	grade[0] = 0;
	int sub[N];
	for (int i = 1;i <= n;i++)
	{
		cin >> grade[i];
		sub[i] = grade[i] - grade[i - 1];//差分数组
	}
	while (p--)
	{
		int x, y, z;
		cin >> x >> y >> z;
		sub[x] += z;
		sub[y+1] -= z;//差分操作的公式

	}
	for (int i = 1;i <= n;i++)
	{
		grade[i] = grade[i - 1] + sub[i];
		ans = min(ans, grade[i]);
	}
	cout << ans;
	return 0;
	
}
