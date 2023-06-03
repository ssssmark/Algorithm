/*
利用树状数组求逆序对
1.离散化
2.求顺序对（逐个更新+查询）
*/

#include<iostream>
#include<algorithm>
using namespace std;
const int N = 200010;
int nums[N], c[N], seperate[N];//nums是原数组，seperate是将其离散化数组，C是树状数组
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
bool cmp(int x, int y)
{
	if (nums[x] == nums[y])
		return x > y;
	return nums[x] > nums[y];
}
int main()
{
	cin >> n;
	long long ans = 0;
	for (int i = 1;i <= n;i++)
	{
		cin >> nums[i];
		seperate[i] = i;//初始化离散数组
	}
	sort(seperate + 1, seperate + n + 1, cmp);
	for (int i = 1;i <= n;i++)
	{
		add(seperate[i], 1);
		ans += sum(seperate[i] - 1);
	}
	cout << ans;
	return 0;
}