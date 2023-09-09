#include<iostream> 
using namespace std;
const long long mod = 1e9 + 7;
//快速幂模版 将n按二进制分解
long long int quickpower(long long  a, long long  n)
{
    a %= mod;
    long long int ans = 1; // n = 0 时候不进循环
    while (n)
    {
        if (n & 1)
            ans =ans* a%mod;
        a = a*a%mod;
        n >>= 1;
    }
    return ans;
}
int main()
{
    long long int k;
    long long int ans;
    cin >> k;
    if (k % 2 == 0)
    {
        long long int temp = k / 2;
        ans = quickpower(4, temp) * quickpower(5, temp)%mod;
    }
    else if (k % 2 == 1)
    {
        long long int temp = k / 2;
        ans = quickpower(4, temp) * quickpower(5, temp+1)%mod;
    }
    cout << ans;
    return 0;
}