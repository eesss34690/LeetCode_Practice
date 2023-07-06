# 72. Edit Distance
###### tags: `leetcode`
## Description
Given two strings `word1` and `word2`, return the minimum number of operations required to convert `word1` to `word2`.

You have the following three operations permitted on a word:

- Insert a character
- Delete a character
- Replace a character
 

- Example 1:

>Input: word1 = "horse", word2 = "ros"
Output: 3
>>Explanation: 
horse $\rightarrow$ rorse (replace 'h' with 'r')
rorse $\rightarrow$ rose (remove 'r')
rose $\rightarrow$ ros (remove 'e')

- Example 2:

>Input: word1 = "intention", word2 = "execution"
Output: 5
>>Explanation: 
intention $\rightarrow$ inention (remove 't')
inention $\rightarrow$ enention (replace 'i' with 'e')
enention $\rightarrow$ exention (replace 'n' with 'x')
exention $\rightarrow$ exection (replace 'n' with 'c')
exection $\rightarrow$ execution (insert 'u')

- Constraints:

>0 $\leq$ word1.length, word2.length $\leq$ 500
`word1` and `word2` consist of lowercase English letters.

## Solution
- This can be done by the observation of specific pattern. Starting from the first character, We can see that there are two chances
    - The two charaters are the same, for the counting, the distance is the same as the previous step to this character comparison
    - The two characters are different, for the counting, the distance may have the following change
        - Use replacement, the counting of this step would be both previous characters of two strings
        - Use insertion, the counting of this step would be only move `word2`
        - Use deletion, the counting of this step would be only move `word1`
- As the result, construct a 2 dimensional matrix in order to finish **dynamic programming** and let the `dp[i][j]` means `the counting of substring word1[0:i] and substring word2[0:j]`.
```cpp=
int m = word1.length();
int n = word2.length();
vector<vector<int>> dp(m + 1, vector<int>(n + 1));
```
- Add one more case, which is the base case, meaning that there is no string in one of them (0 case). And the value should be the other length of the substring.
```cpp=
for (int i = 0; i <= m; i++)
    dp[i][0] = i;
for (int j = 0; j <= n; j++)
    dp[0][j] = j;
```
- To do it in backward fashion, consider the cases, and reverse them
```cpp=
for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
        if (word1[i - 1] == word2[j - 1])
            dp[i][j] = dp[i - 1][j - 1];
        else
            dp[i][j] = 1 + min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]});
    }
}
```