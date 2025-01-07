#include <vector>
#include <iostream>
using namespace std;

#define ll long long

// Node structure for Segment Tree
struct Node1 {
    ll val;
    Node1() {
        val = 0;
    }
    Node1(ll p1) {
        val = p1;
    }
    void merge(Node1 &l, Node1 &r) {
        val = l.val + r.val;
    }
};

// Update structure for Segment Tree
struct Update1 {
    ll val;
    Update1(ll p1) {
        val = p1;
    }
    void apply(Node1 &a) {
        a.val = val;
    }
};

template<typename Node, typename Update>
class SegTree {
    vector<Node> tree;
    vector<ll> arr;
    int n, s;

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
        Node l = query(start, mid, 2 * index, left, right);
        Node r = query(mid + 1, end, 2 * index + 1, left, right);
        Node ans;
        ans.merge(l, r);
        return ans;
    }

public:
    SegTree(int a_len, const vector<ll> &a) {  // Accepting a const reference
        arr = a;
        n = a_len;
        s = 1;
        while (s < 2 * n) s <<= 1;
        tree.resize(s, Node());
        build(0, n - 1, 1);
    }

    void make_update(int index, ll val) {
        Update new_update(val);
        update(0, n - 1, 1, index, new_update);
    }

    Node make_query(int left, int right) {
        return query(0, n - 1, 1, left, right);
    }
};