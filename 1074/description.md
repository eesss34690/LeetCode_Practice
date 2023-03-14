# 1074. Number of Submatrices That Sum to Target
###### tags: `leetcode`
## Description
Given a `matrix` and a `target`, return the number of non-empty submatrices that sum to target.

A submatrix `x1, y1, x2, y2` is the set of all cells `matrix[x][y]` with $x1 \leq x \leq x2$ and $y1 \leq y \leq y2$.

Two submatrices `(x1, y1, x2, y2)` and `(x1', y1', x2', y2')` are different if they have some coordinate that is different: for example, if `x1 != x1'`.

- Example 1:
![](https://assets.leetcode.com/uploads/2020/09/02/mate1.jpg)

>Input: matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
Output: 4
>>Explanation: The four 1x1 submatrices that only contain 0.

- Example 2:

>Input: matrix = [[1,-1],[-1,1]], target = 0
Output: 5
>>Explanation: The two 1x2 submatrices, plus the two 2x1 submatrices, plus the 2x2 submatrix.

- Example 3:

>Input: matrix = [[904]], target = 0
Output: 0

- Constraints:

>$1 \leq matrix.length \leq 100\\$
$1 \leq matrix[0].length \leq 100\\$
$-1000 \leq matrix[i] \leq 1000\\$
$-10^8 \leq target \leq 10^8$

## Solution
- Use the 2D summation matrix to store the summation from the ever first corner to the current index. In order to eliminate the calculation, add one more row and column as 0 for the prestarter
```cpp=
int row = matrix.size() + 1, col = matrix[0].size() + 1;
vector<vector<int>> summation(row, vector<int>(col));
for (int i = 0; i < row; i++)
    summation[i][0] = 0;
for (int i = 1; i < col; i++)
    summation[0][i] = 0;
for (int i = 1; i < row; i++)
{
    for (int j = 1; j < col; j++)
        summation[i][j] = summation[i][j - 1] + matrix[i - 1][j - 1] + summation[i - 1][j] - summation[i - 1][j - 1];
}
```
- To get the answer, go from two dimensional sliding window and calculate the summation for the current window size
```cpp=
int ans = 0;
for (int lx = 1; lx < row; lx++)
{
    for (int rx = lx; rx < row; rx++)
    {
        for (int ly = 1; ly < col; ly++)
        {
            for (int ry = ly; ry < col; ry++)
            {
                if (summation[rx][ry] + summation[lx - 1][ly - 1] - summation[rx][ly - 1] - summation[lx - 1][ry] == target)
                    ans++;
            }
        }
    }
}
return ans;
```
