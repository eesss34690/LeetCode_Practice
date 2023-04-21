# 413. Arithmetic Slices
###### tags: `leetcode`
## Description
An integer array is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic sequences.
Given an integer array nums, return the number of arithmetic subarrays of nums.

A subarray is a contiguous subsequence of the array.

- Example 1:

>Input: nums = [1,2,3,4]
Output: 3
>>Explanation: We have 3 arithmetic slices in nums: [1, 2, 3], [2, 3, 4] and [1,2,3,4] itself.

- Example 2:

>Input: nums = [1]
Output: 0

- Constraints:

>$1 \leq nums.length \leq 5000$
$-1000 \leq nums[i] \leq 1000$

## Solution
- Just keep the record for the last difference because the slice is defined as the subsequent subarray.
- When the new differece is just like the last one, add the count. After the difference sequence ends, calculate for the length by `(length - 3) * (length - 2) / 2` and update the length. (The length is cut by 3 in default because we do not need to keep the value for the length of 2 and 1)
```cpp=
for (int i = 2; i < nums.size(); i++)
{
    if (nums[i] - nums[i - 1] == diff) subcnt++;
    else
    {
        ans += subcnt * (subcnt + 1) / 2;
        subcnt = 0;
        diff = nums[i] - nums[i - 1];
    }
}
```
