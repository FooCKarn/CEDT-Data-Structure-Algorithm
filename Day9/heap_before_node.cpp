#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,a; cin>>n>>a;
    vector<bool> used(n+10,false);
    queue<int> q;
    if(a==0){
        cout<<"0";
        return 0;
    }
    q.push(a);
    int cnt = 1;
    while(!q.empty()){
        int k = q.front(); q.pop();
        int l = 2*k+1;
        int r = 2*k+2;
        used[k] = true;
        
        
        if(l<n){
            q.push(l);cnt++;used[l] = true;
        }
        if(r<n){
            q.push(r);cnt++;used[r] = true;
        }
    }
    cout<<n-cnt<<endl;
    for(int i = 0;i<n;i++){
        if(!used[i]) cout<<i<<" ";
    }

}