/*
Problem: String to Integer (atoi)
Difficulty: Medium

Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

The algorithm for myAtoi(string s) is as follows:
1. Whitespace: Ignore any leading whitespace (" ").
2. Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
3. Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached.
   If no digits were read, then the result is 0.
4. Rounding: If the integer is out of the 32-bit signed integer range [-2^31, 2^31 - 1], 
   then round the integer to remain in the range.

Example 1:
Input: s = "42"
Output: 42

Example 2:
Input: s = "   -042"
Output: -42

Example 3:
Input: s = "1337c0d3"
Output: 1337

Example 4:
Input: s = "0-1"
Output: 0

Example 5:
Input: s = "words and 987"
Output: 0

Constraints:
- 0 <= s.length <= 200
- s consists of English letters (lower-case and upper-case), digits (0-9), ' ', '+', '-', and '.'
*/

#include <string.h>
#include <limits.h>

int myAtoi(char *s) {
    int i = 0;
    int n = strlen(s);

    // 1. skip leading whitespace
    while (i < n && s[i] == ' ') i++;

    // 2. optional sign
    int sign = 1;
    if (i < n && (s[i] == '+' || s[i] == '-')) {
        if (s[i] == '-') sign = -1;
        i++;
    }

    // 3. parse digits and build result using long long to detect overflow
    long long result = 0;
    while (i < n && s[i] >= '0' && s[i] <= '9') {
        int digit = s[i] - '0';
        result = result * 10 + digit;

        // early clamp checks
        if (sign == 1 && result > INT_MAX) return INT_MAX;
        if (sign == -1 && result > (long long)INT_MAX + 1) return INT_MIN;

        i++;
    }

    result *= sign;

    // final clamp (should be redundant due to early checks)
    if (result > INT_MAX) return INT_MAX;
    if (result < INT_MIN) return INT_MIN;
    return (int)result;
}
