# 859. Buddy Strings
###### tags: `leetcode`
## Description
Given two strings s and goal, return true if you can swap two letters in s so the result is equal to goal, otherwise, return false.

Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at s[i] and s[j].

For example, swapping at indices 0 and 2 in "abcd" results in "cbad".

- Example 1:

>Input: s = "ab", goal = "ba"
Output: true
>>Explanation: You can swap s[0] = 'a' and s[1] = 'b' to get "ba", which is equal to goal.

- Example 2:

>Input: s = "ab", goal = "ab"
Output: false
>>Explanation: The only letters you can swap are s[0] = 'a' and s[1] = 'b', which results in "ba" != goal.

- Example 3:

>Input: s = "aa", goal = "aa"
Output: true
>>Explanation: You can swap s[0] = 'a' and s[1] = 'a' to get "aa", which is equal to goal.

- Constraints:

>1 <= s.length, goal.length <= 2 * 104
s and goal consist of lowercase letters.

## Solution
- There are two possibilities for making a swappable. The first one is a normal swap, which requires the two characters to be in different positions but exactly the same for the two strings and the other characters the same. The second one is for the two identical characters to swap, and the whole string are the same
- To identify first, we check the length of the two strings
```cpp=
if (s.length() != goal.length()) return false;
```
- For the others, check the position. Store the first different index and then check for the second one to appear. If they can be swapped, keep checking whether the whole string for the rest is the same
```cpp=
for (int i = 0; i < s.length(); i++)
{
    if (s[i] != goal[i])
    {
        if (diff > 0) return false;
        else if (idx == -1) idx = i;
        else if (s[i] == goal[idx] && s[idx] == goal[i]) diff++;
        else return false;
    }
}
```
- After the loop, check whether the difference has occurred
```cpp=
if (diff > 0) return true;
```
- If the difference has not appeared, check the identical character among the string. Use the bit manipulation for the searching in order to save space. Mark the existence of the character and check for each iteration
```cpp=
if (idx == -1)
{
    int bit = 0;
    for (auto &i : s)
    {
        if (bit & (1 << (i - 'a'))) return true;
        else bit = bit | (1 << (i - 'a'));
    }
}
```
