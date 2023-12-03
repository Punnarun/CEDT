#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<vector<int>>  sorted;
int cnt = 0;

void dfs(int index){
    visited[index] = true;
    sorted[cnt].push_back(index);
    for (auto i : adj[index]){
        if (!visited[i]) dfs(i);
    }
}

int main(){
    int v , e; cin >> v >> e;
    adj.resize(v+2);
    visited.resize(v+2);
    sorted.resize(v);
    for (int i = 0 ; i < e; i++){
        int x,y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 0 ; i < v; i++){
        visited[i] = false;
    }
    
    for (int i = 0 ; i < v; i++){
        if (!visited[i]){
            dfs(i);
            cnt++;
        }
    }
    sorted.resize(cnt);
    int ans = 0;
    
    for (auto i : sorted){
        bool plus = true;
        for (auto j : i){
            if (adj[j].size() > 2){
                plus = false;
                break;
            }
        }
        if (plus) ans++;
    }
    cout << ans;
    //cout << cnt;
}