//hashing Google_OA
//link:https://docs.google.com/document/d/1Y64Xw5WeW6-UYXXuu75_w7_AQU9tlqYdvhGfHc7-XqU/edit
/*Find maximum subarray sum in an array given the condition that the first and last elements of the subarray are equal.
Example
A= { 1,1,2,-1,-3,2,1,}
Result = [1,........1] = 3.
Expected Time Complexity : O(n)*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int prefix[n];
    prefix[0]=arr[0];
    for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+arr[i];
    }
    unordered_map<int,int>mp;
    int sum=0;
    for(int i=0;i<n;i++){
        if(mp.find(arr[i])==mp.end()){
            mp[arr[i]]=i;
        }else{
            int j=mp[arr[i]];
            sum=max(sum,prefix[i]-prefix[j-1]);
        }
    }
    cout<<sum;
    //7 
    //1 1 2 -1 -3 2 1
    
}