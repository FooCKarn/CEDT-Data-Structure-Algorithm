#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int v,e;cin>>v>>e;
    vector<vector<int>> graph(v);
    vector<int> deg(v,0);
    vector<bool> visited(v,false);
    for(int i = 1;i<=e;i++){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    int cnt = 0;
    for(int i=0;i<v;i++){
        if(visited[i]) continue;

        stack<int> st;
        st.push(i);
        int comNode = 0;
        int comEdge = 0;
        bool isValid = true;
        visited[i] = true;
        while(!st.empty()){
            int u = st.top(); st.pop();
            comNode++;
            comEdge+=deg[u];
            if(deg[u]>2) isValid = false;
            for(auto x:graph[u]){
                if(!visited[x]){
                    visited[x] = true;
                    st.push(x);
                }
            }
        }
        int realEdge = comEdge/2;
        if(isValid == true && realEdge == comNode - 1) cnt++;
    }
    cout<<cnt;
}