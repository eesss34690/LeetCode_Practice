# 446 Arithmetic Slices II - Subsequence
###### tags: `leetcode` `446`
## Problem Statement
Given an integer array nums, return the number of all the arithmetic subsequences of nums.

A sequence of numbers is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, ```[1, 3, 5, 7, 9]```, ```[7, 7, 7, 7]```, and ```[3, -1, -5, -9]``` are arithmetic sequences.
For example, ```[1, 1, 2, 5, 7]``` is not an arithmetic sequence.
A subsequence of an array is a sequence that can be formed by removing some elements (possibly none) of the array.

For example, ```[2,5,10]``` is a subsequence of ```[1,2,1,2,4,1,5,10]```.
The test cases are generated so that the answer fits in 32-bit integer.
- Example 1:

> Input: nums = [2,4,6,8,10]
Output: 7
Explanation: All arithmetic subsequence slices are:
$[2,4,6]\\
[4,6,8]\\
[6,8,10]\\
[2,4,6,8]\\
[4,6,8,10]\\
[2,4,6,8,10]\\
[2,6,10]$
- Example 2:

> Input: nums = [7,7,7,7,7]
Output: 16
Explanation: Any subsequence of this array is arithmetic.
 
- Constraints:

> $1  \leq nums.length \leq 1000\\
-2^{31} \leq nums[i] \leq 2^{31} - 1$
## Solution
- Use ```map``` to store the matching number for current number ```i``` with difference ```dif```.
```cpp=
vector<unordered_map<int,int>> dp(A.size());
```
```cpp=
int dif = A[i] - A[j];
dp[i][dif] += 1;
```
- After checking the first 2 elements, check whether it is extensible for the differnece length.
```cpp=
if(dp[j].find(dif) != dp[j].end()){
    dp[i][dif] += dp[j][dif];
    res += dp[j][dif];
}
```