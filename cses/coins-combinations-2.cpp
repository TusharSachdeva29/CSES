#include <bits/stdc++.h>
 
using namespace std;
 
// #define int long long int
// #define double long double
// #define INT_MAX LLONG_MAX
// #define INT_MIN LLONG_MIN
#define vin(a) for(int i=0;i<(a).size();i++)cin>>a[i];
#define vout(a) for(int i=0;i<a.size();i++)cout<<a[i]<<' ';cout<<endl;
#define vpin(a) for(int i=0;i<(a).size();i++)cin>>a[i].first>>a[i].second;
#define vpout(a) for(int i=0;i<a.size();i++)cout<<a[i].first<<' '<<a[i].second<<endl;cout<<endl;
#define cout(x) cout<<setprecision(20)<<x<<endl 
#define r(x) {cout<<x<<'\n';return;}
 
const int M = 1000000007;
const int N = 1e5+10;
 
void precalc(){}
 
void solve(){
    int n , k;
    cin >> n >> k;
    vector<int> coins(n);
    vin(coins);
    // sort(coins.begin(),coins.end());
    vector<vector<int>> dp(n+5,vector<int>(1e6+10,0));
    for(int i=0 ; i<n ; i++) for(int j=i ; j<n ; j++) dp[i][coins[i]] = 1;
    for(int i=0 ; i<n ; i++){
        for(int j=1 ; j<=k+5 ; j++){
            if(j-coins[i]>=0) dp[i][j] += dp[i][j-coins[i]];
            dp[i][j] %= M;
            if(i>0) dp[i][j] += dp[i-1][j];
            dp[i][j] %= M;
        }
    }
    cout << dp[n-1][k] ;
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    precalc();
    // int t;
    // cin >> t;
    // while(t--){
        solve();
    // }
    return 0;
}