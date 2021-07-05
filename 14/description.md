# 14_Longest_Common_Prefix
###### tags: `leetcode` `14`
## Problem Statement
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

- Example 1:

> Input: strs = ["flower","flow","flight"]
> Output: "fl"
- Example 2:

> Input: strs = ["dog","racecar","car"]
> Output: ""
> Explanation: There is no common prefix among the input strings.
 

- Constraints:

> 0 <= strs.length <= 200
> 0 <= strs[i].length <= 200
> strs[i] consists of only lower-case English letters.

## Solution
- Use control variable ```f``` to see whether comparison is still needed.
- This question only need to compare the front elements. Therefore, see whether it fits for every string in the same position.
```cpp=
bool f = !(strs.size() > 0);
while (!f){    
    if (strs[0].size() <= j)
    {
        j++;
        break;
    }
    for (int i = 1; i < strs.size(); i ++){
        if (strs[i].size() <= j || strs[i][j] != strs[0][j])
        {f = true; break;}
    }
    j ++;
}
```
- Return the element that fits.
```cpp=
return j-1 >= 0 ? strs[0].substr(0, j-1) : "";
```