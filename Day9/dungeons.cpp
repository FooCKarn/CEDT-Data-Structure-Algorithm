#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    map<int,priority_queue<int,vector<int>,greater<int>>> mp;
    int n,d,t,z;
    cin>>n>>d>>t>>z;
    while(d--){
        int a,b;cin>>a>>b;
        mp[b].push(a);
    }
    int cnt = 0;
    bool flag = false;
    for(int i = 0;i<n;i++){
        int q;cin>>q;
        while(q--){
            int item;cin>>item;
            if(flag) break;
            if(mp.find(item)==mp.end()){
                flag = true;
                break;
            }
            else{
                t-=mp[item].top();
                mp[item].pop();
                if(t<0){
                    flag = true;
                    break;
                }
            }
        }
        if(!flag) cnt++;
    }
    cout<<cnt;
}