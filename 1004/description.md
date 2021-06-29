# 1004_Max_Consecutive_Ones_III
###### tags: `leetcode` `1004`
## Problem Statement
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

- Example 1:

> Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
- Example 2:

> Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
 

- Constraints:

> 1 <= nums.length <= 105
nums[i] is either 0 or 1.
0 <= k <= nums.length
## Solution
- This problem is a good case to use ```sliding window algorithm```
- The algorithm is simple to think. There are 2 constraits ```left``` for left bound, ```right``` for right bound.
- To begin with, start with no data but the first involve. 
- When we gradually move the right bound, the answer fits till the constraints fails.
- Whenm the fail happens, move the left bound to include less data till the constraints meet.
- Search finished after the right bound meets the end.
- In this scenario, there also need to record how many 0 is consume for constraint monitor and maximum gap we have now.
```cpp=
int l= 0, r= 0, consume= 0, ma= 0;
```
- When every right bound adds, check whether 0 is consumed.

```cpp=
if (!nums[r++])
    consume++;
```
- If the consume is more than the constraints, move the left bound till meets.

```cpp=
while (consume> k)
{
    if (!nums[l])
        consume--;
    l++;
}
```
- After every move, check wether the bound is bigger than history, modify it if true.

```cpp=
if (ma< r-l)
    ma= r-l;
```