# 1020. Number of Enclaves
###### tags: `leetcode`
## Description
You are given an `m x n` binary matrix grid, where `0` represents a sea cell and `1` represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

- Example 1:
![](https://assets.leetcode.com/uploads/2021/02/18/enclaves1.jpg)

>Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
>>Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.

- Example 2:
![](https://assets.leetcode.com/uploads/2021/02/18/enclaves2.jpg)

>Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
Output: 0
>>Explanation: All 1s are either on the boundary or can reach the boundary.

- Constraints:

>m == grid.length
n == grid[i].length
$1 \leq m, n \leq 500$
grid[i][j] is either 0 or 1.

## Solution
- The problem is a dfs to all the land and check the boundary condition.
- When iterating through all the nodes, check the land part and expand it. If it touches the edge, return false for the boolean
```cpp=
int dfs(int i, int j, vector<vector<int>>& grid, bool& inside) {
    int ans = 1;
    grid[i][j] = -1;
    if (i == 0) inside = false;
    else if (grid[i - 1][j] == 1) ans += dfs(i - 1, j, grid, inside);
    if (i == h) inside = false;
    else if (grid[i + 1][j] == 1) ans += dfs(i + 1, j, grid, inside);
    if (j == 0) inside = false;
    else if (grid[i][j - 1] == 1) ans += dfs(i, j - 1, grid, inside);
    if (j == w) inside = false;
    else if (grid[i][j + 1] == 1) ans += dfs(i, j + 1, grid, inside);
    return ans;
}
```
- When doing iteration, check the boolean and confirm whether to add on the value
```cpp=
for (int i = 1; i < h; i++)
{
    for (int j = 1; j < w; j++)
    {
        if (grid[i][j] == 1)
        {
            inside = true;
            temp = dfs(i, j, grid, inside);
            if (inside) ans += temp;
        }
    }
}
```
