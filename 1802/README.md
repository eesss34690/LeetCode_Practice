# 1802. Maximum Value at a Given Index in a Bounded Array
###### tags: `leetcode`
## Description
You are given three positive integers: n, index, and maxSum. You want to construct an array nums (0-indexed) that satisfies the following conditions:

nums.length == n
nums[i] is a positive integer where 0 <= i < n.
abs(nums[i] - nums[i+1]) <= 1 where 0 <= i < n-1.
The sum of all the elements of nums does not exceed maxSum.
nums[index] is maximized.
Return nums[index] of the constructed array.

Note that abs(x) equals x if x >= 0, and -x otherwise.

- Example 1:

>Input: n = 4, index = 2,  maxSum = 6
Output: 2
>>Explanation: nums = [1,2,2,1] is one array that satisfies all the conditions.
There are no arrays that satisfy all the conditions and have nums[2] == 3, so 2 is the maximum nums[2].

- Example 2:

>Input: n = 6, index = 1,  maxSum = 10
Output: 3

- Constraints:

>1 <= n <= maxSum <= 109
0 <= index < n

## Solution
- The problem can be seems as `finding the maximum that can be achieved for the sum limit`.
- So, find the maximum for n and start binary search for the optimal answer
- Before the iteration, it is advised to downcast `maxSum` for the rest of the value as `0` for better computation
```cpp=
maxSum -= n;
int left = 0, right = maxSum, mid;
while (left < right) {
    mid = (left + right + 1) / 2;
    if (check(mid, index, n) <= maxSum) left = mid;
    else right = mid - 1;
}
return left + 1;
```
- For the `check` function, calculate the sum by checking the smallest value on left and right hand side
- Use the formula $1+2+...+n=\frac{n\times n + n}{2}$
- We calculate the tip twice, so substract it back when returning
```cpp=
long long check(long long a, int index, int n) {
    long long leftOffset = max(a - (long long)index, 0LL);
    long long result = (a + leftOffset) * (a - leftOffset + 1) / 2;
    long long rightOffset = max(a - (long long)((n - 1) - index), 0LL);
    result += (a + rightOffset) * (a - rightOffset + 1) / 2;
    return result - a;
}