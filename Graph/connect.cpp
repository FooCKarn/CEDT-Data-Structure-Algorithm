#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,e,k; cin>>n>>e>>k;
    vector<vector<int>> graph(n);
    for(int i = 1;i<=e;i++){
        int u,v; cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int mx = 0;
    for(int i = 0;i<n;i++){
        vector<bool> visited(n,false);
        vector<int> dist(n);
        queue<int> q;
        q.push(i);
        int cnt = 0;
        visited[i] = true;
        dist[i] = 0;
        while(!q.empty()){
            int curr = q.front(); q.pop();
            cnt++;
            if(dist[curr]<k){
                for(auto x:graph[curr]){
                    if(!visited[x]){
                        visited[x] = true;
                        dist[x] = dist[curr]+1;
                        q.push(x);
                    }
                }
            }
        }
        mx = max(mx,cnt);
    }
    cout<<mx;
}