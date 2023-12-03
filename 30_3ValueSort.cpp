#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    vector<int> v2(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        v2[i] = v[i];
    }
    
    sort(v2.begin(), v2.end());
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0 ; i < v.size(); i++){
        if (v[i] < v2[i]){
            cnt1++;
        }
        if (v[i] > v2[i]){
            cnt2++;
        }
    }
    cout << max(cnt1,cnt2) << endl;

}
