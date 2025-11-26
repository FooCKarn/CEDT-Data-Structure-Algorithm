#include<bits/stdc++.h>
using namespace std;
vector<int> dna;
bool recur(int st,int en){
    int len = (en-st) + 1;
    if(len==1) return true;
    int mid = (st+en)/2;
    int c1=0,c2=0;
    for(int i = st;i<=mid;i++) if(dna[i]==1) c1++;
    for(int i = mid+1;i<=en;i++) if(dna[i]==1) c2++;
    if(abs(c1-c2)>1) return false;
    return recur(st,mid) && recur(mid+1,en);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,k;cin>>n>>k;
    int len = pow(2,k);
    dna.reserve(len);
    while(n--){
        dna.resize(len);
        for(int i = 0;i<len;i++){
            cin>>dna[i];
        }
        if(recur(0,len-1)) cout<<"yes\n";
        else cout<<"no\n";
    }
} 
