#include<iostream>
using namespace std;
const int mod = 998244353;
long long int quickpow(long long  a, long long n)
{
	a %= mod;
	long long int ans = 1;
	while (n > 0)
	{
		if (n & 1)
			ans =ans*a%mod;
		a = a*a%mod;
		n >>= 1;
	}
	return ans;
}
int main()
{
	int n;
	cin >> n;
	int ret = 0;
	for (int i = 1;i <= n;i++)
	{
		ret += quickpow(i, i);
		ret %= mod;
	}
	cout << ret;
	return 0;
}