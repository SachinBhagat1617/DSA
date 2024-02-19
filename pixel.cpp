#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string a,b;
        cin>>a;
        cin>>b;
        int count=0;
        char arr[]={a[0],a[1],b[0],b[1]};
        unordered_map<char,int>freq;
        for(int i=0;i<4;i++){
            freq[arr[i]]++;
        }
        count=freq.size();
        if(count==1){
            cout<<0<<endl;
        }else if(count==3){
            cout<<2<<endl;
        }else if(count==2){
            cout<<1<<endl;
        }else if(count==4){
            cout<<3<<endl;
        }
    }
}
