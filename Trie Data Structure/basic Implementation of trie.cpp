#include <iostream>
#include <string>
using namespace std;

int sz = 0;
int t[500000][26];
int dp[500000][26];
//for counting prefix dp2
int dp2[500000][26];

void insert(string s) {
    int v = 0;
    for(int i = 0; i < s.size(); i++) {
        int c = s[i] - 'a' + 1 ;
        // cout << v << " " << c << endl;
        if(t[v][c] == 0) { // pahle baar mila
            sz = sz + 1;
            t[v][c] = sz;
            dp2[v][c]=1;
        }else{ 
            dp2[v][c]=dp2[v][c]+1;
        }
        if(i == s.size() - 1) {
            dp[v][c] = 1;
        }
        
        v = t[v][c];
    }
}

bool search(string tmp) {
    int v = 0;
    for(int i = 0; i < tmp.size(); i++) {
        int c = tmp[i] - 'a'+ 1;
        // cout << v << " " << c << endl;
        if(t[v][c] == 0) {
            return false;
        }
        
        if(i == tmp.size() - 1) {
            if(dp[v][c] == 1) {
                return true;
            }
            return false;
        }
        
        v = t[v][c];
    }

    return false;
}
//for counting prefix
int count(string temp){
    int v=0;
    int c=0;
    for(int i=0;i<temp.size();i++){
        c = temp[i] - 'a' + 1 ;
        // cout << v << "   " << c << "   " << dp2[v][c] << endl;
        if(t[v][c]==0){
            return 0;
        }
        if(i!=temp.size()-1)
            v=t[v][c];
    }
    // cout<<v <<"    "<<c<<endl;
    return dp2[v][c];
}
int main() {
    insert("abb");
    insert("abc");
    insert("def");
    
    if (search("ab"))
        cout << "Found\n";
    else
        cout << "Not Found\n";
    if (search("abb"))
        cout << "Found\n";
    else
        cout << "Not Found\n";
        
    string t="ab";// count how much times this prefix came;
    cout<<count(t)<<"\n";
    cout<<count("cd")<<"\n";
        
    
    return 0;
}
