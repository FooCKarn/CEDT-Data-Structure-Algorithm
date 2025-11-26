#include<bits/stdc++.h>
using namespace std;
vector<long long> pref;
long long cal(int l,int r,int k){
    return pref[r+1] - pref[l] + (r-l+1)*k;
}
int main(){
   ios_base::sync_with_stdio(0); cin.tie(0);
   int n,m,k;cin>>n>>m>>k;
   pref.resize(n+5,0);
   for(int i = 1;i<=n;i++){
        long long a; cin>>a;
        pref[i] = pref[i-1]+a;
   }
   while(m--){
    int a,b; cin>>a>>b;
    int l = a,r=n-1;
    int ans = a;
    if(cal(a,a,k)>b){
        cout<<"0\n";
        continue;
    }
    while(l<=r){
        int mid = l + ((r-l)/ 2);
        int cost = cal(a,mid,k);
        if(cost<=b){
            ans = mid;
            l = mid+1;
        }
        else{
            r = mid -1 ;
        }
    }
    cout<<pref[ans+1] - pref[a]<<"\n";
   }

   
}