#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int check(vector<ll>&price,ll mid,ll x){
    if(price[mid]>=x) return 1;
    return 0;
}
int main() {
	ll n;
	cin>>n;
	vector<ll>price(n,0);
	for(ll i=0;i<n;i++){
	    cin>>price[i];
	}
	sort(price.begin(),price.end());
	ll n_q;
	cin>>n_q;
	vector<ll>q(n,0);
	for(ll i=0;i<n;i++){
	    cin>>q[i];
	}
	vector<ll>pref(n,0);
	pref[0]=price[0];
	for(ll i=1;i<n;i++){
	    pref[i]=price[i]+pref[i-1];
	}
	ll j=0;
	while(j<n_q){
	    ll x=q[j];
	    ll low=0;
	    ll high=n-1;
	    ll ind=-1;
	    while(low<=high){
	        ll mid=low+(high-low)/2;
	        if(check(price,mid,x)==1){
	            ind=mid;
	            high=mid-1;
	        }else{
	            low=mid+1;
	        }
	    }
	    ll left_len=ind;
	    ll right_len=n-ind;
	    ll ans=0;
	    if(ind==-1){
	        ans=(n*x)-pref[n-1];
	    }else{
	        ans=((left_len*x)-(pref[ind-1])) + ((pref[ind]-pref[ind-1])-(x*right_len));
	    }
	        
	    cout<<ans<<"\n";
	    j++;
	}
	
	
	
}