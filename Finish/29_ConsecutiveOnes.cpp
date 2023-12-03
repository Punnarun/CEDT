#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;
void permute(vector<int> v , int left , int connected){
    if (left == 0) {
        int consecutive = 0;
        for (int i = 0 ; i < v.size(); i++){
            if (v[i] == 1) consecutive++;
            else consecutive = 0;

            if (consecutive >= connected){
                ans.push_back(v);
                break;
            }
        }
    } else {
        v.push_back(1); permute(v,left-1,connected); v.pop_back();
        v.push_back(0); permute(v,left-1,connected); v.pop_back(); 
    }
    
}

int main(){
    int n,c ; cin >> n >> c;
    vector<int> v;
    permute(v,n,c);
    sort(ans.begin(),ans.end());
    for (auto i : ans) {
        for (auto j : i){
            cout << j;
        }
        cout << endl;
    }
}