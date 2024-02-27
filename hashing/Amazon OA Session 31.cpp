//hashing Amazon_OA
//link:https://docs.google.com/document/d/1ndmwNjcfyY3kTTou4-olNLki34aBg6xpgBXgxkz_PWk/edit

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int x;
    cin>>x;
    //dekho question mai bola hai pairs ka condition (arr[i]+arr[j])%x==0
    //let price=[31,25,85,29,35], x=60
    // we have to count the pairs which are divisible by x; here output is 3 (85,35) (31,29) (25,35)
    //let assume this pair (85,35) sum is 120 divisible by 60
    //suppose we are at 35 then how to find 85 ?
    //so we have to make a pair divisible by 60 to do so
    //if no is not divisible by 60 then make a pair such that their remainder sum get divisible by 60
    //kyunki agar tum 35 ko divide karoge 60 se to dekhoge ki tumhe 25 aur chahiye to make it divisible by 60
    // and ye extra 25 kaha se aya as said by modi ji ye 85 se ayega kyunki 85%60=25
    //25+35=60 which is divisible by 60
    unordered_map<int,int>mp;
    int cnt=0;
    for(int i=0;i<n;i++){
        int req_rem=x-(arr[i]%x);
        req_rem=req_rem%x; // because what if req_rem is 0 then we need another no with rem 0
        // so req_rem=60-(120%60)=60 so make it once more mod by 60 req_rem%=x =>req_rem=60%60=0
        cnt+=mp[req_rem];
        mp[arr[i]%x]++;
    }
    cout<<cnt;
    
    
}
