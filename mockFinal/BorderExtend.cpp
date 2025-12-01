#include<bits/stdc++.h>
using namespace std;


struct State {
    int r, c, step;
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    int r, c, k; 
    cin >> r >> c >> k;
    
    int arr[r+10][c+10]; 
    
    queue<State> q; 

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> arr[i][j];

            if(arr[i][j] == 1) {
                q.push({i, j, 0});
            }
        }
    }

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while(!q.empty()){
        State current = q.front();
        q.pop();

        int row = current.r;
        int col = current.c;
        int step = current.step;


        if(step >= k) continue;

        for(int i = 0; i < 4; i++){
            int nr = row + dr[i];
            int nc = col + dc[i];

            if(nr >= 0 && nr < r && nc >= 0 && nc < c){
                if(arr[nr][nc] == 0){
                    arr[nr][nc] = 2;       
                    q.push({nr, nc, step + 1}); 
                }
            }
        }
    }

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){ 
            cout << arr[i][j]<<" "; 
        }
        cout << "\n";
    }
}