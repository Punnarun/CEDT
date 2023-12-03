#include <bits/stdc++.h>
using namespace std;

int main(){
    int ans = 0;
    int r,c,T; cin >> r >> c >> T;
    vector<vector<int>> table(r,vector<int>(c,-1));
    queue<pair<int,pair<int,int>>> q;
    for (int i = 0 ; i < r; i++){
        for (int j = 0; j < c; j++){
            int x; cin >> x;
            table[i][j] = x;

            if (x == 1){
                q.push(make_pair(0,make_pair(i,j)));
                ans+=1;
            }
        }
    }
    int time = 1; 
    while(!q.empty() && time != T+1){
        int day = q.front().first;
        int row = q.front().second.first;
        int col = q.front().second.second;
        while(day == time -1){
            q.pop();
            if (row - 1 >= 0 && table[row-1][col] == 0){
                int inf_row = row-1;
                int inf_col = col;
                table[inf_row][inf_col] = 1;
                q.push(make_pair(day+1,make_pair(inf_row,inf_col)));
                ans++;
            }
            if (row + 1 < r && table[row+1][col] == 0){
                int inf_row = row+1;
                int inf_col = col;
                table[inf_row][inf_col] = 1;
                q.push(make_pair(day+1,make_pair(inf_row,inf_col)));
                ans++;
            }
            if (col - 1 >= 0 && table[row][col-1] == 0){
                int inf_row = row;
                int inf_col = col-1;
                table[inf_row][inf_col] = 1;
                q.push(make_pair(day+1,make_pair(inf_row,inf_col)));
                ans++;
            }
            if (col + 1 < c && table[row][col+1] == 0){
                int inf_row = row;
                int inf_col = col+1;
                table[inf_row][inf_col] = 1;
                q.push(make_pair(day+1,make_pair(inf_row,inf_col)));
                ans++;
            }

            day = q.front().first;
            row = q.front().second.first;
            col = q.front().second.second;
        }
        time++;
    }
    cout << ans;
}