# 438. Find All Anagrams in a String
###### tags: `leetcode`
## Description
Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

- Example 1:
>Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
>>Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

- Example 2:
>Input: s = "abab", p = "ab"
Output: [0,1,2]
>>Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".

- Constraints:

>1 <= s.length, p.length <= 3 * 104
s and p consist of lowercase English letters.

## Solution
- Similar to the permutation problem, the problem is based on the same lentgh with different combination substring
- Establish the original substring set and count the occurance in order to compare the similarity for the problem
```cpp=
for (; i < p.length(); i++)
{
    cnt[s[i] - 'a']--;
    cnt[p[i] - 'a']++;
}
for (i = 0; i < 26 && cnt[i] == 0; i++);
if (i == 26) ans.push_back(idx);
```
- For the other combination, the only difference is on the first bit of the last combo which should be deleted, and the last one of the current combo. Simply unselect the last one and add the current one and do the comparison again
```cpp=
while (idx < s.length() - p.length())
{
    i = idx, idx++;
    cnt[s[i] - 'a']++;
    cnt[s[i + p.length()] - 'a']--;
    for (i = 0; i < 26 && cnt[i] == 0; i++);
    if (i == 26) ans.push_back(idx);
    }
```
- When the comparison matches, add the first index into the answer list and finally return it as the answer
