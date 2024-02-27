//atlassian OA
//hashing session 29
//link:https://docs.google.com/document/d/1f2VzhDu7z0fxBgn5TcpW0xf0wVyPFePNW_Iezlvk_oI/edit

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // analyse the equation
    //=>s[i]-s[j]=i-j (condition for balance)
    //=>s[i]-i=s[j]-j
    // means we have to find the largest sum of subsequence having s[i]-i=s[j]-j=s[k]-k
    
    //eg: arr=[1,5,3,7,8]
//no.thatcanbalance (1-0),(5-1),(3-2),(7-3),(8-4)
           //=[1,4,1,4,4]
           //mp[1]=1+3  mp[4]=5+7+8=20
    
    unordered_map<int,int>mp;
    int maxi=-1e9;
    for(int i=0;i<n;i++){
        int b=arr[i]-i;
        mp[b]+=arr[i];
        maxi=max(maxi,mp[b]);
    }
    cout<<maxi<<endl;
    
    
}
