# 1162. As Far from Land as Possible
###### tags: `leetcode`
## Description
Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized, and return the distance. If no land or water exists in the grid, return -1.

The distance used in this problem is the Manhattan distance: the distance between two cells $(x_0, y_0)$ and $(x_1, y_1)$ is $|x_0 - x_1| + |y_0 - y_1|$.

- Example 1:
![](https://i.imgur.com/TYzauTR.png)

>Input: grid = $[[1,0,1],[0,0,0],[1,0,1]]$
Output: 2
>>Explanation: The cell (1, 1) is as far as possible from all the land with distance 2.

- Example 2:
![](https://i.imgur.com/m1U98XU.png)

>Input: grid = $[[1,0,0],[0,0,0],[0,0,0]]$
Output: 4
>>Explanation: The cell (2, 2) is as far as possible from all the land with distance 4.

- Constraints:

>n == grid.length
n == grid[i].length
1 $\leq$ n $\leq$ 100
$grid[i][j]$ is 0 or 1

## Solution
- For the problem to solve, the simpler version should not compare the longest distance from the perspective of water, but should use land to do the calculation
- In order to get the farest water, expand the land until the no more water is left.
- For distinguishing between the new added land and the land needing expandtion right now, let the new-added land to be the next distance values
```cpp=
if (grid[i][j] == dist && grid[i][j] > 0)
{
    if (i + 1 < grid.size() && grid[i + 1][j] == 0)
    {
        grid[i + 1][j] = dist + 1;
        cnt = true;
    }
    if (i > 0 && grid[i - 1][j] == 0)
    {
        grid[i - 1][j] = dist + 1;
        cnt = true;
    }
    if (j + 1 < grid[0].size() && grid[i][j + 1] == 0)
    {
        grid[i][j + 1] = dist + 1;
        cnt = true;
    }
    if (j > 0 && grid[i][j - 1] == 0)
    {
        grid[i][j - 1] = dist + 1;
        cnt = true;
    }
}
```
- The `cnt` is recording whether new land is added. If the iteration contains no more new land, return the distance value previously. Remember the all 1 and all 0 case, which should be -1
```cpp=
if (cnt == false)
    return (dist == 1) ? -1 : dist - 1;
```