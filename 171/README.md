# 171_Excel_Sheet_Column_Number
###### tags: `leetcode` `171`
## Problem Statement
Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...
- Example 1:

> Input: "A"
Output: 1
- Example 2:

> Input: "AB"
Output: 28
- Example 3:

> Input: "ZY"
Output: 701
 
- Constraints:

> 1 <= s.length <= 7
s consists only of uppercase English letters.
s is between "A" and "FXSHRXW".

## Solution
- Reverse the string to add in the correct order.

```cpp=
reverse(begin(s), end(s));
```
- Just let every element has 26 carry and add the number one by one.

```cpp=
for (auto &i: s)
{
    ans+= cnt* (i- 'A'+ 1);
    cnt*= 26;
}
```
