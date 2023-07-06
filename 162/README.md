# 162_Find_Peak_Element
###### tags: `leetcode` `162`
## Problem Statement
A peak element is an element that is strictly greater than its neighbors.

Given an integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞.

You must write an algorithm that runs in O(log n) time.

- Example 1:

> Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
- Example 2:

> Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
 
- Constraints:

> 1 <= nums.length <= 1000
-231 <= nums[i] <= 231 - 1
nums[i] != nums[i + 1] for all valid i.
## Solution
- Acctually, the simplest way to accomplish that is to use ```max_element```

```cpp=
return max_element(nums.begin(), nums.end())- nums.begin();
```
- To be more programmatic, use ```binary search``` is a better approach to get the time complexity to **O(log N)**
- Search starts from the first and the end. If the value of the middle is bigger than the one right after middle, change the right threshold to the middle to zoom in. Else change the left threshold to the one next to middle.

```cpp=
while(l< r)
{
    mid= (l+ r)/ 2;
    if (nums[mid]> nums[mid+ 1])
        r= mid;
    else
        l= mid+ 1;
}
```