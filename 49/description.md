# 49_Group_Anagrams
###### tags: `leetcode` `49`
## Problem Statement
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.


- Example 1:

> Input: strs = ["eat","tea","tan","ate","nat","bat"]
> Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
- Example 2:

> Input: strs = [""]
> Output: [[""]]
- Example 3:

> Input: strs = ["a"]
> Output: [["a"]]

- Constraints:

> $$1 <= strs.length <= 10^4$$
> $$0 <= strs[i].length <= 100$$
> strs[i] consists of lower-case English letters.

## Solution
- the original declaration is like below, the answer, and the cnt map.

```cpp=
unordered_map<string, vector<string>> anagrams;
vector<vector<string>> result;
```
- To begin with, the problem is to calculate the frequencies of occurance in each string, and shift its appearance into ordered string.
```cpp=
for(auto str : strs)
{
    int charset[26] = {0};
    string charstr = "";
    for(auto c : str)
        charset[c - 'a']++;
    for(auto v : charset)
        charstr += '#' + char(v);
    anagrams[charstr].push_back(str);
}
```
- Then add the original array part into the result.

```cpp=
for(auto it : anagrams)
    result.push_back(it.second);
return result;
```