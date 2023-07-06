# 2328. Number of Increasing Paths in a Grid
###### tags: `leetcode`
## Description
You are given an m x n integer matrix grid, where you can move from a cell to any adjacent cell in all 4 directions.

Return the number of strictly increasing paths in the grid such that you can start from any cell and end at any cell. Since the answer may be very large, return it modulo 109 + 7.

Two paths are considered different if they do not have exactly the same sequence of visited cells.

- Example 1:
![](https://assets.leetcode.com/uploads/2022/05/10/griddrawio-4.png)

>Input: grid = [[1,1],[3,4]]
Output: 8
>>Explanation: The strictly increasing paths are:
>>- Paths with length 1: [1], [1], [3], [4].
>>- Paths with length 2: [1 -> 3], [1 -> 4], [3 -> 4].
>>- Paths with length 3: [1 -> 3 -> 4].
The total number of paths is 4 + 3 + 1 = 8.

- Example 2:

>Input: grid = [[1],[2]]
Output: 3
>>Explanation: The strictly increasing paths are:
>>- Paths with length 1: [1], [2].
>>- Paths with length 2: [1 -> 2].
The total number of paths is 2 + 1 = 3.

- Constraints:

>m == grid.length
n == grid[i].length
1 <= m, n <= 1000
1 <= m * n <= 105
1 <= grid[i][j] <= 105

## Solution
- The problem can be solved by dynamic programming. By sorting the question to be the starting points for summation
- To clarify whether the point has been iterated, use `-1` to unmark the un-iterated ones
```cpp=
int ans = 0;
vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
```
- For everyone, iterate through and add up to the answer and return it back
```cpp=
for (int i = 0; i < grid.size(); i++)
{
    for (int j = 0; j < grid[0].size(); j++) ans = (ans + dfs(grid, dp, i, j, -1)) % modulus;
}
```
- For the dfs, check the existence by the boundaries and the value for the current one and the previous one
```cpp=
if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] <= prev) return 0;
```
- If the path is connected, the value can be proceded. Go to the four dimensions of the current point and add one for the single point
```cpp=
return dp[i][j] = (1 + dfs(grid, dp, i + 1, j, grid[i][j]) + dfs(grid, dp, i, j + 1, grid[i][j]) + dfs(grid, dp, i - 1, j, grid[i][j]) + dfs(grid, dp, i, j - 1, grid[i][j])) % modulus;
```