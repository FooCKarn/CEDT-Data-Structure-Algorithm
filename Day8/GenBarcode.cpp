#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b; cin>>a>>b;
    string s(b-a,'0');
    s += string(a,'1');
    cout<<s<<endl;
    while(next_permutation(s.begin(),s.end())){
        cout<<s<<endl;
    }
}