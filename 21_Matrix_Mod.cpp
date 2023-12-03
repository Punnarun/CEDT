#include <bits/stdc++.h>
using namespace std;

vector<int> a;
vector<int> a2;
vector <int> oneMatrix(4,1);
int n,k;
void multiply(int k , vector<int>& v, vector<int>& v2){
    long long topleft = v[0]*v2[0] + v[1]*v2[2];
    long long btmleft = v[2]*v2[0] + v[3]*v2[2];
    long long topright = v[0]*v2[1] + v[1]*v2[3];
    long long btmright = v[2]*v2[1] + v[3]*v2[3];
    v[0] = topleft;
    v[1] = topright;
    v[2] = btmleft;
    v[3] = btmright;
}

void process(int n){
    
}




int main(){
    
    cin >> n >> k;
    
    for (int i = 0 ; i < 4; i++){
        int x; cin >> x;
        v.push_back(x);
        v2.push_back(x);
    }
    
    process(n);

    for (auto i : v) {
        cout << i << ' ';
    }
    
}