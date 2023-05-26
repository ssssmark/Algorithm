#include<iostream>
#include<algorithm>
using namespace std;
struct relation {
	int i, j;
}a[10005];
int fa[10005] = {};
void init()
{
	for (int i = 1;i < 10005;i++) {
		fa[i] = i;
	}
}
int find(int x)
{
	if (fa[x] == x)
		return x;
	else {
		return find(fa[x]);
	}
}
int main()
{
	init();
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i].i >> a[i].j;
		fa[a[i].j] = a[i].i;//b是a的附庸代表b的父节点是a
	}
	int q;
	cin >> q;
	for (int t = 0;t < q;t++)
	{
		int a, b;
		cin >> a >> b;
		int x = find(a);
		int y = find(b);
		if (x == y)
		{
			cout << 1 << endl;
		}
		else
			cout << 0 << endl;
	}
	return 0;
}