# 80_Remove_Duplicates_From_Sorted_Array_II
###### tags: `leetcode` `80`
## Problem Statement
Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.

Do not allocate extra space for another array; you must do this by modifying the input array in-place with O(1) extra memory.

:::success
- Clarification:

Confused why the returned value is an integer, but your answer is an array?

Note that the input array is passed in by reference, which means a modification to the input array will be known to the caller.

Internally you can think of this:

```!
// nums is passed in by reference. (i.e., without making a copy)
int len = removeDuplicates(nums);

// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len elements.
for (int i = 0; i < len; i++) {
    print(nums[i]);
}
```
:::

 

- Example 1:

> Input: nums = [1,1,1,2,2,3]
> Output: 5, nums = [1,1,2,2,3]
> Explanation: Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively. It doesn't matter what you leave beyond the returned length.

- Example 2:

> Input: nums = [0,0,1,1,1,1,2,3,3]
> Output: 7, nums = [0,0,1,1,2,3,3]
> Explanation: Your function should return length = 7, with the first seven elements of nums being modified to 0, 0, 1, 1, 2, 3 and 3 respectively. It doesn't matter what values are set beyond the returned length.
 

- Constraints:

> 1 <= nums.length <= 3 * 104
> -104 <= nums[i] <= 104
> nums is sorted in ascending order.

## Solution
- To begin with, only the array size with size bigger than 2 need to do the constraints.
```cpp=
if (nums.size()> 2){

}
```
- Define a ```boolean``` to do the classification of the different comparison in order to eliminate the process.
    - If there are 3 duplicates in the array, the latter comparisons only need to see 2 char..
    - Else, need to compare 3 char..
```cpp=
for (vector<int>::iterator i = nums.begin(); nums.size()> 2&& i!= nums.end()-1; i++)
{
    if (!s)
    {           
        if ((i!= nums.end()-2)&& ((*i == *(i+ 1))&& (*i== *(i+ 2))))
        {
            nums.erase(i);
            s = 1;
        }                
    }
    else
    {
        if (*i ==*(i+1))
        {
            nums.erase(i);
            i--;
        }
        else
        {
            s= 0;
        }
    }
}
```
- The rest is to print out the array, skip there.