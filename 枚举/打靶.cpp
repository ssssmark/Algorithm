//MT2014 ´ò°Ð
#include<iostream>
#include<vector>
using namespace std;
int a[100010] = {};
int main()
{
	int num = 0;
	int n;
	cin >> n;
	while (n--)
	{
		int h;
		cin >> h;
		if (a[h] != 0)
		{
			a[h]--;
		}
		else {
			num++;
		}
		a[h - 1]++;
	}
	cout << num;
	return 0;
}