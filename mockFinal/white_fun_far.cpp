#include<bits/stdc++.h>
using namespace std;
const int m =100000007;
int main(){
    ios_base::sync_with_stdio(0);
    int n;cin>>n;
    int prevC = 1, prevE = 1, prevD = 1,prevT = 1;
    int tmpC,tmpE,tmpD,tmpT;
    for(int i = 2;i<=n;i++){
        int tmpC =prevD + prevT;
        int tmpE = prevC + prevT;
        int tmpD = prevE;
        int tmpT = prevC;
        prevC = tmpC%m;
        prevE = tmpE%m;
        prevD = tmpD%m;
        prevT = tmpT%m;
    }
    cout<<(prevC+prevE+prevD+prevT)%m;

}