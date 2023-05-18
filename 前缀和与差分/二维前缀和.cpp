/*
在一个直角坐标系上，有 n 个坐标上有元素值(其余坐标的元素值为0)，
现给定一些点的坐标 (ti,yi) 和这个坐标的元素值 v: ，计算用一个边长为 R 的正矩形能括 标的元素值的和的最大值。不包括正方形的边界。
*/
#include<iostream>
using namespace std;
int map[1005][1005] = {};
int s[1005][1005] = {};//s[i,j]表示第i行第j列格子左上角所有元素的和
int main()
{
	int n, R;
	cin >> n >> R;
	for (int i = 1;i <=n;i++)
	{
		int x, y, v;
		cin >> x >> y >> v;
		x++;
		y++;
		map[x][y] += v;
	}
	for (int i = 1;i <= 1001;i++)
	{
		for (int j = 1;j <=1001;j++)
		{
			s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1]+map[i][j];
		}
	}
	int ans = 0;
	for (int i =R ;i <= 1001;i++)
	{
		for (int j = R;j <= 1001;j++)
		{
			ans = max(ans, s[i][j]-s[i-R][j]-s[i][j-R]+s[i-R][j-R]);
		}
	}
	cout << ans;
}