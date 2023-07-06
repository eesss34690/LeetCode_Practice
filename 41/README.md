# 41_First_Missing_Positive
###### tags: `leetcode` `41`
## Problem Statement
Given an unsorted integer array nums, find the smallest missing positive integer.

>Follow up: Could you implement an algorithm that runs in O(n) time and uses constant extra space.?

- Example 1:
>Input: nums = [1,2,0]
>Output: 3

- Example 2:
> Input: nums = [3,4,-1,1]
> Output: 2

- Example 3:

> Input: nums = [7,8,9,11,12]
> Output: 1
- Constraints:
> 0 <= nums.length <= 300
> -2^31^ <= nums[i] <= 2^31^ - 1
## Solution
- If there is no array, return 0
```cpp=
if (!nums.size())
{
    return 1;
}
```
- Elsewhile, since we only have ```300``` testcases, the possibilities for the output range only from ```1``` to ```300```. Therefore, construct a array of length 300.
```cpp=
bool use[300] = {0};
```
- Runa for loop to see wherther the number is in the possibility range, if positive, turn ```false``` to ```true```.
```cpp=
for (vector<int>::iterator i= nums.begin(); i!= nums.end(); i++)
{
    if (*i> 0&& *i< 301)
    {
        use[*i- 1]= 1;
    } 
}
```
- Run a for loop to search from the smallest ```1``` to the biggest ```300``` to see whether is present or not, and then return the value.
```cpp=
for (int i= 0; i< 300; i++)
{
    if (use[i]== 0)
    {
        return i+ 1;
    }
}
return 301;
```