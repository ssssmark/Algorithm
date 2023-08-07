#include<iostream>
#include<algorithm>
#include<math.h>
#include<unordered_set>
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int solve(int k, int c, int n)
{
    int ans = 0;
    for (int a = n;a <= (c - n) / k;a++)
    {
        int b = c - k * a;
        if (b >= n && b < c) {
            if (c % b == 0 && gcd(a, b) >= n)
                ans++;
        }
        
    }
    return ans;
}

int main()
{
    int q;
    std::cin >> q;
    for (int i = 0;i < q;i++)
    {
        int k, c, n;
        std::cin >> k >> c >> n;
        int ans = solve(k, c, n);
        std::cout << ans << "\n";
    }


    return 0;
}