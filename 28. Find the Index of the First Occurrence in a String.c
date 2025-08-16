/*
28. Find the Index of the First Occurrence in a String
Solved
Easy
Topics
premium lock icon
Companies

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

Example 2:
Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.

Constraints:
1 <= haystack.length, needle.length <= 10^4
haystack and needle consist of only lowercase English characters.
*/

#include <stdio.h>
#include <string.h>

int strStr(char* haystack, char* needle) {
    int len1 = strlen(haystack);
    int len2 = strlen(needle);

    if (len2 == 0) return 0;  // An empty needle appears at index 0

    for (int i = 0; i <= len1 - len2; i++) {
        int j = 0;
        while (j < len2 && haystack[i + j] == needle[j]) {
            j++;
        }
        if (j == len2) {
            return i;  // Match found
        }
    }
    return -1;  // No match found
}
