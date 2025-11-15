#include<bits/stdc++.h>
using namespace std;
void gen(string &cur, int idx, int cnt1, int n, int k,bool ok) {
    if (idx == n) {
        if (ok) cout << cur << "\n";
        return;
    }
    if(!ok && cnt1 + (n-idx)<k) return;
    cur.push_back('0');
    gen(cur,idx+1,0,n,k,ok);
    cur.pop_back();

    cur.push_back('1');
    bool tmp_ok = ok || (cnt1+1>=k);
    gen(cur,idx+1,cnt1+1,n,k,tmp_ok);
    cur.pop_back();
}

int main(){
    int n,k; cin>>n>>k;
    string cur;
    cur="";
    gen(cur,0,0,n,k,false);
}