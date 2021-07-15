# 611_Valid_Triangle_Number
###### tags: `leetcode` `791`
## Problem Statement
Given an integer array nums, return the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.

- Example 1:

> Input: nums = [2,2,3,4]
Output: 3
Explanation: Valid combinations are: 
>>2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3
- Example 2:

> Input: nums = [4,2,3,4]
Output: 4
 
- Constraints:

> 1 <= nums.length <= 1000
0 <= nums[i] <= 1000
## Solution
- To construct a triangle and count the number, use brute force takes $O(n^3)$, which is inefficient.
- By sorting the vector, there are some pattern to trace.
- With the strictest rule, if the condition satisfies, all the numbers in between can fit, too.
- Therefore, count from the last digit and adjust the ```low threshold``` and ```high threshold```. If combining the two with the fixed digit and construct a triangle, low threshold can be all the numbers between the 2 thresholds. Then change the high threshold to make condition harder.

```cpp=
if (nums[lo] + nums[hi] > nums[i])
{
    res += hi - lo;
    hi--;
}
```
- if the condition does not apply, move the lower threshold to make condition easiler.

```cpp=
else lo++;
```