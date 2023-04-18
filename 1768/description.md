# 1768. Merge Strings Alternately
###### tags: `leetcode`
## Description
You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string.

- Example 1:

>Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
>>Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r

- Example 2:

>Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"
>>Explanation: Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b
word2:    p   q   r   s
merged: a p b q   r   s

- Example 3:

>Input: word1 = "abcd", word2 = "pq"
Output: "apbqcd"
>>Explanation: Notice that as word1 is longer, "cd" is appended to the end.
word1:  a   b   c   d
word2:    p   q
merged: a p b q c   d

- Constraints:

>$1 \leq word1.length, word2.length \leq 100$
word1 and word2 consist of lowercase English letters.

## Solution
- The problem is jusst go through the two set of string until one of them reach the end
```cpp=
string ans = "";
int idx = 0;
while (idx < word1.length() && idx < word2.length())
{
    ans += word1[idx];
    ans += word2[idx];
    idx++;
}
```
- The rest of the string should be concanated in the back
```cpp=
if (idx < word1.length()) ans += word1.substr(idx);
else if (idx < word2.length()) ans += word2.substr(idx);
```
