#include<bits/stdc++.h>
using namespace std;
int arr[1000][1000];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int r,c,t;
    
    cin>>r>>c>>t;
    queue<pair<pair<int,int>,int>> q;
    for(int i = 1;i<=r;i++){
        for(int j = 1;j<=c;j++){
            cin>>arr[i][j];
            if(arr[i][j]==1){
                q.push({{i,j},0});
            }
        }
    }
    int cnt = 0;
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int day = q.front().second;
        q.pop();
        cnt++;
        if(day<t){
            if(x-1>0 && y>0 && x-1<=r && y<=c && arr[x-1][y] == 0){
                arr[x-1][y] = 1;
                q.push({{x-1,y},day+1});
            }
            if(x+1>0 && y>0 && x+1<=r && y<=c && arr[x+1][y] == 0){
                arr[x+1][y] = 1;
                q.push({{x+1,y},day+1});
            }
            if(x>0 && y-1>0 && x<=r && y-1<=c && arr[x][y-1] == 0){
                arr[x][y-1] = 1;
                q.push({{x,y-1},day+1});
            }
            if(x>0 && y+1>0 && x<=r && y+1<=c && arr[x][y+1] == 0){
                arr[x][y+1] = 1;
                q.push({{x,y+1},day+1});
            }
        }
    }
    cout<<cnt;
}