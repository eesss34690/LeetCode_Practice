# 242_Valid_Anagram
###### tags: `leetcode` `242`
## Problem Statement
Given two strings s and t , write a function to determine if t is an anagram of s.

- Example 1:

> Input: s = "anagram", t = "nagaram"
> Output: true
- Example 2:

> Input: s = "rat", t = "car"
> Output: false
- Note:
> You may assume the string contains only lowercase alphabets.

## Solution
- If you use ```find``` and then erase the character found in the string, it is pretty slow.
- The faster way is to calculate the frequencies of each character, and compare the vector to see the result.
- Note that it is impossible to be anagram if the 2 strings have different length.
```cpp=
if (s.size()!= t.size())
    return false;
```

```cpp=
for (int i= 0; i< s.size(); i++)
{
    cnt_s[s[i]- 'a']++;
    cnt_t[t[i]- 'a']++;
}
if (cnt_s== cnt_t)
    return true;
return false;
```