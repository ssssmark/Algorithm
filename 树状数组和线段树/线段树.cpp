//线段树模板题。已知一个数列，你需要进行下面两种操作: 将某区间每一个数加上k ，求出某区间每一个数的和。
#include <iostream>
#include <vector>
using namespace std;
# define int long long
class SegmentTree {
public:
    SegmentTree(int n) : nums(n), tree(n * 4) {}

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = nums[start];
        }
        else {
            int mid = (start + end) / 2;
            build(node * 2, start, mid);
            build(node * 2 + 1, mid + 1, end);
            tree[node] = tree[node * 2] + tree[node * 2 + 1];
        }
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            nums[idx] += val;
            tree[node] += val;
        }
        else {
            int mid = (start + end) / 2;
            if (idx >= start && idx <= mid) {
                update(node * 2, start, mid, idx, val);
            }
            else {
                update(node * 2 + 1, mid + 1, end, idx, val);
            }
            tree[node] = tree[node * 2] + tree[node * 2 + 1];
        }
    }

    int query(int node, int start, int end, int l, int r) {
        if (start > r || end < l) {
            return 0;
        }
        else if (start >= l && end <= r) {
            return tree[node];
        }
        else {
            int mid = (start + end) / 2;
            int sumLeft = query(node * 2, start, mid, l, r);
            int sumRight = query(node * 2 + 1, mid + 1, end, l, r);
            return sumLeft + sumRight;
        }
    }

private:
    vector<int> nums;
    vector<int> tree;
};

signed main()
{
    int n, m;
    cin >> n >> m;

    SegmentTree st(n);
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        st.update(1, 1, n, i + 1, num);
    }

    while (m--) {
        int op, x, y, k;
        cin >> op >> x >> y;
        if (op == 1) {
            cin >> k;
            for (int i = x; i <= y; i++) {
                st.update(1, 1, n, i, k);
            }
        }
        else {
            cout << st.query(1, 1, n, x, y) << endl;
        }
    }

    return 0;
}
