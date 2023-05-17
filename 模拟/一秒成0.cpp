#include<iostream>
using namespace std;
int main()
{
	int n;
	int op=0;
	cin >> n;
	while (n)
	{
		if (n % 2 == 0)
		{
			n = n / 2;
		}
		else
		{
			n = n - 1;
		}
		op++;
	}
	cout << op;
	return 0;
}