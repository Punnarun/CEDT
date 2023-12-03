#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> ans;
vector<bool> visited;

void dfs(int index){
    visited[index] = true;
    ans.push_back(index);
    for (auto i : adj[index]){
        if (!visited[i]) dfs(i);
    }
}

int main(){
    
    int v,e; cin >> v >> e;
    adj.resize(v);
    visited.resize(v);
    for (int i = 0 ; i < e; i++){
        int x,y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int num_cc;
    for (int i = 0 ; i < v; i++){
        if (!visited[i]){
            num_cc++;
            dfs(i);
        }
    }
    cout << num_cc;
}