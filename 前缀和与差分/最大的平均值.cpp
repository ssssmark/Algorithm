/*
给一个数组长度为n，找一个长度大于等于m的子区间，使得这个区间的元素平均值最大
*/
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	int* a = new int[n];
	double* average = new double[n];
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	for(int t=0;t<n;t++)//计算从t开始长度不小于m的子区间的最大平均值
	{
		average[t] = 0;
		if (m + t > n)//从t开始不可能有长度大于等于m的子数组
			continue;
		for (int i = t;i < m+t;i++)
		{
			average[t] += a[i];
		}
		average[t] /= m; //初始化平均值
		int length = m;
		for (int j = m;j < n;j++)
		{
			if (a[j] > average[t])
			{
				average[t] = (average[t] * length + a[j]) / (length + 1);
				length++;
			}
			else {
				break;
			}
		}
	}
	double max_average = average[0];
	for (int i = 0;i < n;i++)
	{
		if (average[i] > max_average)
			max_average = average[i];
	}
	
	cout << int(max_average * 1000);
	return 0;

}