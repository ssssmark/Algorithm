#include<iostream>
#include<algorithm>
#include<string>
#include<iomanip>
using namespace std;
int arc[105][105] = {};
struct node {
	int i, j, c;
	bool operator<(const node &t) const {
		return c < t.c;
	}
}p[105];
int city[105];
void init()
{
	for (int i = 1;i <= 100;i++)
		city[i] = i;
}
//并查集，查找两个节点的根节点
int find(int x)
{
	if (x == city[x])
		return x;
	else {
		return find(city[x]);
	}
}
//并查集，如果两个节点根节点不同说明不在一个集合中，需要把两个节点连接起来
void merge(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x != y)
		city[x] = y;
}
int main()
{
	init();
	int n, k;
	cin >> n >> k;
	for (int t= 1;t <= k;t++)
	{
		cin >> p[t].i >> p[t].j >> p[t].c;
	}
	sort(p + 1, p + 1 + k);//按边的权值排序
	int ans = 0;
	for (int i = 1;i <= k;i++)
	{
		if (find(p[i].i) != find(p[i].j))//如果两个节点不在同一集合，需要把二者相连，ans+=权值
		{
			ans += p[i].c;
			merge(p[i].i, p[i].j);
		}
		else {

		}
	}
	cout << ans;
	return 0;
}