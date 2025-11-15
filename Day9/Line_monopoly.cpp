#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    set<pair<int,int>> v;
    int n;cin>>n;
    while(n--){
        int k ; cin>>k;
        if(k==1){
            int x,y; cin>>x>>y;
            if(v.empty()){
                v.insert({x,y});
                continue;
            }
            int l = x;
            int r = y;
            auto it = v.lower_bound({x,0});
            if(it!=v.begin()) it--;
            if(it!=v.end()&&it->second<x-1) it++;
            auto start_it = it;
            while(it!=v.end()&&it->first<=r+1){
                l = min(l,it->first);
                r = max(r,it->second);
                it++;
            }
            v.erase(start_it,it);
            v.insert({l,r});

        }
        if(k==2){
            cout<<v.size()<<"\n";
        }

    }
}