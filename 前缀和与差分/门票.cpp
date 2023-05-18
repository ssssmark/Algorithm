//MT2057
#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int main()
{
	int n, ticket;
	cin >> n >> ticket;
	int *a= new int[n];
	int* method = new int[n];//method[i]表示从i开始的子数组能抵消门票的个数
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	for (int j = 0;j < n;j++)
	{
		int sum = 0;
		method[j] = 0;
		int length = 1;
		for (int t = j;t < n;t++)
		{
			sum += a[t];
			if (sum/length >= ticket)
			{
				method[j] += 1;
				
			}
			length++;
		}
	}
	int total = 0;
	for (int i = 0;i < n;i++)
	{
		total += method[i];
	}
	cout << total % int(1e9 + 7);
	return 0;
}