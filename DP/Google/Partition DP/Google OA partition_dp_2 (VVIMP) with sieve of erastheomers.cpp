// given an string s count the no of way you can partition it into different substring such that 
// each partition is prime
// constraints: 1<=sizeof(s)<=1e5 and If you encounter a number greater than 6 digits while checking for prime status in the given code, you can safely skip checking that substring. The problem constraints specify that you are only interested in partitions where each substring is a prime number and is at most 6 digits long (since 6 digits can represent numbers up to 999,999).
// eg : 11375 can be partitioned into 3 ways:
// {11,3,7,5} , {11,37,5} , {113, 7, 5}

#include <bits/stdc++.h>
using namespace std;
int n;
int maxNum=1e5+4;
vector<int>isPrime(maxNum,1);
// vvimp the size of string is 1e5 but the maxNum which you can generate through substring is of length less than equal to 6
void sieve() {
    isPrime.assign(maxNum + 1, true);
    isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime numbers
    for (int i = 2; i * i <= maxNum; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= maxNum; j += i) {
                isPrime[j] = false;
            }
        }
    }
}
int main() {
    string s;
    cin >> s;
    n = s.size();
    sieve();
    vector<int> dp(n + 1, 0);
    dp[0]=1;
    //convert it to 1 based indexing
    for(int i=0;i<n;i++){
        int j=i;
        while(j>=0 && (i-j+1)<=6){
            int len=i-j+1;
            int num=stoi(s.substr(j,len));
            // Avoid leading zeros except for the single digit '0'
            if (s[j] == '0' && len > 1) {
                continue; // Skip invalid substrings
            }
            if(isPrime[num]==1){
                //dp[i]+=dp[j-1]; 0 based indexing
                dp[i+1]+=dp[j];//1based
            }
                
            j--;
        }
    }
    cout<<dp[n]<<"\n";
}


// int n;
// // o(n^3)
// // Function to check if a number is prime
// int isPrime(int num) {
//     if (num <= 1) return 0;
//     if (num == 2) return 1;
//     for (int i = 2; i * i <= num; i++) {
//         if (num % i == 0) {
//             return 0;
//         }
//     }
//     return 1;
// }

// // Helper function to recursively find the number of valid partitions
// int helper(int ind, int prevInd, string &s, vector<vector<int>> &dp) {
//     // Base case: If we have processed all characters in the string
//     if (ind < 0) {
//         return 1; // Successfully partitioned the entire string
//     }

//     // If the result for this state is already computed, return it
//     if (dp[ind][prevInd] != -1) return dp[ind][prevInd];

//     int ans = 0;

//     // Try forming substrings from the current index and check if they form primes
//     for (int i = ind; i >= 0; i--) {
//         int len = prevInd - i;
//         int num = stoi(s.substr(i, len)); // Convert the substring to an integer
//         if (isPrime(num)) {
//             // If it's prime, continue partitioning the rest of the string
//             ans += helper(i - 1, i, s, dp);
//         }
//     }

//     // Store and return the result for this state
//     return dp[ind][prevInd] = ans;
// }

// int main() {
//     string s;
//     cin >> s;
//     n = s.size();

//     // Initialize the DP array with -1 (to signify uncalculated states)
//     vector<vector<int>> dp(n, vector<int>(n + 1, -1));

//     // Start recursion from the last index and the size of the string as prevInd
//     cout << helper(n - 1, n, s, dp) << "\n";
// }
