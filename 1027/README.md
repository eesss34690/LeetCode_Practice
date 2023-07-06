## Description
Given an array nums of integers, return the length of the longest arithmetic subsequence in nums.

Note that:

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
A sequence seq is arithmetic if seq[i + 1] - seq[i] are all the same value (for 0 <= i < seq.length - 1).

- Example 1:

>Input: nums = [3,6,9,12]
Output: 4
>>Explanation:  The whole array is an arithmetic sequence with steps of length = 3.

- Example 2:

>Input: nums = [9,4,7,2,10]
Output: 3
>>Explanation:  The longest arithmetic subsequence is [4,7,10].

- Example 3:

>Input: nums = [20,1,15,3,10,5,8]
Output: 4
>>Explanation:  The longest arithmetic subsequence is [20,15,10,5].

- Constraints:

>2 <= nums.length <= 1000
0 <= nums[i] <= 500

## Solution
- Intuitively we may think about dynamic programming, but the main problem is `how to dfine the stored attribute`?
- The problem is about arithmetic sequence, so the difference between different gap is the same. The core spirit is that the length should be the subsequence plus one if we add one more in the back of the subsequence
- It makes the problem easiler. We can define the problem to be the `start from ith index and the difference is j`. Because of the constraint given, we can initialize the problem to be as below
```cpp=
vector<vector<int>> dp(nums.size(), vector<int>(1002));
```
- For each of the pair of sequence, we calculate the difference and check the difference value of the starting point. The value should be the starting point value plus one
- As for the `500`, it is because of negative value and the boundary, so we add the value to avoid smaller than 0 index
```cpp=
diff = nums[j] - nums[i] + 500;
dp[j][diff] = max(2, dp[i][diff] + 1);
```
- The answer should be the maximum of all the dp value
```cpp=
ans = max(ans, dp[j][diff]);
```