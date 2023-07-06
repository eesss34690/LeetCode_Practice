# 35. Search Insert Position
###### tags: `leetcode`
## Description
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

- Example 1:

>Input: nums = [1,3,5,6], target = 5
Output: 2

- Example 2:

>Input: nums = [1,3,5,6], target = 2
Output: 1

- Example 3:

>Input: nums = [1,3,5,6], target = 7
Output: 4

- Constraints:

>$1 \leq \text{nums.length} \leq 10^4$
$-10^4 \leq nums[i] \leq 10^4$
nums contains distinct values sorted in ascending order.
$-10^4 \leq target \leq 10^4$

## Solution
- The problem can be solved simply by `BFS`
- To construct the BFS structure, use the left and right to distinguish the window.
- Find hte middle one and compare the value between the target and the middle value. The key is that it is related to the insertion, so the searching ends when the left position is not greater than the right index.
```cpp=
while(l<= r){
    if(nums[(l+ r)/ 2] == target) return (l+ r)/ 2;
    else if (nums[(l+ r)/ 2] < target) l = (l+ r)/ 2+ 1;
    else r = (l+ r)/ 2- 1;
}
```
