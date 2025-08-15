/*
13. Roman to Integer
Solved
Easy

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol   Value
I        1
V        5
X        10
L        50
C        100
D        500
M        1000

For example:
- 2 is written as II in Roman numeral, which is two ones added together.
- 12 is written as XII, which is simply X + II.
- 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right.
However, the numeral for four is not IIII. Instead, the number four is written as IV. 
Because the one is before the five we subtract it, making four.
The same principle applies to the number nine, which is written as IX.

There are six instances where subtraction is used:
- I can be placed before V (5) and X (10) to make 4 and 9.
- X can be placed before L (50) and C (100) to make 40 and 90.
- C can be placed before D (500) and M (1000) to make 400 and 900.

Given a Roman numeral, convert it to an integer.

Example 1:
Input: s = "III"
Output: 3
Explanation: III = 3.

Example 2:
Input: s = "LVIII"
Output: 58
Explanation: L = 50, V = 5, III = 3.

Example 3:
Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90, IV = 4.

Constraints:
1 <= s.length <= 15
s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
It is guaranteed that s is a valid Roman numeral in the range [1, 3999].
*/

int value(char c) {
    if (c == 'I') return 1;
    if (c == 'V') return 5;
    if (c == 'X') return 10;
    if (c == 'L') return 50;
    if (c == 'C') return 100;
    if (c == 'D') return 500;
    if (c == 'M') return 1000;
    return 0;
}

int romanToInt(const char *s) {
    int total = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        int curr = value(s[i]);
        int next = value(s[i + 1]);
        if (curr < next) {
            total -= curr;  // subtract if smaller before bigger
        } else {
            total += curr;  // otherwise add
        }
    }
    return total;
}
