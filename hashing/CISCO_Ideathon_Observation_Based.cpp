
//Q_Link:https://docs.google.com/document/d/12EwezVPCqLO51mNGvSA9qSR0sko1VWYcjeuK-PSURiQ/edit

//t:TC : O(N) 

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	int arr[n][2];
	for(int i=0;i<n;i++){
	    cin>>arr[i][0];
	    cin>>arr[i][1];
	}
	int rate,max_packets;
	cin>>rate>>max_packets;
	int tot_packets=arr[0][1];
	int packets_drop=0;
	int i=1;
	int initial_time=arr[0][0];
	while(i<n){
	    int g=tot_packets - (rate*(arr[i][0]-initial_time));
	    if(g>0){
	        tot_packets=arr[i][1]+g;
	        if(tot_packets>max_packets){
	            packets_drop+=tot_packets-max_packets;
	            tot_packets=max_packets;
	        }
	    }
	    initial_time=arr[i][0];
	    i++;
	}
	cout<<packets_drop<<endl;
	return 0;
}