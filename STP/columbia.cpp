#include<bits/stdc++.h>
using namespace std;
const int inf = INT_MAX;
struct edge{
    int st,en,w;
    bool operator<(const edge &x) const{
        return w>x.w;
    } 
};
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int r,c; cin>>r>>c;
    vector<vector<int>> grid(r,vector<int>(c));
    vector<vector<int>> dist(r,vector<int>(c,inf));
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            cin>>grid[i][j];
        }
    }
    dist[0][0] = 0;
    priority_queue<edge> pq;
    int dr[] = {-1,0,0,1};
    int dc[] = {0,1,-1,0};
    pq.push({0,0,0});
    while(!pq.empty()){
        int sr = pq.top().st;
        int sc = pq.top().en;
        int d = pq.top().w;
        pq.pop();
        if(d>dist[sr][sc]) continue;
        for(int i = 0;i<4;i++){
            int nr = sr + dr[i];
            int nc = sc + dc[i];
            if(nr >= 0&&nr<r&& nc>=0 && nc<c){
                if(grid[nr][nc]+dist[sr][sc]<dist[nr][nc]){
                    dist[nr][nc] = grid[nr][nc]+dist[sr][sc];
                    pq.push({nr,nc,dist[nr][nc]});
                }
            }
        }
    }
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<"\n";
    }


}