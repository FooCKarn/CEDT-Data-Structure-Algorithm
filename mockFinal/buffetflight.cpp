#include<bits/stdc++.h>
using namespace std;
const int inf = INT_MAX;
struct edge{
    int to;
    int w;
    bool operator<(const edge &x) const{
        return w>x.w;
    }  
};
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;cin>>n>>m;
    vector<int> ci(n),co(n);
    for(int i = 0;i<n;i++) cin>>ci[i];
    for(int i = 0;i<n;i++) cin>>co[i];
    vector<int> dist(n,inf);
    vector<vector<int>> graph(n);
    for(int i = 0;i<m;i++){
        int u,v; cin>>u>>v;
        graph[u].push_back(v);
    }
    dist[0] = 0;
    priority_queue<edge> pq;
    pq.push({0,0});
    while(!pq.empty()){
        int u = pq.top().to;
        int d = pq.top().w;
        pq.pop();
        if(d>dist[u]) continue;
        for(auto x:graph[u]){
            if(dist[u]+co[u]+ci[x]<dist[x]){
                dist[x] = dist[u]+co[u]+ci[x];
                pq.push({x,dist[x]});
            }
        }
    }
    for(int i = 0;i<n;i++){
        if(dist[i]==inf) cout<<"-1 ";
        else cout<<dist[i]<<" ";
    }

}