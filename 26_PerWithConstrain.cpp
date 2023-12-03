#include <bits/stdc++.h>
using namespace std;

vector<int> v;
void permu(int cnt ,int n , vector<bool> &used, map<int,int> condition){
    //vector<int> v(n);
    if (cnt == n){
        for (auto i : v){
            cout << i << ' ';   
        }
        cout << endl;
    } else {
        for (int i = 0 ; i < n; i++){
            if (!used[i] && (condition[i] == 100 || used[condition[i]])){
                v[cnt] = i;
                used[i] = true;
                permu(cnt+1,n,used,condition);
                used[i] = false;
            }
        }
    }
}
int main(){

    int n,m; cin >> n >> m;
    map<int,int> condition;
    v.resize(n);
    for (int i = 0 ; i < n; i++){
        condition[i] = 100;
    }
    for (int i = 0 ; i < m; i++){
            int x,y; cin >> x >> y;
            condition[y] = x;
    }
    vector<bool> used(n,false);
    permu(0,n,used,condition);
}