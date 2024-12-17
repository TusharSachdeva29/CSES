#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define itn long long  
#define int long long int

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
#define debug(x) cerr << #x << " = "; _print(x); cerr << endl
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
using vc = vector<char>;
using vii = vector<pair<int, int>>;
using vs = vector<string>;
using pii = pair<int, int>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;

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
itn dp[505][63000];
// int f(int n,int i,int target){
//     if(target==0){
//         return 1;
//     }
//     if(i==n or target<0) return 0;
//     if(dp[i][target]!=-1) return dp[i][target]%MOD;
//     dp[i][target] = f(n,i+1,target-i)+f(n,i+1,target);
//     return dp[i][target]%MOD;
// }

inline void solve(){
    cin>>n;memset(dp,0,sizeof(dp));
    int total = n*(n+1)/2;
    
    if(total%2!=0) {cout<<0;return;}
    total/=2;
    dp[n][0] = 1;
    for(int i=1;i<=total;i++)dp[n][i]=0;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=total;j++){
            if(j==0) dp[i][j] = 1;
            else if(j<i) dp[i][j] = 0;
            else dp[i][j] = (dp[i+1][j-i]+dp[i+1][j])%MOD;
        }
    }
    cout<<dp[1][total]%MOD;
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
