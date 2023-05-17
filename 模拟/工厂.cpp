#include<iostream>
using namespace std;
int main()
{
	int a, m;
	cin >> a >> m;
	int num = a;
	for (int i = 0;i < 100000;i++)
	{
		if (num % m == 0)
		{
			cout << "Yes";
			return 0;
		}
		num += num % m;
		
	}
	cout << "No";
	return 0;
}