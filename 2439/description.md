# 2439. Minimize Maximum of Array
###### tags: `leetcode`
## Description
You are given a 0-indexed array nums comprising of n non-negative integers.

In one operation, you must:

Choose an integer i such that 1 <= i < n and nums[i] > 0.
Decrease nums[i] by 1.
Increase nums[i - 1] by 1.
Return the minimum possible value of the maximum integer of nums after performing any number of operations.

- Example 1:

>Input: nums = [3,7,1,6]
Output: 5
>>Explanation:
One set of optimal operations is as follows:
>>1. Choose i = 1, and nums becomes [4,6,1,6].
>>2. Choose i = 3, and nums becomes [4,6,2,5].
>>3. Choose i = 1, and nums becomes [5,5,2,5].
The maximum integer of nums is 5. It can be shown that the maximum number cannot be less than 5.
Therefore, we return 5.

- Example 2:

>Input: nums = [10,1]
Output: 10
>>Explanation:
It is optimal to leave nums as is, and since 10 is the maximum value, we return 10.

- Constraints:

>n == nums.length
$2 \leq n \leq 10^5$
$0 \leq nums[i] \leq 10^9$

## Solution
- The problem can be seen as the adjustment of maximum average iteration
- Because the changing of the sequence decrease one of the element and increase the other element, the final average is the same. Consequently, the maximum average for one subarray is the normal average plus the possible iteration of changing sequence.
- For the first element, it is impossible to flip the value. So the average is just the value itself. For the second one, it can flip one and the result may be plus one time. The others are as follow.
- For each iteration, the maximum of the average should be updated, and the final maximum one would be the answer
```cpp=
for (int index = 0; index < nums.size(); ++index) {
    sum += nums[index];
    result = max(result, (sum + index) / (index + 1));
}
```