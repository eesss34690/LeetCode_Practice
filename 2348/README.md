# 2348. Number of Zero-Filled Subarrays
###### tags: `leetcode`
## Description
Given an integer array nums, return the number of subarrays filled with 0.

A subarray is a contiguous non-empty sequence of elements within an array.

- Example 1:

>Input: nums = [1,3,0,0,2,0,0,4]
Output: 6
>>Explanation:
There are 4 occurrences of [0] as a subarray.
There are 2 occurrences of [0,0] as a subarray.
There is no occurrence of a subarray with a size more than 2 filled with 0. Therefore, we return 6.

- Example 2:

>Input: nums = [0,0,0,2,0,0]
Output: 9
>>Explanation:
There are 5 occurrences of [0] as a subarray.
There are 3 occurrences of [0,0] as a subarray.
There is 1 occurrence of [0,0,0] as a subarray.
There is no occurrence of a subarray with a size more than 3 filled with 0. Therefore, we return 9.

- Example 3:

>Input: nums = [2,10,2019]
Output: 0
>>Explanation: There is no subarray filled with 0. Therefore, we return 0.

- Constraints:

>$1 \leq nums.length \leq 10^5$
$-10^9 \leq nums[i] \leq 10^9$

## Solution
- The problem can be regarded as the simple iteration through the consecutive 0.
- Add the prervious one for 1 if it is currently 0 and sum to the answer. Elsewise turn previous into 0
```cpp=
for (auto &i : nums)
{
    if (i == 0)
    {
        prev++;
        ans += prev;
    }
    else prev = 0;
}
```
