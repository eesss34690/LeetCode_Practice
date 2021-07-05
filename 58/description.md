# 58_Length_of_Last_Word
###### tags: `leetcode` `58`
## Problem Statement
Given a string s consists of some words separated by spaces, return the length of the last word in the string. If the last word does not exist, return 0.

A word is a maximal substring consisting of non-space characters only.

- Example 1:

> Input: s = "Hello World"
> Output: 5
- Example 2:

> Input: s = " "
> Output: 0

- Constraints:

> 1 <= s.length <= 10^4^
> s consists of only English letters and spaces ' '.
## Solution
- In order to finish the task, need to remember the first index to begin and the last index to end.
```cpp=
// the first non-space index
int i= s.length()- 1;
for (; i> -1; i--)
{
    if (s[i]!= ' ')
        break;                
}
```
```cpp=
// the last non-zero index
int j= i;
for (; j> -1; j--)
{
    if (s[j]== ' ')
        break;
}
```