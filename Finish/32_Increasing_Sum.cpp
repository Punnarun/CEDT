#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

void permu(int left , vector<int>&v){
    int start = 1;
    if (v.size() != 0) start = v[v.size()-1];
    for (int i = start; i <= left; i++){
        v.push_back(i);
        permu(left-i,v);
        v.pop_back();
    }
    if (left == 0){
        cnt++;
    }
}
int main(){
    int n; cin >> n;
    vector<int> v;
    permu(n,v); cout << cnt;
}