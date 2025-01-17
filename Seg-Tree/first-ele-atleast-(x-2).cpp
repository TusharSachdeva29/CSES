#include <bits/stdc++.h>
using namespace std;

typedef int ll;
#define int long long int
#define Tushar                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
#define endl '\n'
#define vin(a)          \
    for (auto &x : (a)) \
    cin >> x
#define vout(a)               \
    for (const auto &x : (a)) \
        cout << x << ' ';     \
    cout << endl
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ff first
#define ss second

using vi = vector<int>;

const int MOD = 1000000007;

template <typename Node, typename Update>
struct SegTree
{
    vector<Node> tree;
    vector<ll> arr;
    int n;
    int s;

    SegTree(int a_len, vector<ll> &a)
    {
        arr = a;
        n = a_len;
        s = 1;
        while (s < 2 * n)
        {
            s = s << 1;
        }
        tree.resize(s);
        fill(all(tree), Node());
        build(0, n - 1, 1);
    }

    void build(int start, int end, int index)
    {
        if (start == end)
        {
            tree[index] = Node(arr[start]);
            return;
        }
        int mid = (start + end) / 2;
        build(start, mid, 2 * index);
        build(mid + 1, end, 2 * index + 1);
        tree[index].merge(tree[2 * index], tree[2 * index + 1]);
    }

    void update(int start, int end, int index, int query_index, Update &u)
    {
        if (start == end)
        {
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

    Node query(int start, int end, int index, int left, int right, int l, int x)
    {
        if (end < l || start > right)
        {
            return Node(-1); // Out of range
        }
        if (tree[index].val < x)
        {
            return Node(-1); // Does not satisfy condition
        }
        if (start == end)
        {
            return Node(start); // Found the index
        }
        int mid = (start + end) / 2;
        Node left_result = query(start, mid, 2 * index, left, right, l, x);
        if (left_result.val != -1)
        {
            return left_result;
        }
        return query(mid + 1, end, 2 * index + 1, left, right, l, x);
    }

    void make_update(int index, ll val)
    {
        Update new_update = Update(val);
        update(0, n - 1, 1, index, new_update);
    }

    Node make_query(int l, int n, int x)
    {
        return query(0, n - 1, 1, l, n - 1, l, x);
    }
};

struct Node1
{
    ll val;
    Node1()
    {
        val = -1e9; // Identity element
    }
    Node1(ll p1)
    {
        val = p1;
    }
    void merge(Node1 &l, Node1 &r)
    {
        val = max(l.val, r.val);
    }
};

struct Update1
{
    ll val;
    Update1(ll p1)
    {
        val = p1;
    }
    void apply(Node1 &a)
    {
        a.val = val;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<ll> arr(n);
    vin(arr);
    SegTree<Node1, Update1> seg = SegTree<Node1, Update1>(n, arr);

    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        if (k == 1)
        {
            int idx, val;
            cin >> idx >> val;
            seg.make_update(idx, val);
        }
        else if (k == 2)
        {
            int x, l;
            cin >> x >> l;
            Node1 result = seg.make_query(l, n, x);
            cout << (result.val == -1 ? -1 : result.val) << endl;
        }
    }
}

int32_t main()
{
    Tushar;
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
