/*
��һ�����鳤��Ϊn����һ�����ȴ��ڵ���m�������䣬ʹ����������Ԫ��ƽ��ֵ���
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
	for(int t=0;t<n;t++)//�����t��ʼ���Ȳ�С��m������������ƽ��ֵ
	{
		average[t] = 0;
		if (m + t > n)//��t��ʼ�������г��ȴ��ڵ���m��������
			continue;
		for (int i = t;i < m+t;i++)
		{
			average[t] += a[i];
		}
		average[t] /= m; //��ʼ��ƽ��ֵ
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