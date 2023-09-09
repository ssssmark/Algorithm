#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int cntSubsegments(vector<int>& P) {
    int n = P.size();
    int ans = 0;
    vector<int> left(n), right(n);

    for (int i = 0; i < n; i++) {
        int pos = lower_bound(P.begin(), P.begin() + i, P[i]) - P.begin();
        left[i] = pos + 1;
    }

    for (int i = n - 1; i >= 0; i--) {
        int pos = upper_bound(P.begin() + i, P.end(), P[i]) - P.begin();
        right[i] = n - pos;
    }

    for (int i = 0; i < n; i++) {
        ans += left[i] * right[i];
    }

    return ans;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0;i < T;i++)
    {
        int n;
        cin >> n;
        vector<int> P(n);
        for (int i = 0;i < n;i++)
        {
            cin >> P[i];
        }
        cout << cntSubsegments(P) << endl;
    }
    return 0;


}