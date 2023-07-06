# 980. Unique Paths III
###### tags: `leetcode`
## Problem Statement
You are given an m x n integer array grid where grid[i][j] could be:

1 representing the starting square. There is exactly one starting square.
2 representing the ending square. There is exactly one ending square.
0 representing empty squares we can walk over.
-1 representing obstacles that we cannot walk over.
Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.

- Example 1:
![](https://i.imgur.com/OnNyCA5.png)
> Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
Output: 2
Explanation: We have the following two paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)

- Example 2:
![](https://i.imgur.com/Aayrb1E.png)
> Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
Output: 4
Explanation: We have the following four paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)

- Example 3:
![](https://i.imgur.com/0ViOjfX.png)
> Input: grid = [[0,1],[2,0]]
Output: 0
Explanation: There is no path that walks over every empty square exactly once.
Note that the starting and ending square can be anywhere in the grid.

- Constraints:

> m == grid.length
n == grid[i].length
1 <= m, n <= 20
1 <= m * n <= 20
-1 <= grid[i][j] <= 2
There is exactly one starting cell and one ending cell.

## Solution
- This can be solved by a simple dfds algorithm.
- Because all the roads need to be traverse, remember the total steps to walk first and, at the same time, get the starting point
```cpp=
for (int i = 0; i < grid.size(); i++)
{
    for (int j = 0; j < grid[0].size(); j++)
    {
        if (grid[i][j] == 1)
        {
            start_i = i;
            start_j = j;
        }
        if (grid[i][j] != -1)
            total++;
    }
}
```
- By recongnizing the source, find the path by stamping on one trace path, and check if the dirrection hit the wall or hit the obstacles. The one on the forbidden path is dropped.
```cpp=
if (stamp[start_i][start_j] == -1)
    return;
cur++;
```
- When hit the destination, check if it gets all the paths already. If positive, store the result.
```cpp=
if (stamp[start_i][start_j] == 2)
{
    if (cur == total)
        ans++;
    return;
}
```