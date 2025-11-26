#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;cin>>n>>m;
    vector<int> v,q;
    for(int i = 0;i<n;i++){
        int k;cin>>k;
        v.push_back(k);
    }
    while(m--){
        int val; cin>>val;
        auto it = upper_bound(v.begin(),v.end(),val);
        if(v[0]>val) cout<<"-1\n";
        else {it--;cout<<*it<<"\n";}
    }

}