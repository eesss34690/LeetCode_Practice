# 567. Permutation in String
###### tags: `leetcode`
## Description
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

- Example 1:

>Input: s1 = "ab", s2 = "eidbaooo"
Output: true
>>Explanation: s2 contains one permutation of s1 ("ba").

- Example 2:

>Input: s1 = "ab", s2 = "eidboaoo"
Output: false

- Constraints:

>1 <= s1.length, s2.length <= 104
s1 and s2 consist of lowercase English letters.

## Solution
- This is a permutation of the substring. As the result, count the frequency is required
- To begin with, the s1 is the substring.Therefore, s2 length must be greater than or equal to s1
```cpp=
if (s2.length() < s1.length())
    return false;
```
- To count the frequency, cut the substring with s1 length for each combination of s2. Count the first one. Use addition and substraction can help reduce memory waste
```cpp=
for (i = 0; i < s1.length(); i++)
{
    s1Cnt[s1[i] - 'a']++;
    s1Cnt[s2[i] - 'a']--;
}
```
- Check the result and the correct one will give all 0
```cpp=
for (i = 0; i < 26; i++)
    if (s1Cnt[i] != 0) break;
if (i == 26) return true;
```
- For the other combination, cut the first bit of the last combo and add the last bit of this combo. And comparre similarity again
```cpp=
for (i = 0; i < s2.length() - s1.length(); i++)
{
    s1Cnt[s2[i] - 'a']++;
    s1Cnt[s2[i + s1.length()] - 'a']--;
    for (j = 0; j < 26; j++)
        if (s1Cnt[j] != 0) break;
    if (j == 26) return true;
}
```
