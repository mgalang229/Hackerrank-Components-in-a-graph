#include <bits/stdc++.h>
using namespace std;

const int N = 15000;
vector<int> adj[2*N+1];
bool vis[2*N+1];
int cnt;

void dfs(int u) {
    vis[u] = true;
    cnt++;
    for (int v : adj[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(vis, false, sizeof(vis));
    int mn = 2 * n, mx = 0;
    for (int u = 0; u < 2 * n; u++) {
        if (!vis[u]) {
            cnt = 0;
            dfs(u);
            if (cnt >= 2) {
                mn = min(mn, cnt);
                mx = max(mx, cnt);
            }
        }
    }
    cout << mn << " " << mx << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
}
