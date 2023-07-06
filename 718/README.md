# 718_Maximum_Length_of_Repeated_Subarray
###### tags: `leetcode` `718`
## Problem Statement
Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.

- Example 1:

> Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
Output: 3
Explanation: The repeated subarray with maximum length is [3,2,1].
- Example 2:

> Input: nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
Output: 5
 
- Constraints:

> 1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 100
## Solution
- This can be done by ```dynamic programming```, record each substring common in the last line
- By accomplish so, use a variable to record the maximum value ever and a 2-D matrix.

```cpp=
int first= nums1.size(), second= nums2.size(), temp= 0;
vector<vector<int>> dp(first, vector<int>(second));
```
- The ```dp[i][j]``` means the max common of subarray nums1[:i] and nums2[:j] including nums1[i] and nums2[j]
    - Compare nums1[i] and nums2[j], if they are the same, the answer is one plus both with one last bit removed. Also need to see wether to update the record.

```cpp=
if (nums1[i]== nums2[j])
{
    dp[i][j]= 1+ dp[i-1][j-1];
    temp= (temp< dp[i][j])? dp[i][j]: temp;
}
```
- If not, the value is just 0

```cpp=
else
{
    dp[i][j]= 0;
}
```