// Understanding -> Pick subset of elements from array -> Sum of that subset should be maximum. 

// -> If you pick a group of 2 numbers; you can again do this operation only after ignoring 1 next number 

// -> You can select a group of 3 numbers as well -> but if you do that the next 2 numbers should not be selected and the same goes for the previous 2 numbers. 

// test Case:
// 3
// 5
// 4 1 1 5 6
// 4
// 1 2 3 4
// 5
// 1 5 5 5 1

// ouput:
// 16
// 9
// 15
#include <bits/stdc++.h>
using namespace std;
int n;
int helper(int ind,vector<int>a,vector<int>&dp){
    if(ind>=n){
        return 0;
    }
    if(dp[ind]!=-1) return dp[ind];
    int ans1=0,ans2=0;
    if(ind+1<n){
        ans1=a[ind]+a[ind+1]+helper(ind+3,a,dp);
    }
    if(ind+2<n){
        ans2=a[ind]+a[ind+1]+a[ind+2]+helper(ind+5,a,dp);
    }
    int ans3=helper(ind+1,a,dp);
    return dp[ind]=max({ans1,ans2,ans3});
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    cin>>n;
	    vector<int>a(n,0);
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    vector<int>dp(n+1,-1);
	    cout<<helper(0,a,dp)<<"\n";
	}
	return 0;
}