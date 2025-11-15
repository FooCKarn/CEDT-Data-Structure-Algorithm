#include<bits/stdc++.h>
using namespace std;
int main(){
   ios_base::sync_with_stdio(0); cin.tie();
   int n,m;cin>>n>>m;
   vector<int> vec,q;
   for(int i = 0;i<n;i++){
    int k; cin>>k;
    vec.push_back(k);
   }
   for(int i = 0;i<m;i++){
    int z; cin>>z;
    q.push_back(z);
   }
   vector<int> ans(n+10,0);
   for(int i = 0;i<m;i++){
    int cnt=0;
    for(int j = 0;j<n;j++){
        if(vec[j]==q[i]) break;
        if(vec[j]>q[i]) ans[i]++;
    }
    cout<<ans[i]<<endl;
   }
}