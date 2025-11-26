#include<bits/stdc++.h>
int parent[1005] ; 
using namespace std;
int findHead(int n){
    if(parent[n]==n) return n;
    else return parent[n] = findHead(parent[n]);
}
int main(){
    int t; cin>>t;
    while(t--){
        int n,e;
        cin>>n>>e;
        for(int i = 0;i<n;i++){
            parent[i] = i;
        }
        bool ans = false;
        for(int j = 0;j<e;j++){
            int st,en;
            cin>>st>>en;
            int find_st = findHead(st);
            int find_en = findHead(en);
            if(find_st==find_en) ans = true;
            parent[find_st] = parent[find_en];
        }
        if(ans) cout<<"YES\n";
        else cout<<"NO\n";
    }
}