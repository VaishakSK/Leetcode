/*
Problem: Median of Two Sorted Arrays
Difficulty: Hard

Given two sorted arrays nums1 and nums2 of size m and n respectively, 
return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

Example 1:
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

Constraints:
- nums1.length == m
- nums2.length == n
- 0 <= m <= 1000
- 0 <= n <= 1000
- 1 <= m + n <= 2000
- -10^6 <= nums1[i], nums2[i] <= 10^6
*/

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int a = 0, b = 0;
    double med;
    int tl = nums1Size + nums2Size;
    int total[tl];  // Array to store merged sorted elements

    // Merge the two sorted arrays until we reach the middle point
    for (int i = 0; i <= (tl / 2); i++) {
        if (a < nums1Size && (b >= nums2Size || nums1[a] < nums2[b])) {
            total[i] = nums1[a];
            a++;
        } else {
            total[i] = nums2[b];
            b++;
        }
    }

    int x = tl / 2;

    // If the total number of elements is even, take the average of the middle two
    if (tl % 2 == 0) {
        med = (total[x - 1] + total[x]) / 2.0;
    } else {
        // Otherwise, take the middle element
        med = total[x];
    }

    return med;
}
