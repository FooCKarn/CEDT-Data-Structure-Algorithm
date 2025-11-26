#include<bits/stdc++.h>
using namespace std;
#define pii pair<long long,int>
struct edge{
    int st;
    int en;
    int w;
};
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,e,s; cin>>n>>e>>s;
   vector<edge> vec;
   for(int i = 0;i<e;i++){
    int u,v,w;cin>>u>>v>>w;
    vec.push_back({u,v,w});
   }
   vector<int> dist(n+10,INT_MAX);
   dist[s] = 0;
   for(int i = 0;i<n-1;i++){
    for(auto x:vec){
        if(dist[x.st]!=INT_MAX && dist[x.st]+x.w<dist[x.en]){
            dist[x.en] = dist[x.st] + x.w;
            }
        }
   }
   bool isValid = false;
   for(auto x:vec){
        if(dist[x.st]!=INT_MAX && dist[x.st]+x.w<dist[x.en]){
             isValid = true; break;
            }
    }
   if(isValid){
        cout<<"-1";
        return 0;
   }
   for(int i = 0;i<n;i++){
        cout<<dist[i]<<" ";
   }

}