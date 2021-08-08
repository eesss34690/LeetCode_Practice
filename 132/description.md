# 132_Palindrome Partitioning II
###### tags: `leetcode` `132`
## Problem Statement
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

- Example 1:

> Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
Example 2:

Input: s = "a"
Output: 0
- Example 3:

> Input: s = "ab"
Output: 1
 
- Constraints:

> $1 \leq s.length \leq 2000$
s consists of lower-case English letters only
## Solution
- This is a typical ```dynamic programming```
- Since there is a string filled with words, we can regard the problem as gradually implement the string one by one word and see the latest result.
```cpp=
vector<int> dp(si, -1);
dp[0]= 0;
```
- After that, the first option to add a cut at the last one.
- Then we need to find whether it is fine to add another combination from the back.
- Go through the whole loop to see whether the back can form a palindrome with others.
- Compare the new value with the original one to see whether it is smaller.
```cpp=
dp[i]= dp[i- 1]+ 1;
int j= 0;
for (; j< i; j++)
{
    if (s[j]!= s[i])
        continue;
    int r= i- 1, l= j+ 1;
    while (l< r)
    {
        if (s[r]!= s[l])
            break;
        l++, r--;
    }
    if (l>= r)
    {
        dp[i]= (j> 0)? ((dp[i]> dp[j- 1]+ 1)? dp[j- 1]+ 1: dp[i]): 0;
    }
}
```