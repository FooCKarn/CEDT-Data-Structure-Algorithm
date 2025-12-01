#include<bits/stdc++.h>
using namespace std;
struct edge{
    int r,c,w;
};
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int r,c;cin>>r>>c;
    vector<vector<int>> grid(r,vector<int>(c));
    vector<vector<bool>> visited(r,vector<bool>(c,false));
    queue<edge> q;
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            cin>>grid[i][j];
            if(grid[i][j]==1){
                q.push({i,j,1});
                visited[i][j] = true;
            }
        }
    }
    int ans = 0;
    int dr[] = {-1,1,0,0};    
    int dc[] = {0,0,-1,1};
    while(!q.empty()){
        int sr = q.front().r;
        int sc = q.front().c;
        int dis = q.front().w;
        if(grid[sr][sc]==2){
            ans = dis;
            break;
        }
        q.pop();
        for(int i = 0;i<4;i++){
            int nr = sr + dr[i];
            int nc = sc + dc[i];
            if(nr>=0&&nr<r&&nc>=0&&nc<c&& !visited[nr][nc]&&grid[nr][nc]!=3){
                q.push({nr,nc,dis+1});
                visited[nr][nc] = true;
            }
        }
    }
    cout<<ans;
}