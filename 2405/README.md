# 2405. Optimal Partition of String
###### tags: `leetcode`
## Description
Given a string s, partition the string into one or more substrings such that the characters in each substring are unique. That is, no letter appears in a single substring more than once.

Return the minimum number of substrings in such a partition.

Note that each character should belong to exactly one substring in a partition.

- Example 1:

>Input: s = "abacaba"
Output: 4
>>Explanation:
Two possible partitions are ("a","ba","cab","a") and ("ab","a","ca","ba").
It can be shown that 4 is the minimum number of substrings needed.

- Example 2:

>Input: s = "ssssss"
Output: 6
>>Explanation:
The only valid partition is ("s","s","s","s","s","s").

- Constraints:

>$1 \leq s.length \leq 10^5$
s consists of only English lowercase letters.

## Solution
- The problem can be solved by using greedy algorithm. Simply iterate through all the character and replace as a new substring when there is duplication
```cpp=
int idx = s.length() - 1, ans = 1;
while (idx >= 0)
{
    if (vec[s[idx] - 'a'])
    {
        vec = temp;
        ans++;
    }
    vec[s[idx] - 'a'] = true;
    idx--;
}
```