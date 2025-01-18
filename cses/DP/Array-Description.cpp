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

int n;int m;vi arr;
// ALMOST 95 PERSENT OF DP PROBEM WITH ARRAY COMES WITH THE THINKING OF PREFIX APPROACH

// DP[I][K] = NUMEBR OF PREFIX OF "LENGTH" = I THAT CAN BE FORMED SUCH THAT THE LAST ELEMENT OF THE PREFIX = K , this now drop down to 3 sub problems dp[i-1][k-1] , dp[i-1][k] , dp[i-1][k] 

// BASE CASE : DP[1][K] = 1 IF ARR[0] = K OR ARR[0] = 0; 'I' YAHA PR LENGTH DARSHARA NAAKE INDEX

// FINAL SUB PROBEM :  DP[N][1] + DP[N][2] + .. + DP[N][M]

    // EASY TO UNDERSTAND CAN SEE THIS 👇
    // for(int i=1 ; i<n ; i++){
    //     if(v[i]==0){
    //         for(int j=1 ; j<=m ; j++){
    //             if(j>0) dp[i][j] += dp[i-1][j-1];
    //             dp[i][j]%=M;
    //             dp[i][j] += dp[i-1][j];
    //             dp[i][j]%=M;
    //             if(j<m) dp[i][j] += dp[i-1][j+1];
    //             dp[i][j]%=M;
    //         }
    //     }
    //     else{
    //         if(v[i]>0) dp[i][v[i]] += dp[i-1][v[i]-1];
    //         dp[i][v[i]]%=M;
    //         dp[i][v[i]] += dp[i-1][v[i]];
    //         dp[i][v[i]]%=M;
    //         if(v[i]<m) dp[i][v[i]] += dp[i-1][v[i]+1];
    //         dp[i][v[i]]%=M;
    //     }
    // }

itn dp[100005][105];

bool ok(int x , int m){
    return x>=1 and x<=m;
}

inline void solve(){
    cin>>n>>m;arr.resize(n);vin(arr);
    memset(dp,0,sizeof(dp));
    // for 2d array use .assign meathod
    for(int i=1;i<=m;i++){
        if(arr[0]==0 or arr[0]==i) dp[0][i]=1;
    }
    // CLEAR CODE ::::
    for(itn i=1;i<n;i++){
        for(itn k=1;k<=m;k++){
            if(arr[i]!=0 and arr[i]!=k) dp[i][k]=0;
            else {
                for(itn prev = k-1;prev<= k+1; prev++){
                    if(!ok(prev,m)) continue;
                    dp[i][k] = (dp[i][k]+dp[i-1][prev])%MOD;
                
                }
            }
        }
    }
    itn ans = 0;
    for(int i=1;i<=m;i++){
        ans = (ans + dp[n-1][i]) % MOD;
    }
    cout<<ans;
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
