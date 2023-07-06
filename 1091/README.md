# 1091. Shortest Path in Binary Matrix
###### tags: `leetcode`
## Description
Given an `n x n` binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return `-1`.

A clear path in a binary matrix is a path from the top-left cell (i.e., `(0, 0)`) to the bottom-right cell (i.e., `(n - 1, n - 1)`) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.

- Example 1:
![](https://assets.leetcode.com/uploads/2021/02/18/example1_1.png)

>Input: grid = [[0,1],[1,0]]
Output: 2

- Example 2:
![](https://assets.leetcode.com/uploads/2021/02/18/example2_1.png)

>Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
Output: 4

- Example 3:

Input: grid >= [[1,0,0],[1,1,0],[1,1,0]]
Output: -1

- Constraints:

>n == grid.length
n == grid[i].length
1 <= n <= 100
grid[i][j] is 0 or 1

## Solution
- The problem is a typical BFS question. Update each of the path into the queue for the further update for the path and return once the destination is reached
- In the queue, we need to put the information of the x-index and y-index into, as well as the current path length into the queue. The initialization is `{0,0,1}`.
```cpp=
queue<vector<int>> queue;
queue.push({0, 0, 1});
```
- The key point of the problem is that **once the block is iterated, mark it as past** in order to avoid the repeated loop.
```cpp=
grid[0][0] = 1;
```
- For the BFS, iterate through the queue and return once the destination is reached. For the further directions, iterate through them and update the new index if it is not iterated yet. Add the te queue for further update
```cpp=
while (!queue.empty()) {
    auto current = queue.front();
    queue.pop();
    int row = current[0];
    int col = current[1];
    int distance = current[2];

    if (row == n - 1 && col == n - 1) return distance;

    for (const auto& direction : directions) {
        int newRow = row + direction[0];
        int newCol = col + direction[1];

        if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && grid[newRow][newCol] == 0) {
            grid[newRow][newCol] = 1;
            queue.push({newRow, newCol, distance + 1});
        }
    }
}
```
