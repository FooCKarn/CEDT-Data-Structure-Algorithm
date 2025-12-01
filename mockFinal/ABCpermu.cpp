#include<bits/stdc++.h>
using namespace std;
vector<string> ans;
int n;
void solve(int i,int j,int k,string s,int len){
    if(len == n){
        ans.push_back(s);
        return;
    }
    if(i>0){
         solve(i-1,j,k,s+'A',len+1);
    }
    if(j>0){
         solve(i,j-1,k,s+'B',len+1);
    }
    if(k>0){
         solve(i,j,k-1,s+'C',len+1);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int i,j,k; cin>>n>>i>>j>>k;
    solve(i,j,k,"",0);
    cout<<ans.size()<<"\n";
    for(auto x:ans) cout<<x<<"\n";
}