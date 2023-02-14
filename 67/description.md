# 67. Add Binary
###### tags: `leetcode`
## Description
Given two binary strings a and b, return their sum as a binary string.

- Example 1:

>Input: a = "11", b = "1"
Output: "100"

- Example 2:

>Input: a = "1010", b = "1011"
Output: "10101"

- Constraints:

>1 $\leq$ a.length, b.length $\leq 10^4$
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.

## Solution
- Iteratively go through the string adding for each bit. First swap the number to make the first one possess greater or equal number of digits
```cpp=
if (a.length() < b.length())
{
    string temp = b;
    b = a;
    a = temp;
}
```
- When iterating to the bits, add them into the carry and modify the value. Make sure both contains the correct digit
```cpp=
while (aLen >= 0)
{
    carry += (bLen >= 0) ? (a[aLen] - '0') + (b[bLen--] - '0') : a[aLen] - '0';
    a[aLen--] = (carry % 2) + '0';
    carry /= 2;
}
- When returning, check the carry bit if it needs addition
```cpp=
return (carry == 1) ? '1' + a : a;
```
