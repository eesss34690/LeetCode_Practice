# 1799. Maximize Score After N Operations
###### tags: `leetcode`
## Description
You are given nums, an array of positive integers of size 2 * n. You must perform n operations on this array.

In the ith operation (1-indexed), you will:

Choose two elements, x and y.
Receive a score of i * gcd(x, y).
Remove x and y from nums.
Return the maximum score you can receive after performing n operations.

The function gcd(x, y) is the greatest common divisor of x and y.

- Example 1:

>Input: nums = [1,2]
Output: 1
>>Explanation: The optimal choice of operations is:
(1 * gcd(1, 2)) = 1

- Example 2:

>Input: nums = [3,4,6,8]
Output: 11
>>Explanation: The optimal choice of operations is:
(1 * gcd(3, 6)) + (2 * gcd(4, 8)) = 3 + 8 = 11

- Example 3:

>Input: nums = [1,2,3,4,5,6]
Output: 14
>>Explanation: The optimal choice of operations is:
(1 * gcd(1, 5)) + (2 * gcd(2, 4)) + (3 * gcd(3, 6)) = 1 + 4 + 9 = 14

- Constraints:

>1 <= n <= 7
nums.length == 2 * n
1 <= nums[i] <= 106

## Solution
- Originally I though it is a simple greedy and it can be done by iteration of searching. But the result is not acceptable because there may be possibilities of identical gcd and the diffrerent paths need comparison. As the result, it should be done by dfs
- But using plain dfs does not work and it would result in tle. Consequently, use a giant dynamic programming mapping to solve the problem
- The masking technique is that the seven pairs get one of the bit individually. Set the used bit as 1 and check whether the bit is set previously to save the space and time
- As for the dp table, the maximum value is the current amount operation index times the gcd of current pair with the score for the rest of the value with the mask hidden
```cpp=
int new_mask = (1 << j) + (1 << k);
    if ((mask & new_mask) == 0)
        dp[i][mask] = max(dp[i][mask], i * __gcd(n[j], n[k]) + maxScore(n, i + 1, mask + new_mask));
```