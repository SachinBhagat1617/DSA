//To find the number of ways to choose k elements from an array arr such that the 
//sum of those elements does not exceed m. 

// Code Explanation
// Input Variables:

// m: The maximum sum limit.
// k: The number of elements to choose.
// n: The total number of elements in the array.

// test case
/*
n=5,m=5,k=4
arr={1,2,3,4,4}
O/P=2
valid partions are: {1,2},{3},{4},{4} and {1},{2,3},{4},{4}
*/
#include <bits/stdc++.h>
using namespace std;
// iterative way
int main() {
	int m,n,k;
	cin>>m>>k>>n;
	vector<int>arr(n+1,0);
	for(int i=1;i<=n;i++){
	    cin>>arr[i];
	}
	vector<vector<int>>dp(n+4,vector<int>(k+4,0));
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
	    for(int j=1;j<=k;j++){
	        int sum=0;
	        for(int l=i;l>=1;l--){
    	        sum+=arr[l];
    	        if(sum<=m){
    	            dp[i][j]+=dp[l-1][j-1];
    	        }else{
    	            break;
    	        }
    	    }
	    }
	}
	cout<<dp[n][k]<<"\n";
	
}
// memomized code
/*#include <bits/stdc++.h>
using namespace std;
int m,n,k;
int helper(int ind,int k,vector<int>& arr,vector<vector<int>>& dp){
    if(ind==0 && k==0){
        return 1;
    }
    if(k==0 || ind==0){
        return 0;
    }
    if(dp[ind][k]!=-1) return dp[ind][k];
    int sum=0;
    int ans=0;
    for(int i=ind;i>=1;i--){
        sum+=arr[i];
        if(sum<=m){
            ans+=helper(i-1,k-1,arr,dp);
        }else break;
    }
    return dp[ind][k]=ans;
}
int main() {
	cin>>m>>k>>n;
	vector<int>arr(n+1,0);
	for(int i=1;i<=n;i++){
	    cin>>arr[i];
	}
	vector<vector<int>>dp(n+4,vector<int>(k+4,-1));
	cout<<helper(n,k,arr,dp)<<"\n";
}*/