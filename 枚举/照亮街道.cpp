#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int main()
{
	int n, L;
	cin >> n >> L;
	double r=0;
	double a[1005] = {};
	
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	double maxgap = 0;
	for (int i = 0;i < n - 1;i++)
	{
		if (maxgap < a[i + 1] - a[i])
			maxgap = a[i + 1] - a[i];
	}
	r =max( 0.5 * maxgap,max(a[0],L-a[n-1]));
	cout <<fixed<< setprecision(2) << r;
	return 0;
}