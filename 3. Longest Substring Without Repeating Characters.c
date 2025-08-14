/*
Problem: Longest Substring Without Repeating Characters
Difficulty: Medium

Given a string s, find the length of the longest substring without duplicate characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.

Constraints:
- 0 <= s.length <= 5 * 10^4
- s consists of English letters, digits, symbols and spaces.
*/

int lengthOfLongestSubstring(char* s) {
    int n = strlen(s);
    int maxLength = 0; // to store the length of the longest substring
    int start = 0; // start index of the current substring
    
    // Create an array to store the last index of each character (ASCII characters)
    int lastIndex[256]; // 256 for all possible characters (ASCII)
    
    // Initialize all elements of lastIndex to -1, meaning character hasn't been seen
    for (int i = 0; i < 256; i++) {
        lastIndex[i] = -1;
    }
    
    for (int i = 0; i < n; i++) {
        // If the character has been seen before, move the start index
        if (lastIndex[(int)s[i]] >= start) {
            start = lastIndex[(int)s[i]] + 1; // move start right after the last occurrence
        }
        
        // Update the last index of the character
        lastIndex[(int)s[i]] = i;
        
        // Calculate the length of the current substring and update maxLength if necessary
        int currentLength = i - start + 1;
        if (currentLength > maxLength) {
            maxLength = currentLength;
        }
    }
    
    return maxLength;
}
