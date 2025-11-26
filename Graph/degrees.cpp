#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int mx = 0;
    vector<int> node(n+10);
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            int k ;cin>>k;
            if(k==1){
                node[i]++;
                mx = max(mx,node[i]);
            }
        }
    }
    vector<int> mem(mx+10);
    for(int i = 1;i<=n;i++){
        mem[node[i]]++;
    }
    for(int i = 0;i<=mx;i++){
        cout<<mem[i]<<" ";
    }
}