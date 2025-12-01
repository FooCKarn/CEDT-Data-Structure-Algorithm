#include<bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
int n,m,k,s;
long long dist[2][500005];
vector<int> mem;
struct edge{
    int to;
    long long w;
    bool operator<(const edge &x) const{
        return w>x.w;
    }
};
vector<edge> graph[2][500005];
string pattern = "";
void recur(int idx){
    if(idx == k){
        cout<<pattern<<"\n";
        return ;
    }
    int u = mem[idx];
    long long db = dist[0][u];
    long long dr = dist[1][u];
    if(db<=dr){
        pattern += '0';
        recur(idx+1);
        pattern.pop_back();
    }
    if(dr<=db){
        pattern += '1';
        recur(idx+1);
        pattern.pop_back();
    }

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k>>s;
    for(int i = 0;i<m;i++){
        int u,v,t;
        long long d;
        cin>>u>>v>>d>>t;
        graph[t][v].push_back({u,d});
    }
    mem.resize(k);
    for(int i = 0;i<k;i++) cin>>mem[i];
    for(int type = 0;type<2;type++){
        for(int i = 1;i<=n;i++) dist[type][i] = inf;
        dist[type][s] = 0;
        priority_queue<edge> pq;
        pq.push({s,0});
        while(!pq.empty()){
            int u = pq.top().to;
            long long d = pq.top().w;
            pq.pop();
            if(d>dist[type][u]) continue;
            for(auto x:graph[type][u]){
                int v = x.to;
                long long wei = x.w;
                if(dist[type][u]+wei<dist[type][v]){
                    dist[type][v] = dist[type][u] + wei;
                     pq.push({v,dist[type][v]});
                }

            }
        }

    }
    long long totalMin = 0;
    for(int u : mem){
        totalMin += min(dist[0][u],dist[1][u]);
    }
    cout<<totalMin<<"\n";
    recur(0);
}