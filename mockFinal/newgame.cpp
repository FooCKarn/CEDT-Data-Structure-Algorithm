#include<bits/stdc++.h>
using namespace std;
const int m =  100000007 ;
int r,c;
int grid[501][501];
int dp[501][501][3];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>r>>c;
    for(int i = 1;i<=r;i++){
        for(int j = 1;j<=c;j++){
            cin>>grid[i][j];
        }
    }
    for(int i = 1;i<=r;i++){
        if(grid[i][1]==1) continue;
        if(i-1>=1 && grid[i-1][2]==0) dp[i-1][2][0]++;
        if(grid[i][2]==0) dp[i][2][1]++;
        if(i+1<=r && grid[i+1][2]==0) dp[i+1][2][2]++;
    }
    for(int col = 3;col<=c;col++){
        for(int row = 1;row<=r;row++){
            if(grid[row][col]==1) continue;
            if(row+1<=r ) dp[row][col][0] = (dp[row+1][col-1][1] + dp[row+1][col-1][2])%m;
            dp[row][col][1] = (dp[row][col-1][0] + dp[row][col-1][2])%m;
            if(row-1>=1 ) dp[row][col][2] = (dp[row-1][col-1][0] + dp[row-1][col-1][1])%m;;
        }
    }
    int total = 0;
    for(int i = 1;i<=r;i++){
        total = (total + dp[i][c][0]) % m;
        total = (total + dp[i][c][1]) % m;
        total = (total + dp[i][c][2]) % m;
    }
    cout<<total;
}