#include <bits/stdc++.h>
using namespace std;

#define int long long
#define Tushar ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define vin(a) for (auto &x : (a)) cin >> x
#define read(x) int x; cin >> x

template<typename Node, typename Update>
struct SegTree {
    vector<Node> tree;
    vector<int> arr;
    int n, s;

    SegTree(int a_len, vector<int> &a) {
        arr = a;
        n = a_len;
        s = 1;
        while (s < 2 * n) s <<= 1;
        tree.resize(s);
        fill(tree.begin(), tree.end(), Node());
        build(0, n - 1, 1);
    }

    void build(int start, int end, int index) {
        if (start == end) {
            tree[index] = Node(arr[start]);
            return;
        }
        int mid = (start + end) / 2;
        build(start, mid, 2 * index);
        build(mid + 1, end, 2 * index + 1);
        tree[index].merge(tree[2 * index], tree[2 * index + 1]);
    }

    void update(int start, int end, int index, int query_index, Update &u) {
        if (start == end) {
            u.apply(tree[index]);
            return;
        }
        int mid = (start + end) / 2;
        if (mid >= query_index)
            update(start, mid, 2 * index, query_index, u);
        else
            update(mid + 1, end, 2 * index + 1, query_index, u);
        tree[index].merge(tree[2 * index], tree[2 * index + 1]);
    }

    Node query(int start, int end, int index, int left, int right) {
        if (start > right || end < left)
            return Node();
        if (start >= left && end <= right)
            return tree[index];
        int mid = (start + end) / 2;
        Node l, r, ans;
        l = query(start, mid, 2 * index, left, right);
        r = query(mid + 1, end, 2 * index + 1, left, right);
        ans.merge(l, r);
        return ans;
    }

    int find_kth_one(int start, int end, int index, int k) {
        if (start == end) return start;
        int mid = (start + end) / 2;
        if (tree[2 * index].val >= k)
            return find_kth_one(start, mid, 2 * index, k);
        else
            return find_kth_one(mid + 1, end, 2 * index + 1, k - tree[2 * index].val);
    }

    void make_update(int index, int val) {
        Update new_update(val);
        update(0, n - 1, 1, index, new_update);
    }

    Node make_query(int left, int right) {
        return query(0, n - 1, 1, left, right);
    }
};

struct Node1 {
    int val;
    Node1() : val(0) {}
    Node1(int p1) : val(p1) {}
    void merge(Node1 &l, Node1 &r) {
        val = l.val + r.val;
    }
};

struct Update1 {
    int val;
    Update1(int p1) : val(p1) {}
    void apply(Node1 &a) {
        a.val = 1 - a.val;
    }
};

void solve() {
    read(n); read(m);
    vector<int> arr(n); vin(arr);
    SegTree<Node1, Update1> seg(n, arr);

    for (int i = 0; i < m; i++) {
        read(a); read(b);
        if (a == 1) {
            seg.make_update(b, 1 - arr[b]);
            arr[b] = 1 - arr[b];
        } else {
            cout << seg.find_kth_one(0, n - 1, 1, b + 1) << endl;
        }
    }
}

int32_t main() {
    Tushar;
    solve();
    return 0;
}
