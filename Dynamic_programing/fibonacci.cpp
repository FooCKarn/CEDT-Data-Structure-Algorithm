#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int fibo[50];
    fibo[0] = 0;
    fibo[1] = 1;
    for(int i = 2;i<=45;i++){
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
    int k;cin>>k;cout<<fibo[k];
}