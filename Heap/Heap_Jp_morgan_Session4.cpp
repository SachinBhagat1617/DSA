//link:- https://www.desiqna.in/12816/morgan-sde1-coding-questions-and-solutions-india-april-2023

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    priority_queue<int,vector<int>,greater<int>> pq;
    for(auto it:arr){
        pq.push(it);
    }
    int sum=0;
    while(pq.size()>1){
        int x=pq.top();
        pq.pop();
        int y=pq.top();
        pq.pop();
        sum=sum+x+y;
        pq.push(x+y);
    }
    cout<<sum<<endl;
}