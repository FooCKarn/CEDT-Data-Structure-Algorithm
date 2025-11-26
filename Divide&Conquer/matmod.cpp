#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int> mul(vector<int> a,vector<int> b){
    vector<int> c(4);
    c[0] = (a[0]%k * b[0]%k + a[1]%k * b[2]%k)%k;
    c[1] = (a[0]%k * b[1]%k + a[1]%k * b[3]%k)%k;
    c[2] = (a[2]%k * b[0]%k + a[3]%k * b[2]%k)%k;
    c[3] = (a[2]%k * b[1]%k + a[3]%k * b[3]%k)%k;
    return c;
}
vector<int> cal(vector<int> a,int n){
    if(n==0) return {1,0,0,1};
    vector<int> r = cal(a,n/2);
    vector<int> sq = mul(r,r);
    if(n%2==1) return mul(sq,a);
    else return sq;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    vector<int> a(4);
    cin>>a[0]>>a[1]>>a[2]>>a[3];
    vector<int> result = cal(a,n);
    cout<<result[0]<<" "<<result[1]<<" "<<result[2]<<" "<<result[3];
}