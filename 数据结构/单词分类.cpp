#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_set<string> a;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int b[26] = { 0 };
        for (int j = 0; j < s.length(); j++) {
            b[s[j] - 'A']++;
        }
        string str;
        for (int j = 0; j < 26; j++) {
            str += to_string(b[j]);
        }
        a.insert(str);
    }

    cout << a.size() << endl;
    return 0;
}
