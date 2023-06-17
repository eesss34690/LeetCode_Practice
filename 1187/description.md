# 1187. Make Array Strictly Increasing
###### tags: `leetcode`
## Description
Given two integer arrays arr1 and arr2, return the minimum number of operations (possibly zero) needed to make arr1 strictly increasing.

In one operation, you can choose two indices 0 <= i < arr1.length and 0 <= j < arr2.length and do the assignment arr1[i] = arr2[j].

If there is no way to make arr1 strictly increasing, return -1.

- Example 1:

>Input: arr1 = [1,5,3,6,7], arr2 = [1,3,2,4]
Output: 1
>>Explanation: Replace 5 with 2, then arr1 = [1, 2, 3, 6, 7].

- Example 2:

>Input: arr1 = [1,5,3,6,7], arr2 = [4,3,1]
Output: 2
>>Explanation: Replace 5 with 3 and then replace 3 with 4. arr1 = [1, 3, 4, 6, 7].

- Example 3:

>Input: arr1 = [1,5,3,6,7], arr2 = [1,6,3,3]
Output: -1
>>Explanation: You can't make arr1 strictly increasing.

- Constraints:

>1 <= arr1.length, arr2.length <= 2000
0 <= arr1[i], arr2[i] <= 10^9

## Solution
- The problem can be regarded as `dynamic programming` problem, but it is much harder than the typical one
- To clarify the memorize approach, the 2 dimensional array should represent the `subarray for substitution between subarray from arr1[i:] to arr2[j:]`. The meaning is that the dp[i][j] is the number of substitution needed for `arr1[i:]` be strictly increasing with the asset of `arr2[j:]` available
- To begin with, the constraint suggests that there are at most 2000 number of elements. Use the maximum number of array. Sort the `arr2` because we can use `upper_bound` for the problem to reduce the searching time
```cpp=
memset(dp, -1, sizeof(dp));
sort(arr2.begin(), arr2.end());
```
- To loop for the answer, use the solver function with the whole array. Because The value in the array is larger or equal to 0, let the previous one to the initial be as `-1`
- If we need to change more than the size of the original array, it is obvious that it is impossible to do so
```cpp=
int ans = solve(arr1, arr2, 0, 0, -1);
return (ans > arr1.size()) ? -1 : ans;
```
- In the solver function, find the smallest one that is `strictly larger` than the previous one. We need to search for only in the range of the subarray `arr2[j:]`
```cpp=
j = upper_bound(arr2.begin() + j, arr2.end(), prev) - arr2.begin();
```
- For the subarray `arr1[i:]`, if the combination for it with substition subarray `arr2[j:]` has already been calculated, straitly return it back
```cpp=
if (dp[i][j] != -1) return dp[i][j];
```
- It is possible that actually `arr1[i]` is smaller than `prev`, so it needs substitution. However, there is no element in `arr2[j:]` that is larger than `prev`. Consequently, it is impossible to do substitution.
```cpp=
if (arr1[i] <= prev && j == arr2.size()) return 2001;
```
- The choices for the `dp` value can be divided as the two
    - Take the substitution. If the substitution exists, the value should be the previous result (`arr1[i+1:]` and `arr2[j+1:]`) plus one
    - Do not take the result. If we can use the original result, the value should be the previous result (`arr1[i+1:]` and `arr2[j:]`)
- We can choose the smaller one as the optimal result
```cpp=
int take = (j == arr2.size()) ? 2001 : 1 + solve(arr1, arr2, i + 1, j + 1, arr2[j]);
int notake = (arr1[i] > prev) ? solve(arr1, arr2, i + 1, j, arr1[i]) : 2001;
return dp[i][j] = min(take, notake);
```