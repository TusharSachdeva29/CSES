#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
vvi arr;
vi vis, ans;
int n, m;

void dfs(int node)
{
    vis[node] = 1;
    for (int neighbor : arr[node])
    {
        if (!vis[neighbor])
            dfs(neighbor);
    }
}

void solve()
{
    cin >> n >> m;
    arr.resize(n + 1);
    vis.resize(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
            cnt++;
            ans.push_back(i);
        }
    }
    cout << cnt - 1 << endl;
    for (int i = 1; i < ans.size(); i++)
        cout << ans[i - 1] << " " << ans[i] << endl;
}

int main()
{
    solve();
    return 0;
}
