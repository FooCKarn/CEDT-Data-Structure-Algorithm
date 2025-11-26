#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    const long long m = 100000007;
    int n; cin>>n;
    long long prevA = 1,prevB = 1,prevC=1 ; // prevA is 0 0,B is 0 1 ,C is 1 0
    for(int i = 1;i<=n;i++){
        long long tmpA,tmpB,tmpC;
        tmpA = prevA + prevB + prevC;
        tmpB = prevA + prevC;
        tmpC = prevA + prevB;
        prevA = tmpA%m;
        prevB = tmpB%m;
        prevC = tmpC%m;
    }
    cout<<prevA;
}