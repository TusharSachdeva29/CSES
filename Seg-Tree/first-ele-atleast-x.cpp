#include <bits/stdc++.h>
using namespace std;

typedef int ll;
#define int long long int
#define itn long long 
#define Tushar ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl '\n'
#define vin(a) for (auto &x : (a)) cin >> x
#define vout(a) for (const auto &x : (a)) cout << x << ' '; cout << endl
#define vpin(a) for (auto &x : (a)) cin >> x.first >> x.second
#define vpout(a) for (const auto &x : (a)) cout << x.first << ' ' << x.second << endl
#define all(x) (x).begin(), (x).end()
#define isort(v) sort(all(v))
#define dsort(v) sort(all(v), greater<int>())
#define pb push_back
#define ff first
#define ss second
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define debug(x) cerr << #x << " = " << x << endl
#define show(x) cerr << #x << ": "; debug_segtree(x); cerr << endl
// #define r(x) { cout << x << endl; return; }
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(int x) { cerr << x; }
void _print(string x) { cerr << x; }
void _print(char x) { cerr << x; }
void _print(double x) { cerr << x; }
void _print(long double x) { cerr << x; }
void _print(unsigned long long x) { cerr << x; }

template <class T, class V> void _print(pair<T, V> p) { cerr << "{"; _print(p.ff); cerr << ", "; _print(p.ss); cerr << "}"; }
template <class T> void _print(vector<T> v) { cerr << "[ "; for (const auto &x : v) { _print(x); cerr << " "; } cerr << "]"; }
template <class T> void _print(set<T> v) { cerr << "{ "; for (const auto &x : v) { _print(x); cerr << " "; } cerr << "}"; }
template <class T> void _print(multiset<T> v) { cerr << "{ "; for (const auto &x : v) { _print(x); cerr << " "; } cerr << "}"; }
template <class T, class V> void _print(map<T, V> v) { cerr << "{ "; for (const auto &x : v) { _print(x); cerr << " "; } cerr << "}"; }
template<typename T>
void __print(const T &x) { cerr << x; }
void __print(const string &x) { cerr << '"' << x << '"'; }


using vi = vector<int>;
using vii = vector<pair<int, int>>;
using vs = vector<string>;
using pii = pair<int, int>;
using vvi = vector<vector<int>>;

#define loop(a, b, i) for (int i = (a); i < (b); ++i)
#define read(x) int x; cin >> x
#define PI 3.14159265358979323846
#define MAX LLONG_MAX
#define MIN LLONG_MIN

const int MOD = 1000000007;
#define ll long long 


template<typename Node, typename Update>
struct SegTree{
    vector<Node> tree;
    vector<ll> arr; // type may change
    int n;
    int s;
    SegTree(int a_len, vector<ll> &a) { // change if type updated
        arr = a;
        n = a_len;
        s = 1;
        while(s < 2 * n){
            s = s << 1;
        }
        tree.resize(s); fill(all(tree), Node());
        build(0, n - 1, 1);
    }
    void build(int start, int end, int index)  // Never change this
    {
        if (start == end)   {
            tree[index] = Node(arr[start]);
            return;
        }
        int mid = (start + end) / 2;
        build(start, mid, 2 * index);
        build(mid + 1, end, 2 * index + 1);
        tree[index].merge(tree[2 * index], tree[2 * index + 1]);
    }
    void update(int start, int end, int index, int query_index, Update &u)  // Never Change this
    {
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
    Node query(int start, int end, int index, int left, int right,int val) { // Never change this
        if(tree[index].val<val){
            return -1;
        }
        if(start==end){
            return start;
        }
        int mid = (start + end) / 2;
        Node l, r, ans;
        
    
        if(tree[2*index].val>=val){
            return query(start, mid, 2 * index, left, right,val);
        }else{
            return query(mid + 1, end, 2 * index + 1, left, right,val);
        }
        // ans.merge(l, r);
        // return ans;
    }
    void make_update(int index, ll val) {  // pass in as many parameters as required
        Update new_update = Update(val); // may change
        update(0, n - 1, 1, index, new_update);
    }
    Node make_query(int left, int right,int val) {
        return query(0, n - 1, 1, left, right,val);
    }
};

struct Node1 {
    ll val;
    Node1() { // Identity element
        val = -1e9;
    }
    Node1(ll p1) {  // Actual Node
        val = p1; // may change
    }
    void merge(Node1 &l, Node1 &r) { // Merge two child nodes
        val=max(l.val,r.val);  
    } 
};

struct Update1 {
    ll val; 

    Update1(ll p1) { // Actual Update
        val = p1; // may change
    }
    void apply(Node1 &a) { // apply update to given node
        a.val = val; // may change
    }
};
void solve() {
    read(n);read(m);
    vi arr(n);vin(arr);
	SegTree<Node1 , Update1> seg = SegTree<Node1 , Update1>(n,arr);
    
    for(int i=0;i<m;i++){
        read(k);
        if(k==1){
            read(l);read(r);
			seg.make_update(l,r);
		}else{
            read(x);
			cout<<seg.make_query(0,n-1,x).val<<endl;
		}
    }
}

int32_t main() {
    Tushar;
    // precompute();
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}