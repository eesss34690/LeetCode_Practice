# 205_Isomorphic_Strings
###### tags: `leetcode` `205`
## Problem Statement
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

- Example 1:

> Input: s = "egg", t = "add"
> Output: true
- Example 2:

> Input: s = "foo", t = "bar"
> Output: false
- Example 3:

> Input: s = "paper", t = "title"
> Output: true
 
- Constraints:

> 1 <= s.length <= 5 * 10^4^
> t.length == s.length
> s and t consist of any valid ascii character.

## Solution
- To do this task, ```map``` is used in this case.
```cpp=
map<char, char> dict;
map<char, char>::iterator iter;
```
- To map the whole relation, there are 2 main constraints need to consider.
    - 1 to 1 relation
    - order is the same
- the order issue is simply resolved by the loop because it compare the pair one by one.
- To construct the 1 to 1 relation, the structure of the map is like below.

|Attribute|String|
|-|-|
|key|s[i]|
|value|t[i]|

```cpp=
dict[s[0]] = t[0];
//inside for-loop
iter= dict.find(s[i]);

// if the key is found but not the same value
if (iter!= dict.end()&& iter->second!= t[i]) 
{
    return false;
}

// if the key is not found
if (iter== dict.end())
{
    dict[s[i]]= t[i];
}
```
- This relation is ```n to 1```, to make it ```1 to 1```, when the iter is not found, we also need to check whether the value is written.
- The searching zone is from the beginning to the former of the value string, it return ```npos``` if not found.
```cpp=
if (t.rfind(t[i], i- 1)!= string::npos)
    return false;
```