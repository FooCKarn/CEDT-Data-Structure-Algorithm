#include<bits/stdc++.h>
using namespace std;
const int m = 100000007;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;cin>>n;
    int end0 = 1;
    int end1 = 1;
    int end2 = 1;
    int end10 = 0;
    int end20 = 0;
    for(int i = 2;i<=n;i++){
        int new0 = (end0 +end10 +end20)%m;
        int new1 = (end0 + end1 + end10)%m;
        int new2 = (end0 + end2+end20)%m;
        int new10 = end1%m;
        int new20 = end2%m;
        end0 = new0;
        end1 = new1;
        end2 = new2;
        end10 = new10;
        end20 = new20;
    }
    cout<<(end0+end1+end2+end10+end20)%m;
}