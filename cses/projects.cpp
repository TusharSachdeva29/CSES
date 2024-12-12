#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int long long
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
#define r(x) { cout << x << endl; return; }
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)

// Debugging templates
#ifdef ONLINE_JUDGE
#define dbg(x)
#else
#define dbg(x) cerr << #x << " = "; _print(x); cerr << endl
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

// Common type aliases
using vi = vector<int>;
using vii = vector<pair<int, int>>;
using vs = vector<string>;
using pii = pair<int, int>;
using vvi = vector<vector<int>>;

// Utility macros
#define loop(a, b, i) for (int i = (a); i < (b); ++i)
#define read(x) int x; cin >> x
#define PI 3.14159265358979323846
#define MAX LLONG_MAX
#define MIN LLONG_MIN

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
