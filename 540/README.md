# 540. Single Element in a Sorted Array
###### tags: `leetcode`
## Description
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

- Example 1:

>Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2

- Example 2:

>Input: nums = [3,3,7,7,10,11,11]
Output: 10

- Constraints:

>$1 \leq nums.length \leq 10^5$
$0 \leq nums[i] \leq 10^5$

## Solution
- The problem is a BFS. With the middle of the number, we can check the splited half which has odd number. Then do the correct judgement for the change.
```cpp=
if (nums[m] == nums[m - 1])
{
    if ((m - l) % 2 == 0)
        r = m - 2;
    else
        l = m + 1;
}
else if (nums[m] == nums[m + 1])
{
    if ((m - l) % 2 == 1)
        r = m - 1;
    else
        l = m + 2;
}
else
    return nums[m];
```
