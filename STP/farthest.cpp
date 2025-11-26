#include<bits/stdc++.h>
using namespace std;
#define pii pair<long long,int>
struct edge{
    int en;
    int w;
};
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<vector<edge>> graph(n+10);
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            int w; cin>>w;
            if(w!=-1 && i!=j ) graph[i].push_back({j,w});
        }
    }
    vector<long long> dist(n+10,1e18);
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    dist[1] = 0;
    pq.push({0,1});
    while(!pq.empty()){
        int u = pq.top().second;
        long long w = pq.top().first;
        pq.pop();
        if(w>dist[u]) continue;
        for(auto x:graph[u]){
            if(dist[u]+x.w<dist[x.en]){
                dist[x.en] = dist[u] + x.w;
                pq.push({dist[x.en],x.en});
            }
        }
    }
    long long ans = -1;
    for(int i = 1;i<=n;i++){
        if(dist[i]==1e18){
            cout<<"-1";
            return 0;
        }
        ans = max(ans,dist[i]);
    }
    cout<<ans;

}