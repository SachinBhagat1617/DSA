#include <bits/stdc++.h>
using namespace std;
//testcase1:
//7
// 5
// 1 5 -1 -1 5 8 10
//output: 26
//testCase2:
//7
// 5
// 1 5 -5 -5 5 8 10
//output: 23
//testCase3:
//8
// 5
// 1 5 -5 8 8 8 10 15
//output: 34
//link:https://www.desiqna.in/15241/atlassian-sde-interview-coding-problem-2023
int main() {
	int n,k;
	cin>>n>>k;
	vector<int>arr(n);
	unordered_map<int,int>mp;
	vector<int>pref(n);
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	}
	pref[0]=arr[0];
	for(int i=1;i<n;i++){
	    pref[i]=pref[i-1]+arr[i];
	}
	int maxi=-1e9;
	for(int i=0;i<n;i++){
	    if(mp.find(arr[i])!=mp.end()){
	        //index at 4
	        // case1: 5 -1 -1 is not -ve so we will not update mp[5]
	        //index at 4
	        //case2 : 5 -5 -5 is -ve sum=-5 so will update mp[5] kyunki humme maximise karna hai sum ko and -ve walse sum ko include kiye to decrease ho jayega
	        if((arr[i]+(pref[i-1]-pref[mp[arr[i]]]))<0){
	            mp[arr[i]]=i;
	        }
	    }else{
	        mp[arr[i]]=i;
	    }
	    int req1=arr[i]-k;
	    int req2=arr[i]+k;
	    if(mp.find(req1)!=mp.end()){
	        maxi=max(maxi,pref[i]-pref[mp[req1]-1]);
	    }
	    if(mp.find(req2)!=mp.end()){
	        maxi=max(maxi,pref[i]-pref[mp[req2]-1]);
	    }
	}
	cout<<maxi<<endl;
	for(auto it:mp){
	    cout<<it.first<<"---->"<<it.second<<'\n';
	}
	//return 0;
}
