# 189_Rotate_Array
###### tags: `leetcode` `189`
## Problem Statement
Given an array, rotate the array to the right by k steps, where k is non-negative.
:::success
Follow up:

Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
Could you do it in-place with O(1) extra space?
:::

- Example 1:

> Input: nums = [1,2,3,4,5,6,7], k = 3
> Output: [5,6,7,1,2,3,4]
> Explanation:
> rotate 1 steps to the right: [7,1,2,3,4,5,6]
> rotate 2 steps to the right: [6,7,1,2,3,4,5]
> rotate 3 steps to the right: [5,6,7,1,2,3,4]

- Example 2:

> Input: nums = [-1,-100,3,99], k = 2
> Output: [3,99,-1,-100]
> Explanation: 
> rotate 1 steps to the right: [99,-1,-100,3]
> rotate 2 steps to the right: [3,99,-1,-100]
 

- Constraints:

> 1 <= nums.length <= 2 * 10^4^
> -2^31^ <= nums[i] <= 2^31^ - 1
> 0 <= k <= 10^5^

## Solution
- I use another vector to store the true one
- Because the more rotations than the total length, it is equal to the original array, let k becomes the rest from division of length
```cpp=
k= k% nums.size();
```
- Assign a new vector to be divided 2 parts from the original array and then assign it back.
```cpp=
vector<int> a;
a.assign(nums.begin()+ (nums.size()- k), nums.end());
a.insert(a.end(), nums.begin(), nums.begin()+ (nums.size()- k));
nums= a; 
```
- The rest is to print the array, skip there.