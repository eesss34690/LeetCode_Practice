# 316_Remove_Duplicate_Letters
###### tags: `leetcode` `316`
## Problem Statement
Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

- Note: This question is the same as 1081: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/

- Example 1:

> Input: s = "bcabc"
> Output: "abc"
- Example 2:

> Input: s = "cbacdcbc"
> Output: "acdb"
 
- Constraints:

> $$1 <= s.length <= 10^4$$
> s consists of lowercase English letters.

## Solution
- To begin with, remember the last element that appear in the string

```cpp=
int i= 0;
for (; i< s.length(); i++)
{
    app[s[i]- 'a']= i;
}
```
- Use the ```set``` to remember whether the character is used. If positive, compare whether it is needed to replace its original position.
- The condition to remove the last element in the answer is like below:
    - There are elements in the answer.
    - The element to be added is smaller than the last element now.
    - The last element has other index that is bigger than the current used one.

```cpp=
if (!seen.count(c))
{
    while (!ans.empty()&& c< ans.back()&& app[ans.back()- 'a']> i)
    {
        seen.erase(ans.back());
        ans.pop_back();
    }
    ans+= c;
    seen.emplace(c);
}
```
- After the adjustment, add the element in the position.