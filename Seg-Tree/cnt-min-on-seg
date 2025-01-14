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
struct SegTree {
	vector<Node> tree;
	vector<ll> arr;
	int n;
	int s;
	SegTree(int a_len, vector<ll> &a) {
		arr = a;
		n = a_len;
		s = 1;
		while(s < 2 * n){
			s = s << 1;
		}
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
	void make_update(int index, ll val) {
		Update new_update = Update(val);
		update(0, n - 1, 1, index, new_update);
	}
	Node make_query(int left, int right) {
		return query(0, n - 1, 1, left, right);
	}
};

struct Node1 {
	ll val;
	ll count;
	Node1() {
		val = MAX;
		count = 0;
	}
	Node1(ll p1) {
		val = p1;
		count = 1;
	}
	void merge(Node1 &l, Node1 &r) {
		if(l.val<r.val){
			val = l.val;
			count = l.count;
		}else if(l.val>r.val){
			val = r.val;
			count = r.count;
		}else{
			val = l.val;
			count = l.count + r.count;
		}
	}
};
struct Update1 {
	ll val;
	Update1(ll p1) {
		val = p1;
	}
	void apply(Node1 &a) {
		a.val = val;
		a.count = 1;
	}
};



void solve() {
    read(n);read(m);
    vi arr(n);vin(arr);
	SegTree<Node1 , Update1> seg = SegTree<Node1 , Update1>(n,arr);
    
    for(int i=0;i<m;i++){
        read(k);read(l);read(r);
	
        if(k==1){
			seg.make_update(l,r);
		}else{
			cout<<seg.make_query(l,r-1).val<<" "<<seg.make_query(l,r-1).count<<endl;
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