#include <bits/stdc++.h>
using namespace std;

#define vc vector<char>
#define vi vector<int>
#define all(x) x.begin(), x.end()

int n, m;
vector<vc> arr;
vector<vi> vis;

void solve() {
    cin >> n >> m;
    arr.resize(n, vc(m));
    vis.resize(n, vi(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    pair<int, int> start, end;
    queue<pair<int, int>> q;
    bool found = false;
    string ans;

    for (int i = 0; i < n && !found; i++) {
        for (int j = 0; j < m && !found; j++) {
            if (arr[i][j] == 'A') {
                q.push({i, j});
                start = {i, j};
                vis[i][j] = 1;
                found = true;
            }
        }
    }

    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    string path = "UDLR";
    map<pair<int, int>, pair<int, int>> parent;

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        if (arr[curr.first][curr.second] == 'B') {
            cout << "YES" << endl;

            // Reconstruct path
            while (curr != start) {
                auto prev = parent[curr];
                if (prev.first == curr.first - 1) ans += 'D';
                else if (prev.first == curr.first + 1) ans += 'U';
                else if (prev.second == curr.second - 1) ans += 'R';
                else ans += 'L';
                curr = prev;
            }
            reverse(all(ans));
            cout << ans.size() << endl;
            cout << ans << endl;
            return;
        }

        for (int k = 0; k < 4; k++) {
            int nx = curr.first + dir[k][0];
            int ny = curr.second + dir[k][1];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || vis[nx][ny] || arr[nx][ny] == '#') continue;
            vis[nx][ny] = 1;
            q.push({nx, ny});
            parent[{nx, ny}] = curr;
        }
    }

    cout << "NO" << endl;
}

int main() {
    solve();
    return 0;
}
