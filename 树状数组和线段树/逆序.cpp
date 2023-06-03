//MT2142
#include<iostream>
#include<vector>
using namespace std;
const int N = 1e5 + 10;
int nums[N], c[N],chg[N];//c[N]为树状数组,chg[i]代表删除i元素对整个数组record的贡献
int n;
int lowbit(int x)
{
	return x & -x;
}
void add(int i, int x)//点更新，从底层一直更新父节点到顶层
{
	for (;i <= n;i += lowbit(i))
		c[i] += x;
}
int sum(int i)//计算1-i的区间和
{
	int ans = 0;
	for (;i > 0;i -= lowbit(i))
		ans += c[i];
	return ans;
}
int main()
{
	cin >> n;
	int x = 0, maxx = 0;
	for (int i = 1;i <= n;i++)
	{
		cin >> x;
		maxx = max(x, maxx);
		int smaller = sum(x);//树状数组查询这个数前面有多少数比它小
		if (smaller == i - 1)//i-1个说明当前即为前i个数最大值
		{
			chg[maxx]--;
		}
		else if (smaller == i - 2)
		{
			chg[maxx]++;//i-2个说明前面有1个数比当前数大，那么如果把这个数删掉，当前数就可以成为一个record
		}
		add(x, 1);
		
	}
	int ans = 1;
	for (int i = 1;i <= n;i++)
	{
		if (chg[i] > chg[ans])
			ans = i;
	}
	cout << ans;
	return 0;
}