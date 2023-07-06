# 387_First_Unique_Character_in_a_String
###### tags: `leetcode` `387`
## Problem Statement
Given a string, find the first non-repeating character in it and return its index. If it doesn't exist, return -1.

- Examples:

> s = "leetcode"
> return 0.

> s = "loveleetcode"
> return 2.
 

- Note: You may assume the string contains only lowercase English letters.
## Solution
- Because there are only lower-case alpha need to consider, construct an array for 26 characters and conculate the frequencies for each one.
```cpp=
int alpha[26]= {0};
for (int i= 0; i< s.length(); i++)
{
    alpha[s[i]- 'a']++;
}
```
- After the construction, count from the begining of the array and see whether the frequency is 1, if positive, return this index.
```cpp=
for (int i= 0; i< s.length(); i++)
{
    if(alpha[s[i]- 'a']== 1)
        return i;
}
return -1;
```