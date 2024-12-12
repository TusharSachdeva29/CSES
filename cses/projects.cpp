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
#define vin2(a, rows, cols)              \
    for (int i = 0; i < (rows); i++)     \
        for (int j = 0; j < (cols); j++) \
            std::cin >> (a)[i][j];

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

// TIPS :-> brute force do exist like number can be 0-9 only rememnr tht qs in which 26+26^2+26^3>1000
const int MOD = 1000000007;

void precompute()
{
}

int n;
// vvi arr;
int dp[200009];

// int f(int i, int last_taken){
//     if(i>=n) return 0;
//     if(dp[i][last_taken+1]!=-1) return dp[i][last_taken+1];

//     int ans = MIN;
//     if(last_taken==-1 or arr[i][0]>arr[last_taken][1]){
//         ans = max(arr[i][2]+f(i+1,i) , f(i+1,last_taken));
//     }
//     else {
//         ans = max(ans, f(i+1,last_taken));
//     }
//     return dp[i][last_taken+1] = ans;

// }

// instead of doing this if u apply ur little brain and just eliminate the last_taken variable use , okaay so just sort the
// elements on basis of start time and just do binary search (upper_bound) where start time of j greater than end time of i

// **  RECURRANCE : f(i) = max(f(i+1) , arr[i][2] + f(j) ; where j as mentioned above) below is the recursive implementation 👇
// so it is basically , ye waala idx maine lia hain ab btayo agla konsa le skta hun.. good problem

// int f(int i){
//     if(i>=n) return 0;
//     if(dp[i]!=-1) return dp[i];
//     int j = upper_bound(arr.begin(), arr.end(), vector<int>{arr[i][1], INT_MAX},
//                           [](const vector<int>& a, const vector<int>& b) {
//                               return a[0] < b[0];
//                           })-arr.begin();
//     return dp[i]=max(f(i+1),arr[i][2]+f(j));
// }

// instead of making 2d vector make a struct
struct Project
{
    int start, end, price;
};
const int maxn = 2e5 + 1;
vector<Project> a(maxn);

int f(int index){
    if (index == n)
        return 0;
    if (dp[index] != -1)
        return dp[index];

    int newIndex = n, left = index + 1, right = n - 1;

    while (left <= right){
        int mid = (left + right) / 2;
        if (a[mid].start > a[index].end){
            newIndex = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    return dp[index] = max(f(index + 1), a[index].price + f(newIndex));
}

inline void solve()
{
    cin >> n;
    memset(dp, -1, sizeof(dp));
    a.resize(n);

    for (int i = 0; i < n; i++)
        cin >> a[i].start >> a[i].end >> a[i].price;
    sort(a.begin(), a.end(), [&](auto aa, auto b)
         { return aa.start < b.start; });
    cout << f(0);
}

int32_t main()
{

    Tushar;
    precompute();
    int t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}
