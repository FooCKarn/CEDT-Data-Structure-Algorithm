#include <bits/stdc++.h>
using namespace std;
int main() {
    std::ios_base::sync_with_stdio(false);
    long long n;cin>>n;
    map<long long,bool> mp;
    for(int i = 0;i<n;i++){
        int k; cin>>k;
        mp[k] = true;
    }
    for(int i = 1;i<=n;i++){
        if(!mp[i]){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
}