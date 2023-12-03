#include <bits/stdc++.h>
using namespace std;

int n , ans = 0;
vector<int> col;
vector<bool> used;

bool isvalid(int k){
    for (int i = 0 ; i <= k ; i++){
        for (int j = i+1 ; j <= k ; j++){
            if (col[j] == col[i] + (j - i) || col[j] == col[i] - (j - i)) return false;
        }
    }
    return true;
}

void process(int index){
    if (index == n){
        ans+= 1; return;
    }
    for (int i = 0 ; i < n; i++){
        if(used[i]) continue;
        col[index] = i;
        if (isvalid(index)){
            used[i] = true;
            process(index+1);
            used[i] = false;
        }
    }
}

int main(){
    int n; cin >> n;
    col.resize(n);
    used.resize(n,false);

    process(0);
    cout << ans;
}