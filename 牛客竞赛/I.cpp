#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int matchCount(const vector<string>& patterns) {
    int n = patterns.size();
    int count = 0;

    for (int i = 0; i < (1<<n); i++) {
        string s;

        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                s += '1';
            }
            else {
                s += '0';
            }
        }

        
        for (int j = 0; j < n; j++) {
            bool match = true;
            for (int k = 0; k < patterns[j].length(); k++) {
                if (patterns[j][k] != '?' && patterns[j][k] != s[k]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                count++;
                break;
            }
        }

        
    }

    return count;
}

int main() {

    int n;
    cin >> n;
    vector<string> patterns(n);
    for (int i = 0; i < n; i++) {
        cin >> patterns[i];
    }

    int ans = matchCount(patterns);
    cout << ans % 998244353;

    return 0;
}