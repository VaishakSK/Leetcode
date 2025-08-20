/*
917. Reverse Only Letters
Solved
Easy
Hint:Given a string s, reverse the string according to the following rules:

All the characters that are not English letters remain in the same position.
All the English letters (lowercase or uppercase) should be reversed.
Return s after reversing it.

Example 1:
Input: s = "ab-cd"
Output: "dc-ba"

Example 2:
Input: s = "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"

Example 3:
Input: s = "Test1ng-Leet=code-Q!"
Output: "Qedo1ct-eeLg=ntse-T!"
 
Constraints:
1 <= s.length <= 100
s consists of characters with ASCII values in the range [33, 122].
s does not contain '\"' or '\\'.
*/

char* reverseOnlyLetters(char* s) {
    int i=0, index=0, cur=0,len = strlen(s);
    char str[len+1];
    for(int i=0; i<len; i++){
        if(isalpha(s[i])){
            str[index] = s[i];
            index++;
        }
    }
    str[index] = '\0';
    for(int i=len-1; i>=0; i--){
        if(isalpha(s[i])){
            s[i] = str[cur];
            cur++;
        }
    }
    return s;
}
