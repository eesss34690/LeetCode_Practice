# 1539. Kth Missing Positive Number
###### tags: `leetcode`
## Description
Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

Return the kth positive integer that is missing from this array.

- Example 1:

>Input: arr = [2,3,4,7,11], k = 5
Output: 9
>>Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.

- Example 2:

>Input: arr = [1,2,3,4], k = 2
Output: 6
>>Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.

- Constraints:

>$1 \leq arr.length \leq 1000\\$
$1 \leq arr[i] \leq 1000\\$
$1 \leq k \leq 1000\\$
arr[i] < arr[j] for $1 \leq i < j \leq arr.length$

## Solution
- Simply tell the cases for the out of bound one and in the middle one.
- If it is out of bound, straightly return the value
```cpp=
if (k < arr[0])
    return k;
if (k > arr.back() - arr.size())
    return k + arr.size();
```
- If it is in the middle, check the middle number and minus it until it is on the edge of the last case. Thrn return it.
```cpp=
while (true)
{
    temp = arr[i + 1] - arr[i] - 1;
    if (k > temp)
        k -= temp;
    else break;
    i++;
}
return arr[i] + k;
```
