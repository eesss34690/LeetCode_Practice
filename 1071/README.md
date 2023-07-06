# 1071. Greatest Common Divisor of Strings
###### tags: `leetcode`
## Description
For two strings s and t, we say "t divides s" if and only if `s = t + ... + t` (i.e., t is concatenated with itself one or more times).

Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.

- Example 1:
> Input: str1 = "ABCABC", str2 = "ABC"
Output: "ABC"

- Example 2:
> Input: str1 = "ABABAB", str2 = "ABAB"
Output: "AB"

- Example 3:
> Input: str1 = "LEET", str2 = "CODE"
Output: ""

- Constraints:

> 1 <= str1.length, str2.length <= 1000
str1 and str2 consist of English uppercase letters.

## Solution
- The problem can be simplified as finding the longest prefix of the string that meets the standard
- To make it quicker, let get the gcd of the two strings and size down the substring while not match
```cpp=
int commonmax = gcd(str1.length(), str2.length());
if (commonmax == 0)
    return "";
if (str1.length() < str2.length())
{
    string temp = str1;
    str1 = str2;
    str2 = temp;
}
```
- Check both the strings if it is the multiple of the substring and return true while meeting the string, substract the amount when the substring does not match.
```cpp=
while (sub == str2.substr(idx1, commonmax))
    idx1 += commonmax;
if (idx1 >= str2.length())
{
    idx1 = 0;
    while (sub == str1.substr(idx1, commonmax))
        idx1 += commonmax;
    if (idx1 >= str1.length())
        return sub;
}
commonmax--;
```
