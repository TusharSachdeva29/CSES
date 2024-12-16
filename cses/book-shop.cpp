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

int n;int x;
vi price;
vi pages;
int dp[100005];

//dp[money_left] = signify max pages i can buy with that much monwy left
// i want to buy maximum pages within x very similar to knapsack problem

inline void solve(){
    cin>>n>>x;price.resize(n);pages.resize(n);vin(price);vin(pages);
    fill(dp,dp+x+1,0);

    // for(itn i=1;i<=x;i++){
    //     for(itn j=0;j<n;j++){
    //         if(i>=price[j])dp[i] = max(dp[i],pages[j]+dp[i-price[j]]);
    //     }
    // }
    
    // ?? ** THIS IS WRONG WHICH YOU HAVE DONE ABOVE WOULD WORK IF I CAN BUY ONE BOOKS MULTIPLE TIME
    // BUT THATS NOT THE CASE HERE , THIS IS VERY STANDARD PROBLEM O/1 KNAPSACK
    // correct way : 
    // When solving 0/1 knapsack problems, it's critical to ensure that each item (book) is processed independently. This is why the book loop (j) should come first, and the budget loop (i) should run in reverse for each book:




    cout<<dp[x];  
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
