# 1572. Matrix Diagonal Sum
###### tags: `leetcode`
## Description
Given a square matrix `mat`, return the sum of the matrix diagonals.

Only include the sum of all the elements on the primary diagonal and all the elements on the secondary diagonal that are not part of the primary diagonal.

- Example 1:
![](https://assets.leetcode.com/uploads/2020/08/14/sample_1911.png)

>Input: mat = [[1,2,3],
              [4,5,6],
              [7,8,9]]
Output: 25
>>Explanation: Diagonals sum: 1 + 5 + 9 + 3 + 7 = 25
Notice that element mat[1][1] = 5 is counted only once.

- Example 2:

>Input: mat = [[1,1,1,1],
              [1,1,1,1],
              [1,1,1,1],
              [1,1,1,1]]
Output: 8

- Example 3:

>Input: mat = [[5]]
Output: 5

- Constraints:

>n == mat.length == mat[i].length
1 <= n <= 100
1 <= mat[i][j] <= 100

## Solution
- Just add each of the index that satisfy the condition
- The middle one should be added only once if the length is odd.
```cpp=
int len = mat.size() / 2, ans = (mat.size() % 2 == 1) ? mat[len][len] : 0, whole = mat.size() - 1;
```
- The iteration should only goes till half of the value
```cpp=
for (int i = 0; i < len; i++)
    ans += mat[i][i] + mat[whole - i][i] + mat[i][whole - i] + mat[whole - i][whole - i];
```
