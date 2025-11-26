#include<bits/stdc++.h>
using namespace std;
vector<int> a(1010);
vector<int> c(1010);
vector<int> ans;
int k;
const int m = 32717;
int recur(int n){
    if(ans[n]!=INT_MIN) return ans[n];
    int sum = 0;
    for(int i = 0;i<k;i++){
        sum += (c[i] * recur(n-i-1))%m;
    }
    ans[n] = sum%m;
    return sum%m;

}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>k>>n;
    ans.resize(n+1,INT_MIN);
    for(int i = 0;i<k;i++) cin>>c[i];
    for(int i = 0;i<k;i++) cin>>ans[i];
    cout<<recur(n);
}