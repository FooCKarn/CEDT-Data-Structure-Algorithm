#include<bits/stdc++.h>
using namespace std;
long long bc(int n,int k){
    if(n==k||k==0) return 1;
    return bc(n-1,k-1) + bc(n-1,k);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    cout<<bc(n,k);
}