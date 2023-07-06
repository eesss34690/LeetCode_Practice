# 912. Sort an Array
###### tags: `leetcode`
## Description
Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.

- Example 1:

>Input: nums = [5,2,3,1]
Output: [1,2,3,5]
>>Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).

- Example 2:

>Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
>>Explanation: Note that the values of nums are not necessairly unique.

- Constraints:

>$1 \leq nums.length \leq 5 \times 10^4$
$-5 \times 10^4 \leq nums[i] \leq 5 * 10^4$

## Solution
- The sorting algorithm for time complexity `O(n lon n)` is obviously `merge sort`
- The problem can be achieved by splitting the vector and then merge them together afterward
- The easy part is to divide the array, just split in half and do the recursive
```cpp=
int dividesize = arr.size() / 2;
vector<int> merge1, merge2;
for(int i = 0; i < dividesize; i++)
    merge1.push_back(arr[i]);
for(int i = dividesize; i < arr.size(); i++)
    merge2.push_back(arr[i]);
merge1 = mergeSort(merge1);
merge2 = mergeSort(merge2);
```
- The problem may lies in merging the two vectors. Cosntruct a new vector and keeps tracking the two array, pick the smaller one in the begining and do the insertion
```cpp=
if(merge1[ptr1] < merge2[ptr2])
{
    arr[ptr3] = merge1[ptr1];
    ptr1++;
    ptr3++;
}
else
{
    arr[ptr3] = merge2[ptr2];
    ptr2++;
    ptr3++;
}
```
- When one of the array is empty, add all the rest of the other array into the result
```cpp=
if(ptr1 == merge1.size())
{
    arr[ptr3] = merge2[ptr2];
    ptr2++;
    ptr3++;
    continue;
}
if(ptr2 == merge2.size())
{
    arr[ptr3] = merge1[ptr1];
    ptr1++;
    ptr3++;
    continue;
}
```