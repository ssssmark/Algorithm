#include<iostream>
using namespace std;
int a[200005] = {};
int main()
{
	int n;
	int sum = 0;
	int b = 0;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
	}

	for (int i = 1;i < n;i++)
	{
		if (b > 0)
		{
			b += a[i];
		}
		else {
			b = a[i];
		}
		if (b > sum)
		{
			sum = b;
		}
	}
	cout << sum;
	return 0;
}