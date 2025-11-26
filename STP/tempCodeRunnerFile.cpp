#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
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
    int n,c12; cin>>n>>c12;
    vector<vector<pii>> graph(n+1);
    vector<int> dist(n+1,inf);
    dist[1] = 0;
    dist[2] = c12;
    graph[1].push_back({2,c12});
    graph[2].push_back({1,c12});
    for(int i = 3;i<=n;i++){
        int k; cin>>k;
        while(k--){
            int t,d; cin>>t>>d;
            graph[i].push_back({t,d});
            graph[t].push_back({i,d});
            if(dist[t]<inf){
                dist[i] = min(dist[i],dist[t] + d);
            }
        }
        priority_queue<edge> pq;
        pq.push({i,dist[i]});
        while(!pq.empty()){
            int u = pq.top().to;
            int d = pq.top().w;
            pq.pop();
            if(d>dist[u]) continue;
            for(auto x:graph[u]){
                if(dist[u] + x.second < dist[x.first]){
                    dist[x.first] = dist[u] + x.second;
                    pq.push({x.first,dist[x.first]});
                }
            }
        }
        cout<<dist[2]<<" ";
    }
}