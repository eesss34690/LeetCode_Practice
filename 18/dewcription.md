# 18_4Sum
###### tags: `leetcode` `18`
## Problem Statement
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

$0 \leq a, b, c, d < n$
a, b, c, and d are distinct.
$nums[a] + nums[b] + nums[c] + nums[d] == target$
You may return the answer in any order.

- Example 1:

> Input: $nums = [1,0,-1,0,-2,2]$, target = 0
Output: $[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]$
- Example 2:

> Input: $nums = [2,2,2,2,2]$, target = 8
Output: $[[2,2,2,2]]$
 
- Constraints:

> $1 \leq nums.length \leq 200$
$-10^9 \leq nums[i] \leq 10^9$
$-10^9 \leq target \leq 10^9$

## Solution
- This can be done by iteratively seach for the combination with target narrowing down.
- To reduce the waste of time, skip the search for duplicated number is required.
```cpp=
while (l < r && nums[l-1] == nums[l]) ++l; 
while (j+1 < n && nums[j] == nums[j+1]) ++j; 
while (i+1 < n && nums[i] == nums[i+1]) ++i; 
```
- Keep the first and the last in line, move the middle two to search all the combination with the upper and lower bound.

```cpp=!
while (l < r) {
    if (nums[l] + nums[r] == remain) {
        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
        ++l; --r;
        while (l < r && nums[l-1] == nums[l]) ++l; // Skip duplicate nums[l]
    } else if (nums[l] + nums[r] > remain) {
        --r;
    } else {
        ++l;
    }
}
```