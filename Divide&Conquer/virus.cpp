#include<bits/stdc++.h>
using namespace std;
vector<int> dna;
bool recur(int st,int en,bool rv){
    if(en-st==2){
        if(!rv){
            return dna[st] == 0 &&dna[st+1]==1;
        }
        else return dna[st] == 1 &&dna[st+1]==0;
    }
    int mid = (st+en)/2;
    if(!rv) return (recur(st,mid,true) || recur(st,mid,false) )&& recur(mid,en,false);
    else return (recur(mid,en,true) || recur(mid,en,false) )&& recur(st,mid,true);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,k;cin>>n>>k;
    int len = pow(2,k);
    dna.reserve(len);
    while(n--){
        dna.resize(len);
        for(int i = 0;i<len;i++){
            cin>>dna[i];
        }
        cout<< ((recur(0,len,false))? "yes\n": "no\n");
    }
}