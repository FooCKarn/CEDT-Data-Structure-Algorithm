#include<bits/stdc++.h>
using namespace std;
const int inf = 100000007;
struct edge{
    int to;
    int w;
    bool operator<(const edge &x) const{
        return w>x.w;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k;cin>>n>>m>>k;
    vector<int> station(k+1);
    for(int i=0;i<k;i++) cin>>station[i];
    vector<vector<edge>> graph(n+1);
    for(int i = 0;i<m;i++){
        int u,v,d;cin>>u>>v>>d;
        graph[u].push_back({v,d});
        graph[v].push_back({u,d});
    }
    vector<vector<int>> Alldist(k+1,vector<int>(k+1));
    for(int i =0;i<k;i++){
        int st = station[i];
        vector<int> dist(n+1,inf);
        dist[st] = 0;
        priority_queue<edge> pq;
        pq.push({st,0});
        while(!pq.empty()){
            int u = pq.top().to;
            int d = pq.top().w;
            pq.pop();
            if(d>dist[u]) continue;
            for(auto x:graph[u]){
                int v = x.to;
                int wei = x.w;
                if(dist[u]+wei<dist[v]){
                    dist[v] = dist[u]+wei;
                    pq.push({v,dist[v]});
                }
            }
        }
        for(int j = 0;j<k;j++){
            Alldist[i][j] = dist[station[j]];
        }
    }
    vector<int> tmp(k);
    for(int i = 0;i<k;i++) tmp[i] = i;
    int mn = inf;
    while(next_permutation(tmp.begin(),tmp.end())){
        int cur = 0;
        bool valid = true;
        for(int i = 0;i<k-1;i++){
            int u_idx = tmp[i];
            int v_idx = tmp[i+1];
            int cost = Alldist[u_idx][v_idx];
                    if (cost == inf) { 
                        valid = false;
                        break;
                    }
                    cur += cost;
                }

                if (valid) {
                    if (cur < mn) {
                        mn = cur;
                    }
            }
        }
        cout<<mn;
 }

