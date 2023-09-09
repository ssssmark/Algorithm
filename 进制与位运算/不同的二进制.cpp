#include<iostream>
#include<math.h>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int to_decimal(string a,int n) {
    int ans = 0;
    for (int i = n-1, j = 0;i >=0;i--, j++)
    {
        ans += (a[i] - '0') * pow(2, j);
    }
    return ans;
}

int main()
{
    int i = 0;
    vector<string> nums;
    string s;
    while (cin >> s)
    {
        nums.push_back(s);
    }
    int n = nums.size();
    map<int, bool>mp;
    for (int i = 0;i < n;i++)
    {
        int temp = to_decimal(nums[i],n);
        mp[temp] = true;
    }
    string ans = "";
    for (int i = 0;i < (1 << n);i++)
    {
        if (!mp[i])
        {
            int b = i;
            int k = n;
            while (k--)
            {
                if (b & 1)
                    ans = '1'+ans;
                else
                    ans = '0'+ans;
                b >>= 1;
            }
            break;
        }
        
    }
    cout << ans << endl;
    return 0;
}