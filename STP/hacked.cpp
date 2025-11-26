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
    int n,m,k; cin>>n>>m>>k;
    vector<vector<int>> graph(n);
    vector<int> st(k);
    vector<int> dist(n,inf);
    vector<int> cost(n);
    priority_queue<edge> pq;
    for(int i = 0;i<k;i++){
        cin>>st[i];
    }
    for(int i = 0;i<n;i++){
        cin>>cost[i];
    }
    for(int i = 0;i<m;i++){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i = 0;i<k;i++){
        pq.push({st[i],cost[st[i]]});
        dist[st[i]] = cost[st[i]];
    }
    while(!pq.empty()){
        int u = pq.top().to;
        int d = pq.top().w;
        pq.pop();
        if(d>dist[u]) continue;
        for(auto x:graph[u]){
            if(d + cost[x] < dist[x]){
                dist[x] = d + cost[x];
                pq.push({x,dist[x]});
            }
        }
    }
    int mx = 0;
    for(int i = 0;i<n;i++){
        if(dist[i]!=inf) mx = max(mx,dist[i]);
    }
    cout<<mx;
}