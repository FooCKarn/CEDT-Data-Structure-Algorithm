#include<bits/stdc++.h>
using namespace std;
const int inf = INT_MAX;
#define pii pair<int,int>
struct edge{
    int r,c,w;
};
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int r,c;cin>>r>>c;
    vector<vector<char>> grid(r,vector<char>(c));
    vector<vector<int>> dist(r,vector<int>(c,inf));
    queue<edge> q;
    vector<pair<int,int>> bus[6];
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            cin>>grid[i][j];
            if(isdigit(grid[i][j])){
                int num = grid[i][j] - '0';
                bus[num].push_back({i,j});
            }
        }
    }
    map<pii,pii> jump;
    for(int i = 1;i<=5;i++){
        if(bus[i].size()!=2) continue;
        pii p1 = bus[i][0];
        pii p2 = bus[i][1];
        int d1 = abs(p1.first) + abs(p1.second);
        int d2 = abs(p2.first) + abs(p2.second);
        if(d1<d2){
            jump[p1] = p2;
        }
        else{
            jump[p2] = p1;
        }
    }
    dist[0][0] = 0;
    int dr[] = {0,0,1};    
    int dc[] = {1,-1,0};
    q.push({0,0,0});
    while(!q.empty()){
        int sr = q.front().r;
        int sc = q.front().c;
        int dis = q.front().w;
        q.pop();
        if(dis>dist[sr][sc]) continue;
        if(sr== r-1 && sc == c-1){
            cout<<dis;
            return 0;
        }
        for(int i = 0;i<3;i++){
            int nr = sr + dr[i];
            int nc = sc + dc[i];
            if(nr>=0&&nr<r&&nc>=0&&nc<c&& grid[nr][nc]!='X'&& dist[sr][sc]+1<dist[nr][nc]){
                dist[nr][nc] = dist[sr][sc] + 1;
                q.push({nr,nc,dist[nr][nc]});
                
            }


        }
        if(jump.find({sr,sc})!=jump.end()){
            int nr = jump[{sr,sc}].first;
            int nc = jump[{sr,sc}].second;
            if(dist[sr][sc]<dist[nr][nc]){
                dist[nr][nc] = dist[sr][sc];
                q.push({nr,nc,dist[nr][nc]});
                
            }
        }
    }
}