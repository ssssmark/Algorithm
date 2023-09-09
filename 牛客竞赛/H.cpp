#include<iostream>
#include<vector>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin >> n;
    int nn = n, len = 0;
    while (nn) {
        len++, nn /= 10;
    }
    int ans = 0;
    int base = 9, t = 1;
    for (int i = 0;i < len - 1;i++) {
        ans += base * (i + 1), base *= 10;
        t *= 10;
    }
    ans += len * (n - t + 1);
    cout << ans << "\n";
}
signed main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}