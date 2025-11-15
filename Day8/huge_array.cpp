#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<pair<int,int>> vec;
    int n,q; cin>>n>>q;
    for(int i = 0;i<n;i++){
        int x,c;
        cin>>x>>c;
        vec.push_back({x,c});
    }
    sort(vec.begin(),vec.end());
    vector<int> pref;
    vector<int> val;
    int cnt = 0;
    for(int i = 0;i<n;i++){
        cnt += vec[i].second;
        pref.push_back(cnt);
        val.push_back(vec[i].first);
    }
    while(q--){
        int k; 
        cin>>k;
        int index = int(lower_bound(pref.begin(),pref.end(),k)-pref.begin());
        cout<<val[index]<<endl;
    }
}