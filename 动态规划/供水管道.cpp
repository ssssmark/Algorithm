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
//���鼯�����������ڵ�ĸ��ڵ�
int find(int x)
{
	if (x == city[x])
		return x;
	else {
		return find(city[x]);
	}
}
//���鼯����������ڵ���ڵ㲻ͬ˵������һ�������У���Ҫ�������ڵ���������
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
	sort(p + 1, p + 1 + k);//���ߵ�Ȩֵ����
	int ans = 0;
	for (int i = 1;i <= k;i++)
	{
		if (find(p[i].i) != find(p[i].j))//��������ڵ㲻��ͬһ���ϣ���Ҫ�Ѷ���������ans+=Ȩֵ
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