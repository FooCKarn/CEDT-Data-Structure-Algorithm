#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;cin>>n;
    int arr[n+1][n+1] ;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    int mx = INT_MIN;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            int sum = 0;
            for(int k = 0;k<=n;k++){
                if(i+k>=n||j+k>=n) break;
                sum += arr[i+k][j+k];
                mx = max(sum,mx);
            }
        }
    }
    cout<<mx;
}