#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin>>n>>k;
    vector<int> dp(n+1);
    dp[0]=1;
    vector<int> s;
    for(int i = 0;i<k;i++){
        int t;cin>>t;
        s.push_back(t);
    }
    for(int i = 1;i<=n;i++){
        for(int j = 0;j<k;j++){
            if(i>=s[j]) dp[i] = (dp[i]+dp[i-s[j]])%1000003;
        }
    }
    cout<<dp[n];
}