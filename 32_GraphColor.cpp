#include <bits/stdc++.h>
using namespace std;

int n,e;
vector<vector<int>> adj;
vector<int> color;

bool check(int index , int colorNeeded){

    if (index == n) return true;
    
    for (int i = 1; i <= colorNeeded; i++){
        bool isValid = true;
        for (int j = 0 ; j < adj[index].size(); j++){
            int k = adj[index][j];
            if (color[k] == i){
                isValid = false;
                break;
            }
        }
        if(isValid){
            color[index] = i;
            if (check(index+1,colorNeeded)){
                return true;
            };
        }
    }
    color[index] = 0;
    return false;
}

int main(){
    cin >> n >> e;
    
    adj.resize(n);
    color.resize(n,0);
    for (int i = 0 ; i < e; i++){
        int x,y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 1 ; i <= n; i++){
        if (check(0,i)){
            cout << i;
            return 0;
        }
    }
}