#include<bits/stdc++.h>
using namespace std;
string str;
vector<string> ans;
bool used[100000] ={false};
void recur(string &tmp){
    if(tmp.size() == str.size()){
        ans.push_back(tmp);
        return;
    }
    for(int i = 0;i<str.size();i++){
            if(used[i]) continue;
            if(i > 0 && str[i] == str[i-1] && !used[i-1]) continue;
            used[i] = true;
            tmp.push_back(str[i]);
            recur(tmp);
            used[i] = false;
            tmp.pop_back();
        }
 }
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>str; 
    sort(str.begin(),str.end());
    string tmp = "";
    recur(tmp);
    cout<<ans.size()<<endl;
   
    for(auto x:ans) cout<<x<<endl;
}