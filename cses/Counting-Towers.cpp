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
const int maxi = 1000005;
vvi dp(maxi,vi(2,0));

void precompute(){
    dp[0][0]=1;dp[0][1]=1;
    for(int i=1;i<=maxi-3;i++){
        dp[i][0] = (2*dp[i-1][0])%MOD+(dp[i-1][1])%MOD;dp[i][0]%=MOD;
        dp[i][1] = (4*dp[i-1][1])%MOD + (dp[i-1][0])%MOD;dp[i][1]%=MOD;
    }
}

// 0 -> HORIZONTAL cell(can also be represented as width 2 for horizontal and 1 widht for evrtical)
// 1 -> VERTICAL cell


// STATE DEFINFATION :->
// DP[I][0] = NUMBER OF WAYS TO FILL THE GRID ITH ROW TO N-1TH ROW SUCH THAT THERER IS A HORIZONTAL BLOCK TRYING TO EXTEND FROM THE (I-1)TH ROW.[[**** DP[I][0] = DP[I+1][0](ith cell closed new horizontal cell starting extend) + DP[I+1][1](vertical cell starting horixontal closed at i) + DP[I+1][0](ith cell decided to extend) ****]]

// DP[I][1] = 4*DP[I+1][1](left extend, right extend , both extend , boht closed and both vertical new) + DP[I+1][0](both vertical closed and new horizontal caell extend) 

// BASE CASE : DP[N][0] = 1 , DP[N][1] = 1;

//FINAL SUB PROBLEM : dp[1][0] + dp[1][1] // 0 based means 1st row , zeroth row no row is trying to extend so either put 0(horizontal) or put 1(veritcal)


int n;
inline void solve(){
    cin>>n;
    cout<<(dp[n-1][0]+dp[n-1][1])%MOD<<endl;
}

int32_t main()
{

    Tushar;
    
    precompute();
    int t = 1;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}