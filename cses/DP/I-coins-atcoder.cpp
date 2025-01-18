

#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
// typedef unsigned int ull;
typedef long double lld;
#define Tushar                  \
    cin.sync_with_stdio(false); \
    cin.tie(0);                 \
    cout.tie(0)

// #define dbg(x) cerr << #x <<" = "; cerr<<x<<" "; cerr << endl;
#define itn long long

#define int long long int
// #define double long double
#define MAX LLONG_MAX
#define MIN LLONG_MIN
#define endl '\n'
#define vin(a)                           \
    for (int i = 0; i < (a).size(); i++) \
        cin >> a[i];
#define vout(a)                        \
    for (int i = 0; i < a.size(); i++) \
        cout << a[i] << ' ';           \
    cout << endl;
#define vpin(a)                          \
    for (int i = 0; i < (a).size(); i++) \
        cin >> a[i].first;               \
    for (int i = 0; i < (a).size(); i++) \
        cin >> a[i].second;
#define vpin2(a)                         \
    for (int i = 0; i < (a).size(); i++) \
        cin >> a[i].first >> a[i].second;
#define vpout(a)                                          \
    for (int i = 0; i < a.size(); i++)                    \
        cout << a[i].first << ' ' << a[i].second << endl; \
    cout << endl;
#define sin(a, n)               \
    for (int i = 0; i < n; i++) \
    {                           \
        int temp;               \
        cin >> temp;            \
        a.insert(temp);         \
    }
#define sout(a)           \
    for (auto i : a)      \
        cout << i << ' '; \
    cout << endl;
#define cout(x) cout << setprecision(20) << x << endl
#define isort(v) sort(v.begin(), v.end())
#define dsort(v) sort(v.begin(), v.end(), greater<int>());
#define PI 3.1415926535897932384626433832795
// #define ull unsigned long long int
// #define int int64_t
#define vi vector<int>
#define vii vector<pair<int, int>>
#define vs vector<string>
#define vc vector<char>
#define vb vector<bool>
#define pb push_back
#define loop(a, b, i) for (int i = a; i < b; i++)
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define r(x)               \
    {                      \
        cout << x << endl; \
        return;            \
    }
#define read(x) \
    int x;      \
    cin >> x
#define all(x) (x).begin(), (x).end()
/*---------------------------------------------------------------------------------------------------------------------------------------------*/
#ifdef ONLINE_JUDGE
#define debug(x)
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/rope>
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#else
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#endif

#define all(x) (x).begin(), (x).end()

#define mp make_pair
#define ff first
#define ss second

void _print(ll t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

// 4e7 will give mle 


const int MOD = 1000000007;

void precompute(){

}
double dp[3005][3005];
double ans = 0;
double f(vector<double>& arr,int i,int x){
    if(i==arr.size()){
        if(x<=0) return 1.0;
        else return 0.0;
    } 
    if(dp[i][x]>=0) return dp[i][x];

    // double ans = 0;
    ans = f(arr,i+1,x-1)*arr[i] + f(arr,i+1,x)*(1-arr[i]);
    return dp[i][x]=ans;
}


inline void solve(){
    read(n);vector<double> arr(n);vin(arr);
    memset(dp,-1,sizeof(dp));
    
    cout<<setprecision(10)<<f(arr,0,(n+1)/2);

}

int32_t main()
{

    Tushar;
    precompute();
    int t=1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}

