// author-Jai Bansal
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second
#define all(v) (v).begin(), (v).end()
#define print(v)                       \
    for (int i = 0; i < v.size(); i++) \
    cout << v[i] << " "
#define input(v)      \
    for (auto &x : v) \
    cin >> x

// don't change
const bool takefile = false;
const bool takeinput = false;
const bool fastIO = true;

// change
void solve(int tc)
{
    int n;
    cin >> n;
    std::vector<int> arr(n);
    input(arr);
    // cout<<n;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<set<int>> ans(n+1,set<int>());
    function<void(int, int)> dfs = [&](int node, int par)
    {
        int mx = -1;
        int v = node;
        for (auto child : adj[node])
        {
            if (child == par)
                continue;
            dfs(child, node);
            // cout<<ans[child].size()<<endl;
            if (node == 3)
            {
                // cout<<"kjejhskajdf";
                // cout << (ans[child].size()) << " ";
                // cout << mx << endl;
                // cout<<(ans[child].size())<<" "<<mx<<endl;
            }
            // cout << "jh";
            if (ans[child].size() - mx > 0)
            {
                // cout << ans[child].size() << endl;
                mx = ans[child].size();
                v = child;
                if (node == 3)
                {
                    // cout << ans[child].size() << endl;
                }
            }
        }
        // if(node==3){
        //     cout<<mx<<endl;
        // }
        // cout<<mx<<endl;
        if (mx != -1)
        {
            ans[node] = ans[v];
            for (auto child : adj[node])
            {
                if (child != v && child != par)
                {
                    for (auto x : ans[child])
                    {
                        ans[node].insert(x);
                    }
                }
            }
        }
        ans[node].insert(arr[node - 1]);
    };
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i].size() << " ";
    }
    cout << endl;
}

void main_()
{
    int tcase = 1;
    if (takeinput)
        cin >> tcase;
    for (int i = 1; i <= tcase; i++)
        solve(i);
}

signed main()
{
    if (takefile)
    {
#ifndef ONLINE_JUDGE
        freopen("input1.txt", "r", stdin);
        freopen("output1.txt", "w", stdout);
#endif
    }

    // FAST I/O
    if (fastIO)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }

    main_();
    return 0;
}