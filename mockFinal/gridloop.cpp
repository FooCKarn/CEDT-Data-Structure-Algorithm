#include<bits/stdc++.h>
using namespace std;
int r,c;
int grid[1005][1005];
bool visited[1005][1005] = {false};
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
int pipes[7][2] = {
    { -1, -1}, // 0 (ไม่มี)
    {3, 1},    // 1: ซ้าย-ขวา
    {0, 2},    // 2: บน-ล่าง
    {0, 1},    // 3: บน-ขวา
    {1, 2},    // 4: ขวา-ล่าง
    {2, 3},    // 5: ล่าง-ซ้าย
    {3, 0}     // 6: ซ้าย-บน
};
bool canConnect(int i,int j,int opDir){
    if(i<1||i>r||j<1||j>c) return false;
    int type = grid[i][j];
    return (pipes[type][0]==opDir||pipes[type][1]==opDir);
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>r>>c;
    for(int i = 1;i<=r;i++){
        for(int j = 1;j<=c;j++){
            cin>>grid[i][j];
        }
    }
    int loopcnt = 0;
    int maxlen = 0;
    for(int i = 1;i<=r;i++){
        for(int j = 1;j<=c;j++){
            if(visited[i][j]) continue;
            int startR =i, startC = j;
            int curR = i,curC=j;
            int prevR = -1,prevC = -1;
            int nextR = -1,nextC = -1;
            int type = grid[i][j];
            for(int k = 0;k<2;k++){
                int dir = pipes[type][k];
                int nr = i + dr[dir];
                int nc = j + dc[dir];
                int opDir = (dir+2)%4;
                if(canConnect(nr,nc,opDir)){
                    nextR = nr;
                    nextC = nc;
                    break;
                }
            }
            if(nextR == -1){
                visited[i][j] = true;
                continue;
            }

            int curlen = 0;
            vector<pair<int,int>> path;
            path.push_back({curR,curC});
            bool isLoop = false;
            prevR = curR;
            prevC= curC;
            curR = nextR;
            curC = nextC;
            while(true){
                path.push_back({curR,curC});
                curlen++;
                if(curR == startR && curC == startC){
                    isLoop = true;
                    break;
                }
                if(visited[curR][curC]){
                    isLoop = false;
                    break;
                }
                int t = grid[curR][curC];
                bool foundNext = false;
                for(int k = 0;k<2;k++){
                    int dir = pipes[t][k];
                    int nr = curR + dr[dir];
                    int nc = curC + dc[dir];
                    if(nr == prevR && nc == prevC) continue;
                    int opDir = (dir+2)%4;
                if(canConnect(nr,nc,opDir)){
                    prevR = curR;
                    prevC= curC;
                    curR = nr;
                    curC = nc;
                    foundNext = true;
                    break;
                }
             }
             if(!foundNext) break;
            }
            for(auto x:path){
                visited[x.first][x.second] = true;
            }
            if(isLoop){
                loopcnt++;
                if(curlen>maxlen){
                    maxlen = curlen;
                }
            }
        }
    }
    cout<<loopcnt<<" "<<maxlen;
}