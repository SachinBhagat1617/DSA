//Given a string s containing only a and b, 
//find longest substring of s such that 
//s does not contain more than two contiguous occurences of a and b
// aabbaaaaabbaa
// o/p aabbaa
#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin>>s;
	int n=s.size();
	int i=0,j=-1;
	string ans="";
	int len=0;
	int no_a=0,no_b=0;
	while(i<n){
	    while(j<n-1 && (((s[j+1]=='a' && no_a<2) || (s[j+1]=='b' && no_b<2) || (s[j+1]!='a' && s[j+1]!='b' && no_b<=2 && no_a<=2) ) )){
	        j++;
	        if(s[j]=='a'){
	            no_b=0;
	            no_a++;
	        }
	        if(s[j]=='b'){
	            no_a=0;
	            no_b++;
	        }
	    }
	    int curr_len=j-i+1;
	    if(curr_len>len){
	        len=curr_len;
	        ans=s.substr(i,len);
	    }
	    if(i==n-1 && j==n-1) break;
	    if(i>j){
	        i+=1;
	        j=i-1;
	    }else{
	       i=j;
	       no_a = (s[i] == 'a') ? 1 : 0; // Reset counts for the new starting position
           no_b = (s[i] == 'b') ? 1 : 0;
	    }
	}
	cout<<ans<<"\n";
	return 0;
}