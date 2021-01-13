# 55_Jump_Game
###### tags: `leetcode` `55`
## Problem Statement
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

- Example 1:

> Input: nums = [2,3,1,1,4]
> Output: true
> Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

- Example 2:

> Input: nums = [3,2,1,0,4]
> Output: false
> Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 
- Constraints:

> 1 <= nums.length <= 3 * 10^4^
> 0 <= nums[i] <= 10^5^

## Solution
- If step is at the threshold, then it can jump to the last step.
```cpp=
if(i==nums.size()-1) return true;
```
- The main issue is to see whether the ```0``` step can be avoided.
- To do that, just need to make sure when stepping back, there are others that can jump out of the hole.
- To leave, the distance is between the position and the hole, if the step count is bigger, then it can leave.
```cpp=
if(nums[i]==0){
    int j;
    for(j=i;j>=0;j--) if(nums[j]>i-j) break;
    if(j<0) return false;
}
```