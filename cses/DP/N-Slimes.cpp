// // #include <bits/stdc++.h>
// // using namespace std;

// // typedef int ll;
// // #define itn long long
// // #define int long long int

// // #define Tushar                   \
// //     ios::sync_with_stdio(false); \
// //     cin.tie(0);                  \
// //     cout.tie(0)
// // #define endl '\n'
// // #define vin(a)          \
// //     for (auto &x : (a)) \
// //     cin >> x
// // #define vout(a)               \
// //     for (const auto &x : (a)) \
// //         cout << x << ' ';     \
// //     cout << endl
// // #define vpin(a)         \
// //     for (auto &x : (a)) \
// //     cin >> x.first >> x.second
// // #define vpout(a)              \
// //     for (const auto &x : (a)) \
// //     cout << x.first << ' ' << x.second << endl
// // #define all(x) (x).begin(), (x).end()
// // #define isort(v) sort(all(v))
// // #define dsort(v) sort(all(v), greater<int>())
// // #define pb push_back
// // #define ff first
// // #define ss second
// // #define yes cout << "YES" << endl
// // #define no cout << "NO" << endl
// // #define debug(x) cerr << #x << " = " << x << endl
// // #define r(x)               \
// //     {                      \
// //         cout << x << endl; \
// //         return;            \
// //     }
// // #define setbits(x) __builtin_popcountll(x)
// // #define zerobits(x) __builtin_ctzll(x)

// // // Debugging templates
// // #ifndef ONLINE_JUDGE
// // #define debug(x)       \
// //     cerr << #x << " "; \
// //     _print(x);         \
// //     cerr << endl;
// // #else
// // #define debug(x)
// // #endif

// // void _print(int x) { cerr << x; }
// // void _print(string x) { cerr << x; }
// // void _print(char x) { cerr << x; }
// // void _print(double x) { cerr << x; }
// // void _print(long double x) { cerr << x; }
// // void _print(unsigned long long x) { cerr << x; }

// // template <class T, class V>
// // void _print(pair<T, V> p)
// // {
// //     cerr << "{";
// //     _print(p.ff);
// //     cerr << ", ";
// //     _print(p.ss);
// //     cerr << "}";
// // }
// // template <class T>
// // void _print(vector<T> v)
// // {
// //     cerr << "[ ";
// //     for (const auto &x : v)
// //     {
// //         _print(x);
// //         cerr << " ";
// //     }
// //     cerr << "]";
// // }
// // template <class T>
// // void _print(set<T> v)
// // {
// //     cerr << "{ ";
// //     for (const auto &x : v)
// //     {
// //         _print(x);
// //         cerr << " ";
// //     }
// //     cerr << "}";
// // }
// // template <class T>
// // void _print(multiset<T> v)
// // {
// //     cerr << "{ ";
// //     for (const auto &x : v)
// //     {
// //         _print(x);
// //         cerr << " ";
// //     }
// //     cerr << "}";
// // }
// // template <class T, class V>
// // void _print(map<T, V> v)
// // {
// //     cerr << "{ ";
// //     for (const auto &x : v)
// //     {
// //         _print(x);
// //         cerr << " ";
// //     }
// //     cerr << "}";
// // }

// // // Common type aliases
// // using vi = vector<int>;
// // using vii = vector<pair<int, int>>;
// // using vs = vector<string>;
// // using pii = pair<int, int>;
// // using vvi = vector<vector<int>>;

// // // Utility macros
// // #define loop(a, b, i) for (int i = (a); i < (b); ++i)
// // #define read(x) \
// //     int x;      \
// //     cin >> x
// // #define PI 3.14159265358979323846
// // #define MAX LLONG_MAX
// // #define MIN LLONG_MIN

// // // TIPS :-> brute force do exist like number can be 0-9 only rememnr tht qs in which 26+26^2+26^3>1000
// // const int MOD = 1000000007;

// // void precompute()
// // {
// // }
// // int n;
// // vector<int> a, prefix;
// // vector<vector<int>> dp;
// // const int INF = MAX;
// // // Function to compute sum of slimes from index l to r
// // int get_sum(int l, int r) {
// //     return prefix[r] - prefix[l - 1];
// // }

// // int f(int l, int r) {
// //     if (l == r) return 0; // Base case: single slime, no cost
// //     if (dp[l][r] != -1) return dp[l][r]; // Return cached result if available

// //     int cost = INF;
// //     for (int k = l; k < r; k++) {
// //         cost = min(cost, f(l, k) + f(k + 1, r) + get_sum(l, r));
// //     }
// //     return dp[l][r] = cost; // Cache and return result
// // }

// // inline void solve(){
// //     cin >> n;
// //     a.resize(n + 1);
// //     prefix.resize(n + 1, 0);
// //     dp.assign(n + 1, vector<int>(n + 1, -1));

// //     for (int i = 1; i <= n; i++) {
// //         cin >> a[i];
// //         prefix[i] = prefix[i - 1] + a[i]; // Compute prefix sums
// //     }

// //     cout << f(1, n) << endl; 
// // }

// // int32_t main()
// // {

// //     Tushar;
// //     precompute();
// //     int t = 1;
// //     cin >> t;
// //     while (t--)
// //     {
// //         solve();
// //     }
// //     return 0;
// // }



// class Solution {
// public:
//     int dp[305][305][20], MOD = 1e9 + 7;
//     int f(int i, int j, int k, int val, int n, int m, vector<vector<int>>& arr) {
//         if (i == n - 1 && j == m - 1) return (k == val) ? 1 : 0;
//         if (dp[i][j][k] != -1) return dp[i][j][k];
//         int result = 0;
//         if (i + 1 < n) result = (result+f(i + 1, j, k ^ arr[i + 1][j], val, n, m, arr)) % MOD;
//         if (j + 1 < m) result = (result + f(i, j + 1, k ^ arr[i][j + 1], val, n, m, arr)) % MOD;
//         return dp[i][j][k] = result;
//     }
//     int countPathsWithXorValue(vector<vector<int>>& arr, int k) {
//         int n = arr.size(), m = arr[0].size();
//         memset(dp, -1, sizeof(dp));
//         return f(0, 0, arr[0][0], k, n, m, arr);
//     }
// };
// ©leetcod
©leetcode


        // sort(nums.begin(), nums.end());
        // int last = -1e9 - 1;
        // int ans = 0;
    
        // for (int num : nums) {
        //     int val = max(num - k, last + 1);
        //     if (val <= num + k) {
        //         ans++;
        //         last = val;
        //     }
        // }
        // return ans;©leetcode


