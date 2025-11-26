#include<bits/stdc++.h>
using namespace std;
int parent[1005];
struct edge{
    int st,en,w;
    bool operator<(const edge &x){
        return w<x.w;
    }
};

int findHead(int n){
    if(parent[n]== n) return n;
    else return parent[n] = findHead(parent[n]);
}
void unionGraph(int a,int b){
    int root_a = findHead(a);
    int root_b = findHead(b);
    if(root_a!=root_b){
        parent[root_a] = root_b; 
    }
}



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<edge> v;
    for(int i = 0;i<n-1;i++){
        for(int j = 0;j<n-1-i;j++){
            int w;
            cin>>w;
            v.push_back({i,i+j+1,w});
        }
    }
    sort(v.begin(),v.end());
    for(int i = 0;i<n;i++) parent[i] = i;
    int sum = 0;
    for(auto x:v){
        if(findHead(x.st)!=findHead(x.en)){
            unionGraph(x.st,x.en);
            sum+=x.w;
        }
    }
    cout<<sum;

}