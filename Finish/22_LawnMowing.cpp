#include <bits/stdc++.h>
using namespace std;

int main(){
    int n , m , k; cin >> n >> m >> k;

    vector<long long> grass;
    vector<long long> cost;
    for (int i = 0; i < n; i++) {
        long long a; 
        cin >> a;
        grass.push_back(a);
        if (i == 0) {
            cost.push_back(a + k);
        } else {
            cost.push_back(cost[i - 1] + a + k);
        }
    }

    for (int i = 0 ; i < m ; i++){
        long long start,money; cin >> start >> money;
        long long moneyadding = 0;
        if (start > 0) moneyadding = cost[start-1];
        
        auto itr = upper_bound(cost.begin(),cost.end(),money+moneyadding);
        if (itr == cost.begin() && cost[0] > money + moneyadding){
            cout << "0" << endl;
        } else {
            itr--;
            cout << (*itr) - moneyadding - (itr - cost.begin() - start + 1)*k << endl;
        }
    }
}