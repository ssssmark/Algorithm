#include<iostream>
#include<algorithm>
using namespace std;
int fa[100005] = {};
int s[100005];
void init()
{
	for (int i = 0;i < 100005;i++)
	{
		fa[i] = i;
	}
}
int find(int x)
{
	if (fa[x] == x)
		return x;
	else
		return find(fa[x]);
}
int main()
{
	init();
	int n, m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> s[i];
	}
	for (int i = 0;i < m;i++)
	{
		int t;
		cin >> t;
		if (t == 1)
		{
			int a, b;
			cin >> a >> b;
			int x = find(a);
			int y = find(b);
			if(x!=y)
			{
				fa[y] = x;
				s[x] += s[y];
			}
		}
		else if (t == 2)
		{
			int q;
			cin >> q;
			cout << s[find(q)] << endl;
		}
	}
	return 0;
}