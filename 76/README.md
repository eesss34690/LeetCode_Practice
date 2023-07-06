# 76_Minimum_Window_Substring
###### tags: `leetcode` `68`
## Problem Statement
Given two strings s and t, return the minimum window in s which will contain all the characters in t. If there is no such window in s that covers all characters in t, return the empty string "".

Note that If there is such a window, it is guaranteed that there will always be only one unique minimum window in s.

- Example 1:

> Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
- Example 2:

> Input: s = "a", t = "a"
Output: "a"

- Constraints:

> 1 <= s.length, t.length <= 105
s and t consist of English letters.

- Follow up: Could you find an algorithm that runs in O(n) time?

## Solution
- The fastest way to solve is ```sliding windows```.
- First calculate the frequencies for ech element to appear in the test data.

```cpp=
for(auto& ch:t)
    c[getI(ch)]++;
int getI(char ch) {
    return ch-65-((ch>=97)?6:0);
}
```
- Then construct the ```left``` and ```right``` windows for each one and divide each one appears in ```s```.
- Then cut off the redundant left data.
- If the final count is smaller than the former record, change it.

```cpp=
for(int l=0,r=0,total=t.length();s[r];++r){
    if(--c[getI(s[r])]>=0)
        total--;
    while(l<=r && c[getI(s[l])]<0)
        c[getI(s[l++])]++;
    if(total==0 && ans>r-l+1)
        ans=r-l+1,ansl=l;
}
```
- Return the substring as the result.

```cpp=
return (ans==INT_MAX)?"":s.substr(ansl,ans);
```