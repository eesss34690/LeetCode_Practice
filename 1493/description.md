# 1493. Longest Subarray of 1's After Deleting One Element
###### tags: `leetcode`
## Description
Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

- Example 1:

>Input: nums = [1,1,0,1]
Output: 3
>>Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.

- Example 2:

>Input: nums = [0,1,1,1,0,1,1,0,1]
Output: 5
>>Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].

- Example 3:

>Input: nums = [1,1,1]
Output: 2
>>Explanation: You must delete one element.

- Constraints:

>1 <= nums.length <= 105
nums[i] is either 0 or 1.

## Solution
- The problem can be solved by using the sliding window for the conditions
- Because we need to delete at least one element, the window for the element should be `the substring having at most one 0`. The sliding window has two pivots, and the value for each iteration is the one that must have the rightmost pivot as the iteraing pointer
- We use another index value `zero` to store the last zero index, initially we do not know the position for the zero, so it is `-1`
```cpp=
int l = 0, r = 0, zero = -1, ans = 0;
```
- For each iteration, we check the rightmost newly added pivot. If it is zero, we need to erase the substring start form the leftmost to the current zero index.
```cpp=
if (nums[r] != 1)
{
    if (zero != -1)
    {
        while (nums[l++] == 1);
    }
    zero = r;
}
```
- After the construction for the substring, check whether it is larger than the current record
```cpp=
ans = max(ans, r - l);
```
