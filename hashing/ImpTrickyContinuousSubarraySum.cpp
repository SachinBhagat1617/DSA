/*523. Continuous Subarray Sum
Solved
Medium
Topics
Companies
Given an integer array nums and an integer k, return true if nums has a good subarray or false otherwise.

A good subarray is a subarray where:

its length is at least two, and
the sum of the elements of the subarray is a multiple of k.
Note that:

A subarray is a contiguous part of the array.
An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.
 

Example 1:

Input: nums = [23,2,4,6,7], k = 6
Output: true
Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.
Example 2:

Input: nums = [23,2,6,4,7], k = 6
Output: true
Explanation: [23, 2, 6, 4, 7] is an continuous subarray of size 5 whose elements sum up to 42.
42 is a multiple of 6 because 42 = 7 * 6 and 7 is an integer.
Example 3:

Input: nums = [23,2,6,4,7], k = 13
Output: false*/

class Solution {
public:
    bool checkSubarraySum(vector<int> &nums, int k){
        // we will store the prefixSumMod and first occurence in the map
        unordered_map<int, int> mpp;
        long long prefixSum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            prefixSum += nums[i];
            int prefixSumMod = prefixSum % k;
            // if prefixSumMod is 0 means subarray from 0 to that i has sum divisble by k
            // i+1 >= 2 means as indexing in array starts from 0 means minimum length is 2 because written in the question, minimum length should be 2
            if (prefixSumMod == 0 && i + 1 >= 2)
                return true;
            //agar wo remainder already present hai to divisible by k
            if (mpp.find(prefixSumMod) != mpp.end())
            {
                if (i - mpp[prefixSumMod] >= 2)
                    return true;
            }
            else
            {
                mpp[prefixSumMod] = i;
            }
        }
        return false;
    }

};
 
