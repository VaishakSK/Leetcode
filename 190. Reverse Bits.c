/*
190. Reverse Bits
Solved
Easy
Topics
premium lock icon
Companies

Reverse bits of a given 32 bits unsigned integer.

Note:

Note that in some languages, such as Java, there is no unsigned integer type. In this case, both input and output will be given as a signed integer type. They should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
In Java, the compiler represents the signed integers using 2's complement notation.
 
Example 1:

Input: n = 43261596
Output: 964176192

Explanation:
Integer Binary
43261596    00000010100101000001111010011100
964176192   00111001011110000010100101000000

Example 2:

Input: n = 2147483644
Output: 1073741822

Explanation:
Integer Binary
2147483644  01111111111111111111111111111100
1073741822  00111111111111111111111111111110

Constraints:
0 <= n <= 2^31 - 2
n is even.
*/


// First implementation
int reverseBits(int n) {
    int arr[32] = {0}, index=0, sum=0;
    while(n>0){
        if(n%2 == 0) arr[index] = 0;
        else arr[index] = 1;
        n/= 2;
        index++;
    }
    index= 0;
    for(int i=31; i>=0; i--){
        sum += arr[i] * pow(2, index);
        printf("sum = %d\n ", sum);
        index++;
    }
    return sum;
}

// Optimized implementation
int reverseBits(int n) {
    unsigned int result = 0;
    for(int i=0; i<32; i++) {
        result <<= 1;      // shift left to make space
        result |= (n & 1); // add LSB of n
        n >>= 1;           // shift n right
    }
    return result;
}
