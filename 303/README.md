# 303_Range_Sum_Query-Immutable
###### tags: `leetcode` `546`
## Problem Statement
Given an integer array nums, handle multiple queries of the following type:

Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
Implement the NumArray class:

NumArray(int[] nums) Initializes the object with the integer array nums.
int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).
 
- Example 1:

> Input
["NumArray", "sumRange", "sumRange", "sumRange"]
[[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
Output
[null, 1, -1, -3]

>Explanation
> NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
numArray.sumRange(0, 2); // return (-2) + 0 + 3 = 1
numArray.sumRange(2, 5); // return 3 + (-5) + 2 + (-1) = -1
numArray.sumRange(0, 5); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3
 
- Constraints:

> $1 \leq nums.length \leq 10^4\\
-10^5 \leq nums[i] \leq 10^5\\
0 \leq left \leq right < nums.length$
At most $10^4$ calls will be made to sumRange
## Solution
- Do it in in-place is the fastest when it comes to multiple calls for summation
```cpp=
num= nums;
for (int i= 1; i< num.size(); i++)
{
    num[i]+= num[i- 1];
}
```
- After that, if the left is the first one, straightly send the right sum, else needs to substract back.
```cpp=
return (left== 0)? num[right]: num[right]- num[left- 1];
```