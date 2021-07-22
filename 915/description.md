# 915_Partition_Array_into_Disjoint_Intervals
###### tags: `leetcode` `915`
## Problem Statement
Given an array nums, partition it into two (contiguous) subarrays left and right so that:

Every element in left is less than or equal to every element in right.
left and right are non-empty.
left has the smallest possible size.
Return the length of left after such a partitioning.  It is guaranteed that such a partitioning exists.

- Example 1:

> Input: nums = [5,0,3,8,6]
Output: 3
Explanation: left = [5,0,3], right = [8,6]
- Example 2:

> Input: nums = [1,1,1,0,6,12]
Output: 4
Explanation: left = [1,1,1,0], right = [6,12]
 
- Note:

> $2 \leq nums.length \leq 30000$
$0 \leq nums[i] \leq 10^6$
It is guaranteed there is at least one way to partition nums as described.

## Solution
- This can be searched by using standard library ```max_element``` and ```min_element```
- We can start by looking for the smallest position and split.

```cpp=
vector<int>::iterator pos= min_element(nums.begin(), nums.end());
```
- Iteratively looking for the maximum of the right and smallest of the left.

```cpp=
vector<int>::iterator max_= max_element(nums.begin(), pos);
vector<int>::iterator min_= min_element(1+ pos, nums.end());
```
- If the right one is bigger than the left one, the split index needs to shift left to the left smallest index.
- Again find the both until they are smaller or equal.

```cpp=
while(*max_> *min_)
        {
            pos= max_element(pos, min_);
            max_= (*max_< *pos)? pos: max_;
            pos= min_;
            min_= min_element(1+ pos, nums.end());
        }
```
