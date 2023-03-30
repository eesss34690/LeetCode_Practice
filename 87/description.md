# 87. Scramble String
###### tags: `leetcode`
## Description
We can scramble a string s to get a string t using the following algorithm:

If the length of the string is 1, stop.
If the length of the string is > 1, do the following:
Split the string into two non-empty substrings at a random index, i.e., if the string is s, divide it to `x` and `y` where `s = x + y`.
Randomly decide to swap the two substrings or to keep them in the same order. i.e., after this step, `s` may become `s = x + y` or `s = y + x`.
Apply step 1 recursively on each of the two substrings `x` and `y`.
Given two strings `s1` and `s2` of the same length, return `true` if `s2` is a scrambled string of `s1`, otherwise, return `false`.

- Example 1:

>Input: s1 = "great", s2 = "rgeat"
Output: true
>>Explanation: One possible scenario applied on s1 is:
"great" --> "gr/eat" // divide at random index.
"gr/eat" --> "gr/eat" // random decision is not to swap the two substrings and keep them in order.
"gr/eat" --> "g/r / e/at" // apply the same algorithm recursively on both substrings. divide at random index each of them.
"g/r / e/at" --> "r/g / e/at" // random decision was to swap the first substring and to keep the second substring in the same order.
"r/g / e/at" --> "r/g / e/ a/t" // again apply the algorithm recursively, divide "at" to "a/t".
"r/g / e/ a/t" --> "r/g / e/ a/t" // random decision is to keep both substrings in the same order.
The algorithm stops now, and the result string is "rgeat" which is s2.
As one possible scenario led s1 to be scrambled to s2, we return true.

- Example 2:

>Input: s1 = "abcde", s2 = "caebd"
Output: false

- Example 3:

>Input: s1 = "a", s2 = "a"
Output: true

- Constraints:

>s1.length == s2.length
$1 \leq s1.length \leq 30$
s1 and s2 consist of lowercase English letters.

## Solution
- The problem is a harder dynamic problem. Using simple recursive worked fine in the previous submission but for now the new added constraint gives `TLE`
- For each of the char combination with string 1 and string 2, check the permutation for each of the substring. Return the same if one of the split meets
- dp vector use dp[i][j][length] to represent whether s1[i:i+length] and s2[j:j+length] are scrambled versions of each other. 
```cpp=
for (int length = 2; length <= n; length++) {
    for (int i = 0; i <= n-length; i++) {
        for (int j = 0; j <= n-length; j++) {
            for (int k = 1; k < length; k++) {
                if ((dp[i][j][k] && dp[i+k][j+k][length-k]) || (dp[i][j+length-k][k] && dp[i+k][j][length-k])) {
                    dp[i][j][length] = true;
                    break;
                }
            }
        }
    }
}
```
- Return the last one of the whole array
```cpp=
return dp[0][0][n];
```