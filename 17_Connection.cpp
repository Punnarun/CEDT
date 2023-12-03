#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

bool dfs_cd(int a, int parent) {
    visited[a] = true;
    for (int b : adj[a]) {
        if (!visited[b]) {
            if (dfs_cd(b, a))
                return true;
        } else if (b != parent)
            return true;
    }
    return false;
}

bool circuit_detect(int n) {
    visited.resize(n, false);
    for (int u = 0; u < n; ++u) {
        if (!visited[u]) {
            if (dfs_cd(u, -1))
                return true;    
        }
    }
    return false;
}

int main() {
    
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int N, E;
        cin >> N >> E;

        adj.resize(N);
        visited.clear();
        visited.resize(N, false);

        for (int i = 0; i < E; i++) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        if (circuit_detect(N))
            cout << "YES\n";
        else
            cout << "NO\n";

        adj.clear();
    }
    return 0;
}
