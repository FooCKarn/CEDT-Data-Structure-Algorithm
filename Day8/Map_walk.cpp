#include<bits/stdc++.h>
using namespace std;
int arr[100][100];
bool used[100][100] = {false};
int R,C;
void recur(int x,int y,string &ans){
     if(x<1||y<1||x>R||y>C||arr[x][y]==1) return ;
     if(used[x][y]||arr[x][y]==1) return ;
     if(x==R&&y==C){
        if(ans.size()>0) cout<<ans<<endl;
        return ;
     }
    used[x][y] = true;
    if(y+1<=C){
        ans.push_back('A');
        recur(x,y+1,ans);
        ans.pop_back();
    }
    if(x+1<=R){
        ans.push_back('B');
        recur(x+1,y,ans);
        ans.pop_back();
    }
    if(x-1>=1){
        ans.push_back('C');
        recur(x-1,y,ans);
        ans.pop_back();
    }
    used[x][y] = false;

}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>R>>C;
    for(int i = 1;i<=R;i++){
        for(int j = 1;j<=C;j++){
            cin>>arr[i][j];
        }
    }
    string s="";
    recur(1,1,s);
    cout<<"DONE";
}