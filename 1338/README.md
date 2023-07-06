# 378_Kth_Smallest_Element_in_a_Sorted_Matrix
###### tags: `leetcode` `378`
## Problem Statement
Given an n x n matrix where each of the rows and columns are sorted in ascending order, return the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

- Example 1:

> Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13
- Example 2:

> Input: matrix = [[-5]], k = 1
Output: -5
 
- Constraints:

> n == matrix.length
n == matrix[i].length
1 <= n <= 300
-109 <= matrix[i][j] <= 109
All the rows and columns of matrix are guaranteed to be sorted in non-decreasing order.
1 <= k <= n^2

## Solution
- This problem needs comparison up and up by halving the size of observation scope.
- The most efficient way to do that is ```binary search```.
- The scope is from the smallest value to the biggest value.
- Since the constraits show that the value s are sorted in ```non-decreasing``` order, we can know th e smallest and biggest value.

```cpp=
int lo = matrix[0][0], hi = matrix[n-1][n-1] + 1, mid, count, tmp;
```
- See how many numbers in the matrix are smaller than the mid value.
    - Because the matrix is in order, start from the first row and see which column has the value smaller than mid, the next row can start the search from the value, not from the last column.

```cpp=
for (int i = 0; i < n; i++) {
    while (tmp >= 0 && matrix[i][tmp] > mid) tmp--;
    count += tmp + 1;
}
```
- If the nember is to few, change the lower bound, else change the upper bound.

```cpp=
if (count < k) lo = mid + 1;
else hi = mid;
```