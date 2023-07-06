# 209. Minimum Size Subarray Sum
###### tags: `leetcode`
## Description
Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

- Example 1:

>Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
>>Explanation: The subarray [4,3] has the minimal length under the problem constraint.

- Example 2:

>Input: target = 4, nums = [1,4,4]
Output: 1

- Example 3:

>Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0

- Constraints:

>1 <= target <= 109
1 <= nums.length <= 105
1 <= nums[i] <= 104

- Follow up: If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log(n)).

## Solution
- The problem can be seen as the moving two pointers. Because the intergers are all positive, so the larger the length is for the fixed side, the bigger the sum is.
- By fixing the the value of righthand side, we accumulate the pointer if it does not satisfy the condition
- When the value is met, we minimize the lefthand side, with the previous value because we moved the right index, so the sum must be larger than the previous result, calculate for each satisfied condition and substract the total value
```cpp=
while (r < nums.size())
{
    total += nums[r];
    if (total >= target)
    {
        while (total >= target)
        {
            ans = min(ans, r - l + 1);
            total -= nums[l++];
        }
    }
    r++;
}
```
- For the final result, if the answer is not modified then the value would remains as `INT_MAX`. So we need to clarify it as well
```cpp=
return (ans == INT_MAX) ? 0 : ans;
```
