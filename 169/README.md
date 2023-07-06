# 169_Majority_Element
###### tags: `leetcode` `169`
## Problem Statement
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

- Example 1:

> Input: nums = [3,2,3]
> Output: 3
- Example 2:

> Input: nums = [2,2,1,1,1,2,2]
> Output: 2
 
- Constraints:

> n == nums.length
> 1 <= n <= 5 * 10^4^
> -2^31^ <= nums[i] <= 2^31^ - 1

## Solution
- By sorting, the majority element must be the middle one
```cpp=
sort(nums.begin(), nums.end());
return nums[nums.size()/ 2];
```