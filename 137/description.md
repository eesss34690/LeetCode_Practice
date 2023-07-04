# 137. Single Number II
###### tags: `leetcode`
## Description
Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.

- Example 1:

>Input: nums = [2,2,3,2]
Output: 3

- Example 2:

>Input: nums = [0,1,0,1,0,1,99]
Output: 99

- Constraints:

>1 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
Each element in nums appears exactly three times except for one element which appears once.

## Solution
- To solve the problem, use two set to store the appearance of all the values, and the appearance of all the duplicated value
- For each value, check the existence in the all-val set, put it into the duplicated set as well if it presents more than once
```cpp=
unordered_set<int> mapping, duplicate;
for (auto &i : nums)
{
    auto it = mapping.find(i);
    if (it == mapping.end()) mapping.insert(i);
    else duplicate.insert(i);
}
```
- After all the process, check the two sets for the non-existence in the duplicated set
```cpp=
for (auto &i : mapping)
{
    if (duplicate.find(i) == duplicate.end()) return i;
}
```
