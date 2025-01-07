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

void precompute() {}
int ceil(itn n,int k){
    return (n+k-1)/k;
}
void solve() {
    read(n);vi arr(n);vin(arr);
    int cnt = 0;isort(arr);
    int i =0;int j =n-1;int x = 0;
    debug(arr)
    while(i<j){
        // debug(i);debug(j);debug(x);
        // if(arr[i]==0)
        // debug(cnt)debug(x)
        if(x>=arr[j]){
            j--;
            x = 0;
            cnt++;
        }
        else if(arr[i]==1) {
            i++;x++;cnt++;
        }
        else {
            int req = arr[j] - x;
            if(arr[i]>=req){
                // if(i==3) cout<<"maaa";
                arr[i]-=req;
                j--;
                x= 0;
                cnt+=req+1;
                if(arr[i]==0) i++;
            }
            else {
                x+=arr[i];
                // arr[i] = 0;
                // if(i==3) cout<<"maaa"<<cnt<<endl;
                // cout
                cnt+=arr[i];
                i++;
                // cout<<cnt<<endl;
            }
        }
    }  
    debug(cnt)
    int req = arr[i] - x;
    cnt += req/2;
    x+=req/2;
    arr[i] -= req/2;
    if(arr[i]>0){
        arr[i]-=x;
        cnt ++ ;
    }
    cnt+=arr[i];
    cout<<cnt<<endl; 
}

int32_t main() {
    Tushar;
    precompute();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

    //     map<int,long long> mp; 
    //     for(auto e : coins) {
    //         int l = e[0], r=e[1], c=e[2];
    //         mp[l]+=c;
    //         mp[r+1]-=c;
    //     }
        
    //     long long sumi = 0;
    //     vector<pair<int, long long>> pre;
    //     for (auto [pos, value] : mp) {
    //         sumi+=value;
    //         pre.push_back({pos, sumi});
    //     }