#
###### tags: `leetcode`
## Description
Given an array of integers arr, return true if and only if it is a valid mountain array.

Recall that arr is a mountain array if and only if:

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i] 
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

- Example 1:

>Input: arr = [2,1]
Output: false

- Example 2:

>Input: arr = [3,5,5]
Output: false

- Example 3:

>Input: arr = [0,3,2,1]
Output: true

- Constraints:

>1 <= arr.length <= 104
0 <= arr[i] <= 104

## Solution
- Just check sequentially for the answer and see if it is the same as before or it has reaches the end
```cpp=
int idx = 1;
if (arr.size() == 1) return false;
while(idx < arr.size() && arr[idx] > arr[idx - 1]) idx++;
if (idx == 1 || idx == arr.size() || arr[idx] == arr[idx - 1]) return false;
```
- For decreasing, only check the end condition is required
```cpp=
while(idx < arr.size() && arr[idx] < arr[idx - 1]) idx++;
if(idx != arr.size()) return false;
return true;
```