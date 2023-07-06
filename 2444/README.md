# 2444. Count Subarrays With Fixed Bounds
###### tags: `leetcode`
## Description
You are given an integer array nums and two integers `minK` and `maxK`.

A fixed-bound subarray of nums is a subarray that satisfies the following conditions:

- The minimum value in the subarray is equal to minK.
- The maximum value in the subarray is equal to maxK.
Return the number of fixed-bound subarrays.

A subarray is a contiguous part of an array.

- Example 1:

>Input: nums = [1,3,5,2,7,5], minK = 1, maxK = 5
Output: 2
>>Explanation: The fixed-bound subarrays are [1,3,5] and [1,3,5,2].

- Example 2:

>Input: nums = [1,1,1,1], minK = 1, maxK = 1
Output: 10
>>Explanation: Every subarray of nums is a fixed-bound subarray. There are 10 possible subarrays.

- Constraints:

>$2 \leq nums.length \leq 10^5$
$1 \leq nums[i], minK, maxK \leq 10^6$

## Solution
- This is a dynamic programming problem. The intuitive solving idea is to use let `dp[i]` as the **number of subarray that contains $nums[i]$**
- In order to achieve this, keep an eye on the max and min of current subarray set, for the first one the construct looks that below
```cpp=
// minSet, maxSet: the current subarray min and max index
vector<int> minSet, maxSet;
// dp: as described above, last: the overall answer, frontLine: the first one of the subarray
long long int dp[nums.size()], frontLine = 0, last;
// min and max are the same
if (minK == maxK && nums[0] == minK)
{
    dp[0] = 1;
    minSet.push_back(0);
}
else
{
    dp[0] = 0;
    if (nums[0] == minK)
        minSet.push_back(0);
    else if (nums[0] == maxK)
        maxSet.push_back(0);
    else if (nums[0] < minK || nums[0] > maxK)
        frontLine++;
}
```
- For each of the other numbers, possibilities are...
1. In the gap: the added combination is the last one of the array
```cpp=
if (nums[i] > minK && nums[i] < maxK)
    dp[i] = dp[i - 1];
```
2. Out of the gap: recount the frontLine, and clean out the current subarray
```cpp=
else if (nums[i] < minK || nums[i] > maxK)
{
    frontLine = i + 1;
    minSet.clear();
    maxSet.clear();
}
```
3. It is `minK`: may be possible for the minK == maxK. give it an exception because it only counts to `minSet`. For the normal case, it will add the value from the begining of the array till the last maxSet value
```cpp=
else if (nums[i] == minK)
{
    if (minK == maxK)
    {
        if (minSet.empty())
            dp[i] = 1;
        else
            dp[i] = i - minSet[0] + 1;
    }
    else if (!maxSet.empty())
        dp[i] = maxSet.back() - frontLine + 1;
    else dp[i] = 0;
    minSet.push_back(i);
}
```
4. It is `maxK`: add the value from the begining of the array till the last minSet value
```cpp=
else
{
    if (!minSet.empty())
        dp[i] = minSet.back() - frontLine + 1;
    else dp[i] = 0;
    maxSet.push_back(i);
}
```
- Remember to add the `dp[i]` into the final answer