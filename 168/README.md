# 168_Excel_Sheet_Column_Title
###### tags: `leetcode` `168`
## Problem Statement
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

- For example:
```
    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
    ...
```
- Example 1:

> Input: 1
> Output: "A"
- Example 2:

> Input: 28
> Output: "AB"
- Example 3:

> Input: 701
> Output: "ZY"

## Solution
- It is like the method of ```Euclidean algorithm```, remember the value of the remains and divide the number in a circle.

```cpp=
while (n)
{
    n-= 1;
    ans+= n% 26+ 'A';
    n/= 26;
}
```
- After all the characters in place, reverse the string to get the answer.

```cpp=
reverse(begin(ans), end(ans));
return ans;
```