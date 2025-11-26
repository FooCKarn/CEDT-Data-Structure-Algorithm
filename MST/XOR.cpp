#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;cin>>n;
    vector<ull> v(n);
    vector<bool> visited(n,false);
    for(int i = 0;i<n;i++) cin>>v[i];
    ull sum = 0;
    priority_queue<pair<ull,int>> pq;
    pq.push({0,0});
    while(!pq.empty()){
        ull w = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if(visited[u]) continue;
        visited[u] = true;
        sum+=w;
        for(int k = 0;k<n;k++){
            if(!visited[k]){
                ull tw = v[k] ^ v[u];
                pq.push({tw,k});
            }
        }
    }
    cout<<sum;
}