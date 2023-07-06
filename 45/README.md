# 45_Jump_Game_II
###### tags: `leetcode` `45`
## Problem Statement
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.


- Example 1:

> Input: nums = [2,3,1,1,4]
> Output: 2
> Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
- Example 2:

> Input: nums = [2,3,0,1,4]
> Output: 2
 
- Constraints:

> 1 <= nums.length <= 3 * 10^4^
> 0 <= nums[i] <= 10^5^

## Solution
- I use ```dynamic programming``` in the first shot, despite that it work, the result is TLE.
- Therefore, I use ```greedy algorithm```instead and get a great result(100% faster).
- There are several parameters to remember
    - cnt: the num of the jump
    - prev: the last index 
    - old: the index in the middle, the current one.
    - new_: the new index to modified.
```cpp=
int cnt= 0, prev= 0, old= 0, new_= 0;
```
- Calculate until the last index is counted.
```cpp=
while(new_< nums.size()- 1)
```
- In the process, choose the biggest one from each step.
```cpp=
for(int i= prev; i<= old; i++)
{
    new_= max(new_, i+ nums[i]);
}
```
- After the calculation, add the count and shift the index.
```cpp=
cnt++;
prev= old; 
```