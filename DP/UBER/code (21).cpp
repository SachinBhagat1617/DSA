/*Link - https://www.desiqna.in/17735/uber-oa-ctc-60-l-sde1-sep-5 

-> Given an array of size “N” ; you have to do 3 type of operations sequentially 

-> First delete any p elements;

-> Then delete any q-adjacent pair elements. 

-> Then delete any r-adjacent triplet elements. 

After doing all this :- Sum of the remaining array should be maximum.
*/
#include <bits/stdc++.h>
using namespace std;

int dp[104][34][34][34];  // DP array to store results
int n;

// Helper function to maximize the sum of the remaining array
int helper(int ind, int p, int q, int r, vector<int>& arr) {
    // Base case: if all deletions are done, return 0 (no more elements to remove)
    if (p == 0 && q == 0 && r == 0) {
        return 0;
    }

    // If we've reached the end of the array
    if (ind == n) {
        if (p == 0 && q == 0 && r == 0) {
            return 0;
        } else {
            return -1e9;  // Invalid case: no more elements, but deletions are left
        }
    }

    // Memoization check
    if (dp[ind][p][q][r] != -1) return dp[ind][p][q][r];

    int ans1 = -1e9, ans2 = -1e9, ans3 = -1e9;

    // Option 1: Delete 1 element if p > 0
    if (p > 0) {
        ans1 = helper(ind + 1, p - 1, q, r, arr);  // Delete arr[ind], skip this element
    }

    // Option 2: Delete 2 adjacent elements if q > 0 and there are at least 2 elements left
    if (q > 0 && ind + 1 < n) {
        ans2 = helper(ind + 2, p, q - 1, r, arr);  // Delete arr[ind] and arr[ind+1], skip both
    }

    // Option 3: Delete 3 adjacent elements if r > 0 and there are at least 3 elements left
    if (r > 0 && ind + 2 < n) {
        ans3 = helper(ind + 3, p, q, r - 1, arr);  // Delete arr[ind], arr[ind+1], arr[ind+2], skip all 3
    }

    // Option 4: Do not delete the current element, move to the next
    int ans4 = arr[ind] + helper(ind + 1, p, q, r, arr);

    // Store the result and return the maximum of all options
    return dp[ind][p][q][r] = max({ans1, ans2, ans3, ans4});
}

int main() {
    int p, q, r;
    cin >> n;  // Size of the array
    vector<int> arr(n);
    
    // Input array elements
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Input the number of deletions for p, q, and r
    cin >> p >> q >> r;

    // Initialize the dp array with -1
    memset(dp, 0, sizeof(dp));

    // Call the helper function and output the result
    //cout << helper(0, p, q, r, arr) << endl;
     

    return 0;
}
