//Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.
// Example 1:

// Input: left = 5, right = 7
// Output: 4
// Example 2:

// Input: left = 0, right = 0
// Output: 0
// Example 3:

// Input: left = 1, right = 2147483647
// Output: 0

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int result = 0;
        for (int i = 31; i >= 0; --i) {
            int bit = 1 << i;
            //At each bit position i, we extract the ith bit from left and right using bitwise AND with a mask (1 << i).
            //If the ith bit is different between left and right, we break the loop since all subsequent bits will also differ.
            if ((left & bit) != (right & bit)) {
                break;
            }
            result |= (left & bit); // Perform bitwise AND, not OR
            // result | because result is 0 and 0 or x is x only
        }
        return result;
    }
};
