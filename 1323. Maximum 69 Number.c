/*
1323. Maximum 69 Number
Solved
Easy

You are given a positive integer num consisting only of digits 6 and 9.

Return the maximum number you can get by changing at most one digit (6 becomes 9, and 9 becomes 6).

Example 1:
Input: num = 9669
Output: 9969
Explanation: 
Changing the first digit results in 6669.
Changing the second digit results in 9969.
Changing the third digit results in 9699.
Changing the fourth digit results in 9666.
The maximum number is 9969.

Example 2:
Input: num = 9996
Output: 9999
Explanation: Changing the last digit 6 to 9 results in the maximum number.

Example 3:
Input: num = 9999
Output: 9999
Explanation: It is better not to apply any change.

Constraints:
1 <= num <= 10^4
num consists of only 6 and 9 digits.
*/

int maximum69Number (int num) {
    int n[7], dig, index = 0, total = 0;

    // extract digits
    while (num > 0) {
        dig = num % 10;
        num /= 10;
        n[index++] = dig;
    }

    // change first 6 (from most significant side) to 9
    for (int i = index - 1; i >= 0; i--) {
        if (n[i] == 6) {
            n[i] = 9;
            break;
        }
    }

    // reconstruct number
    for (int i = index - 1; i >= 0; i--) {
        total = total * 10 + n[i];
    }

    return total;
}
