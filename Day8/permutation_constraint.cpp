#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> chk;
vector<bool> used;
vector<int> cur;
int n,m;
bool valid(int x){
    for(auto [a,b]:chk){
        if(b==x && !used[a]) return true;
    }
    return false;
}
void recur(){
    if(cur.size() == n){
        for(auto x:cur) cout<<x<<" ";
        cout<<"\n";
        return;
    }
    for(int i = 0;i<n;i++){
        if(used[i]) continue;
        if(valid(i)) continue;
        used[i] = true;
        cur.push_back(i);
        recur();
        cur.pop_back();
        used[i] = false;
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        int a,b;
        cin>>a>>b;
        chk.push_back({a,b});
    }
    used.assign(n+100,false);
    recur();
}