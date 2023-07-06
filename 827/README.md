# 827_Making_A_Large_Island
###### tags: `leetcode` `827`
## Problem Statement
You are given an ```n x n``` binary matrix grid. You are allowed to change at most one 0 to be 1.

Return the size of the largest island in grid after applying this operation.

An island is a 4-directionally connected group of 1s.
- Example 1:

> Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
- Example 2:
> Input: grid = [[1,1],[1,0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.
- Example 3:
> Input: grid = [[1,1],[1,1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 4.
- Constraints:
> $n = grid.length \\
n = grid[i].length \\
1 \leq n \leq 500$
grid[i][j] is either 0 or 1.
## Solution
- In this scenario, there are 4 directions to expand the territories.
- Since the problem needs to find the ```0``` to add as to get the largest island, we need to count the island seperately.
- The method is to expand its way up to the last size with dfs and give it its corresponding ```ID``` and every single space has the total size.

```cpp=
vector<int> dx = {0, 0, 1, -1};
vector<int> dy = {1, -1, 0, 0};
void dfs(pair<int, int> v) {
    grid[v.first][v.second] = islandId;
    comp++;
    for (int i = 0; i < 4; ++i) {
        int x = v.first + dx[i];
        int y = v.second + dy[i];
        if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1) {
            dfs({x, y});
        }
    }
}
```
- In the main code, keep track of all the island size and remember the largest one.

```cpp=
for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
        if (grid[i][j] == 1) {
            comp = 0;
            dfs({i, j});
            islandSizes[islandId++] = comp;
            mx = max(comp, mx);
        }
    }
}
```
- After that, see whether there is chance to add other island and connect a bigger result

```cpp=
for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
        if (grid[i][j] == 0) {
            int cur = 0;
            set<int> neig;
            for (int k = 0; k < 4; ++k) {
                int x = i + dx[k];
                int y = j + dy[k];
                if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != 0 && neig.find(grid[x][y]) == neig.end()) {
                    cur += islandSizes[grid[x][y]];
                    neig.insert(grid[x][y]);
                }
            }
            mx = max(cur + 1, mx);
        }
    }
}
```