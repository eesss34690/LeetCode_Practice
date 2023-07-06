# 54. Spiral Matrix
###### tags: `leetcode`
## Description
Given an m x n matrix, return all elements of the matrix in spiral order.

- Example 1:
![](https://assets.leetcode.com/uploads/2020/11/13/spiral1.jpg)

>Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

- Example 2:
![](https://assets.leetcode.com/uploads/2020/11/13/spiral.jpg)

>Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

- Constraints:

>m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100

## Solution
- It is simply a simulation for the iteration process
- The figure is a matrix that iterates by gradually merge to the central point
- Use the bounding box to merge the boundary for the constraint iterator
```cpp=
int left = 0, right = cols - 1, top = 0, bottom = rows - 1;
```
- The criteria for keeping the iteration is that the left and top index should not overlap with the right and buttom
- For each of the iteration, go from left to right and top to buttom and put them into the answer. After that, add top and right by 1 since we hace finished all the index in that dimension
```cpp=
for (int i = left; i <= right; i++) result.push_back(matrix[top][i]);
top++;
for (int i = top; i <= bottom; i++) result.push_back(matrix[i][right]);
right--;
```
- For the iterating back, check whether the top value is still larger than the buttom one after the implement for the right to left direction. Also check whether the left value is still smaller than the right one after the implement for the buttom to top direction
```cpp=
if (top <= bottom) {
    for (int i = right; i >= left; i--) result.push_back(matrix[bottom][i]);
    bottom--;
}

if (left <= right) {
    for (int i = bottom; i >= top; i--) result.push_back(matrix[i][left]);
    left++;
}
```