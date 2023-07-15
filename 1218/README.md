# 1218. Longest Arithmetic Subsequence of Given Difference
###### tags: `leetcode`
## Description
Given an integer array arr and an integer difference, return the length of the longest subsequence in arr which is an arithmetic sequence such that the difference between adjacent elements in the subsequence equals difference.

A subsequence is a sequence that can be derived from arr by deleting some or no elements without changing the order of the remaining elements.

- Example 1:

>Input: arr = [1,2,3,4], difference = 1
Output: 4
>>Explanation: The longest arithmetic subsequence is [1,2,3,4].

- Example 2:

>Input: arr = [1,3,5,7], difference = 1
Output: 1
>>Explanation: The longest arithmetic subsequence is any single element.

- Example 3:

>Input: arr = [1,5,7,8,5,3,4,2,1], difference = -2
Output: 4
>>Explanation: The longest arithmetic subsequence is [7,5,3,1].

- Constraints:

>1 <= arr.length <= 105
-104 <= arr[i], difference <= 104

## Solution
- Use `dynamic programming` to help solve the problem
- Because every element in the subarray is not allowed to change the position, we start from the end and let the newly added node check the existence of its next appearance
- To store the elements, we can use `unordered_map` to save the value and the index
```cpp=
unordered_map<int, int> pos;
vector<int> dp(arr.size());
```
- For the newly added element, we find the occurence of the previous iterated nodes and check the progress for that node if it has been gone through. Elsewise the length should be 1
```cpp=
for (int i = arr.size() - 1; i >= 0; i--)
{
    auto it = pos.find(arr[i] + difference);
    if (it == pos.end()) dp[i] = 1;
    else dp[i] = dp[it->second] + 1;
    pos[arr[i]] = i;
    ans = max(ans, dp[i]);
}
111
