#include <bits/stdc++.h>
using namespace std;

bool compare(pair<double, double>& a, pair<double, double>& b) {
    return (a.first / a.second) > (b.first / b.second);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    double W, N;
    cin >> W >> N;

    vector<pair<double, double>> weight(N);

    for (int i = 0; i < N; i++) {
        cin >> weight[i].first;
    }
    for (int i = 0; i < N; i++) {
        cin >> weight[i].second;
    }
    sort(weight.begin(), weight.end(), compare);

    double now = 0;
    double val = 0;

    for (int i = 0; i < N; i++) {
        if (now + weight[i].second <= W) {
            val += weight[i].first;
            now += weight[i].second;
        } else {
            double left = W - now;
            double tmp_forval = left / weight[i].second;
            val += (weight[i].first * tmp_forval);
            break;
        }
    }

    cout << fixed << setprecision(4) << val << endl;
    return 0;
}
