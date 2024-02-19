//16 FEB 2024 MoranStanely OA
//link:- https://docs.google.com/document/d/1yYmlKfUW7bBmwC0l8TKTclON6h6y77wEWauNWaqp-Pg/edit

#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int main(){
    int n,m;
    cin>>n>>m;
    int arr[n+1];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    // length=1
    if(arr[1]==-1){
        for(int i=0;i<m;i++){
            dp[1][i]=1;
        }
    }else{
        dp[1][arr[1]]=1;
    }
    // length>2
    //dp[i][j] = number of ways to create a type1 wave till index “i”
    //such that the number at index “i” is assumed to be j. If b[i] = -1; 
    //else you have to take the fixed number 
    for(int i=2;i<=n;i++){
        if(arr[i]==-1){
            for(int j=1;j<m;j++){
                if(i%2==0){// even pos
                    for(int k=1;k<j;k++){
                        dp[i][j]+=dp[i-1][k];
                        dp[i][j]%=mod;
                    }
                }else{
                    for(int k=j+1;k<=m;k++){
                        dp[i][j]+=dp[i-1][k];
                        dp[i][j]%=mod;
                    }
                }
            }
        }else{
            for(int k=1;k<=m;k++){
                if(k!=arr[i]){
                    dp[i][arr[i]]+=dp[i-1][k];
                    dp[i][arr[i]]%=mod;
                }
                
            }
        }
    }
    int ans=0;
    if(arr[n]=-1){
        for(int k=1;k<=m;k++){
            ans+=dp[n][k];
            ans%=mod;
        }
    }else{
        ans=dp[n][arr[n]];
        ans%=mod;
    }
    cout<<ans<<endl;
}
