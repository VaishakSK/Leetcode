/*
35. Search Insert Position
Solved
Easy
Topics
premium lock icon
Companies

Given a sorted array of distinct integers and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2

Example 2:
Input: nums = [1,3,5,6], target = 2
Output: 1

Example 3:
Input: nums = [1,3,5,6], target = 7
Output: 4

Constraints:
1 <= nums.length <= 10^4
-10^4 <= nums[i] <= 10^4
nums contains distinct values sorted in ascending order.
-10^4 <= target <= 10^4
*/

int searchInsert(int* nums, int numsSize, int target) {
    int found = 0;
    for(int i=0; i<numsSize; i++){
        if(nums[i] == target){
            found = 1;
            return i;
        }
    }
    if(found == 0){
        for(int i=0; i<numsSize - 1; i++){
            if(target > nums[i] && target < nums[i+1]){
                return i+1;
            }
        }
    }
    if(target > nums[0]){
        return numsSize;
    }
    else
        return 0;
}
