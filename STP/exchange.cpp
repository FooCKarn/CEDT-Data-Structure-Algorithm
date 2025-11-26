#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin>>k;
    while(k--){
        int n;cin>>n;
        vector<vector<double>> dist(n,vector<double>(n));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                cin>>dist[i][j];
            }
        }
        for(int k = 0;k<n;k++){
            for(int i = 0;i<n;i++){
                for(int j = 0;j<n;j++){
                    dist[i][j] = max(dist[i][j],dist[i][k]*dist[k][j]);
                }
            }
        }
        bool chk = false;
        for(int i = 0;i<n;i++){
            if(dist[i][i] > 1.0){
                chk = true;
                break;
            }
        }
        cout<<(chk? "YES\n":"NO\n");
    }
}
