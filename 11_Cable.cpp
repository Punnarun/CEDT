#include <bits/stdc++.h>
using namespace std;

int K;
map<int,bool>visited; 
vector<vector<int>> v;

void dfs(int i,int left){
    if (left == K) return;
    for (auto j : v[i]){
        visited[j] = true;
        dfs(j,left+1);
    }
}


int main(){

    int N,E; cin >> N >> E >> K;
    v.resize(N);
    for(int i = 0; i < E; i++){
        int x,y; cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);

    }
    for (int i = 0 ; i < N; i++){
        visited[i] = false;
    }
    int tmp = 0;
    for (int i = 0 ; i < N; i++){
        int cnt = 0;
        visited[i] = true; dfs(i,0);
        for (int i = 0 ; i < visited.size(); i++){
            if (visited[i] == true){
                visited[i] = false;
                cnt++;
            }
        }
        tmp = max(tmp,cnt);
    }
    cout << tmp;
}