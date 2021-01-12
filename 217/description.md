# 217_Contain_Duplicate
###### tags: `leetcode` `217`
## Problem Statement
Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

- Example 1:

> Input: [1,2,3,1]
> Output: true
- Example 2:

> Input: [1,2,3,4]
> Output: false
- Example 3:

> Input: [1,1,1,3,3,4,3,2,4,2]
> Output: true

## Solution
- To see whether there are duplicates, simply sort the array first.
```cpp=
sort(nums.begin(), nums.end());
```
- Then see each elements whether there are the same close elements.
```cpp=
for (vector<int>::iterator i= nums.begin(); i!= nums.end()- 1; i++)
{
    if (*i== *(i+ 1))
        return 1;
}
return 0;
```
- Note that we need to make sure that there are no possibility for aray with 0 elements.
```cpp=
if (!nums.size())
    return 0;
```