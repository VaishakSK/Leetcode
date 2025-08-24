/*
2006. Count Number of Pairs With Absolute Difference K
Solved
Easy

Hint: Given an integer array nums and an integer k, return the number of pairs (i, j) where i < j such that |nums[i] - nums[j]| == k.

The value of |x| is defined as:
x if x >= 0.
-x if x < 0.
 

Example 1:
Input: nums = [1,2,2,1], k = 1
Output: 4
Explanation: The pairs with an absolute difference of 1 are:
- [1,2,2,1]
- [1,2,2,1]
- [1,2,2,1]
- [1,2,2,1]

Example 2:
Input: nums = [1,3], k = 3
Output: 0
Explanation: There are no pairs with an absolute difference of 3.

Example 3:
Input: nums = [3,2,1,5,4], k = 2
Output: 3
Explanation: The pairs with an absolute difference of 2 are:
- [3,2,1,5,4]
- [3,2,1,5,4]
- [3,2,1,5,4]
 

Constraints:
1 <= nums.length <= 200
1 <= nums[i] <= 100
1 <= k <= 99
*/

int countKDifference(int* nums, int numsSize, int k) {
    int maxVal = 100; // Problem constraint: nums[i] <= 100 (if LeetCode Q.)
    int freq[101] = {0};  // frequency array
    int count = 0;

    for (int i = 0; i < numsSize; i++) {
        int x = nums[i];

        // check how many previous numbers differ by k
        if (x - k >= 0) count += freq[x - k];
        if (x + k <= maxVal) count += freq[x + k];

        // record current number
        freq[x]++;
    }

    return count;
}

