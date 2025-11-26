#include<bits/stdc++.h>
int parent[10005];
bool chk1[10005] = {false};
int findHead(int n){
    if(parent[n]==n) return n;
    else return parent[n] = findHead(parent[n]);
}
using namespace std;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int v,e;
    cin>>v>>e;
    for(int i = 1;i<=v;i++){
        parent[i] = i;
    }
    for(int i = 0;i<e;i++){
        int st,en;cin>>st>>en;
        int find_st = findHead(st);
        int find_en = findHead(en);
        if(find_st!=find_en) parent[find_st] = parent[find_en];
    }
    int cnt = 0;
    for(int i = 1;i<=v;i++){
        int root = findHead(i);
        if(chk1[root]==false){
            chk1[root] = true;
            cnt++;
        }
    }
    cout<<cnt;
}