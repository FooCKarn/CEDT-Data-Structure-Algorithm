#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<vector<int>> graph(n);
    for(int i = 0;i<n;i++){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int ans = 0;
    bool valid = false;
    vector<bool> visited(n,false);
    vector<int> depth(n,0);
    for(int i = 0;i<n;i++){
        if(valid) break;
        if(visited[i]) continue;
        depth[i] = 0;
        stack<pair<int,int>> st;
        visited[i] = true;
        st.push({i,-1});
        bool flag = true;
        while(!st.empty()){
            int u = st.top().first;
            int p = st.top().second; 
            st.pop();
            if(visited[u]) continue;
            visited[u] = true;
            for(auto x:graph[u]){
                if(x==p) continue;
                if(visited[x]){
                    ans = depth[u] - depth[x] + 1;
                    valid = true;
                    break;
                }
                else{
                    depth[x] = depth[u] + 1;
                    st.push({x,u});
                }
            }
            if(valid) break;
        }
    }
    cout<<ans;
}