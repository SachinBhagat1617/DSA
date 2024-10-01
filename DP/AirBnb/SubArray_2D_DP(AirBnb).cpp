// 4
// 1 5 8 10
// 3 8 2 1
// There are 'n' stones in a row from 0 to n-1. For every ith stone , there are 2 values associated with it, a[i] and b[i] . You have to remove all the stones from the row one by one. Removing the ith stone follows the rule :

// If (i-1)th and (i+1)th stones are still present , then , cost of removing the ith stone is b[i].

// if either (i-1)th or (i+1)th stone is present , then cost of removing the ith stone is a[i].

// if neither (i-1)th nor (i+1)th stone is present , the cost of removing the ith stone is 0.

// Find the minimum total cost of removing all the stones.

// Constraints : 1 <= n <= 50000 1 <= a[i] , b[i] <= 1000
#include <bits/stdc++.h>
using namespace std;
int dp[1004][1004];
int main() {
    // O(N^3) you have to do it in O(N^2) upsolve it
	int n;
	cin>>n;
	vector<int>a(n,0);
	vector<int>b(n,0);
	for(int i=0;i<n;i++){
	    cin>>a[i];
	}
	for(int i=0;i<n;i++){
	    cin>>b[i];
	}
	// length =1
	int i=0;
	while(i<n){
	    dp[i][i]=0;
	    i++;
	}
	// length=2 
	i=0;
	while(i<n-1){
	    if(i==0){
	        dp[i][i+1]=a[i]+dp[i+1][i+1];
	    }else{
	        dp[i][i+1]=min((a[i]+dp[i+1][i+1]),(a[i+1]+dp[i-1][i-1]));
	    }
	    i++;
	}
    int len=3;
    while(len<=n){
        i=0;
        while(i<=n-len){
            int j=len+i-1;
            int ans=1e9;
            for(int k=i;k<=j;k++){
                // solve for len
                if(k==i){
                    ans=min(ans,a[k]+dp[k+1][j]);
                }else if(k==j){
                    ans=min(ans,a[k]+dp[i][k-1]);
                }else{
                    ans=min(ans,b[k]+dp[i][k-1]+dp[k+1][j]);
                }
            }
            dp[i][j]=ans;
            i++;
        }
        len++;
    }
    cout<<dp[0][n-1]<<"\n";
}