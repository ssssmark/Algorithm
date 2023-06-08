//线段树模板题。已知一个数列，你需要进行下面两种操作: 将某区间每一个数加上k ，求出某区间每一个数的和。
#include <iostream>
using namespace std;
#define int long long
const int MAXN = 1e5 + 5;
int arr[MAXN], tree[MAXN * 4], lazy[MAXN * 4];

void build(int node, int start, int end) {
    if (start == end) {
        tree[node] = arr[start];
    }
    else {
        int mid = (start + end) / 2;
        build(node * 2, start, mid);
        build(node * 2 + 1, mid + 1, end);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}

void update(int node, int start, int end, int l, int r, int val) {
    if (lazy[node] != 0) {
        tree[node] += (end - start + 1) * lazy[node];
        if (start != end) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (start > end || start > r || end < l) return;
    if (start >= l && end <= r) {
        tree[node] += (end - start + 1) * val;
        if (start != end) {
            lazy[node * 2] += val;
            lazy[node * 2 + 1] += val;
        }
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, l, r, val);
    update(node * 2 + 1, mid + 1, end, l, r, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int start, int end, int l, int r) {
    if (start > end || start > r || end < l) return 0;
    if (lazy[node] != 0) {
        tree[node] += (end - start + 1) * lazy[node];
        if (start != end) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (start >= l && end <= r) return tree[node];
    int mid = (start + end) / 2;
    return query(node * 2, start, mid, l, r) + query(node * 2 + 1, mid + 1, end, l, r);
}

signed main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    build(1, 1, n);
    for (int i = 0; i < m; i++) {
        int op, l, r, val;
        cin >> op >> l >> r;
        if (op == 1) {
            cin >> val;
            update(1, 1, n, l, r, val);
        }
        else {
            cout << query(1, 1, n, l, r) << endl;
        }
    }
    return 0;
}

