# 516. Longest Palindromic Subsequence
###### tags: `leetcode`
## Description
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

- Example 1:

>Input: s = "bbbab"
Output: 4
>>Explanation: One possible longest palindromic subsequence is "bbbb".

- Example 2:

>Input: s = "cbbd"
Output: 2
>>Explanation: One possible longest palindromic subsequence is "bb".

- Constraints:

>$1 \leq s.length \leq 1000$
s consists only of lowercase English letters.

## Solution
- The problem can be solved by backtracing with dynamic programming
- The key core in that the outer layer relies on the inner layer. Consequently, we can finish the dp vector by filling the smaller substring first and then layer up
- For the one with length 1, it is satisfied and the length is just 1
```cpp=
if (i == 1) dp[start][end] = 1;
```
- For the later on, if the values for the two edges are the same, add as the inner value plus the two
```cpp=
else if (s[start] == s[end])dp[start][end] = 2 + dp[start + 1][end - 1];
```
- If the values are not the same, then the substring can see the two that contains one edge left
```cpp=
else dp[start][end] = max(dp[start + 1][end], dp[start][end - 1]);
```