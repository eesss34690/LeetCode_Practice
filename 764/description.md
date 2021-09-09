# 764 Largest Plus Sign
###### tags: `leetcode` `764`
## Problem Statement
You are given an integer n. You have an n x n binary grid grid with all values initially 1's except for some indices given in the array mines. The ith element of the array mines is defined as $mines[i] = [x_i, y_i]$ where $grid[x_i][y_i] == 0$.

Return the order of the largest axis-aligned plus sign of 1's contained in grid. If there is none, return 0.

An axis-aligned plus sign of 1's of order k has some center $grid[r][c] = 1$ along with four arms of length k - 1 going up, down, left, and right, and made of 1's. Note that there could be 0's or 1's beyond the arms of the plus sign, only the relevant area of the plus sign is checked for 1's.

- Example 1:
![](https://i.imgur.com/1q4CZxj.png)

> Input: n = 5, mines = [[4,2]]
Output: 2
Explanation: In the above grid, the largest plus sign can only be of order 2. One of them is shown.
- Example 2:
![](https://i.imgur.com/NWAfMKW.png)

> Input: n = 1, mines = [[0,0]]
Output: 0
Explanation: There is no plus sign, so return 0.
 
- Constraints:

> $1 \leq n \leq 500\\
1 \leq mines.length \leq 5000\\
0 \leq x_i,\ y_i < n$
All the pairs $(x_i, y_i)$ are unique.
## Solution
- This is a dynamic programming problem with additional modification.
- To begin with, we can use four directional simple as the meaning of ```in the direction above, the maximum spanning of consecutive 1s```.
- With the 4 matrix, the computation is relatively easy. For each node, the minimum among 4 matrix is the answer.
- Construct the real data matrix first.
```cpp=
vector<vector<int>> mat(n, vector<int>(n, 1));
for(auto it : mines)
{
    int x = it[0] ;
    int y = it[1] ;
    mat[x][y] = 0;
}
```
- Let the matrix be the sequence and update for 1 occurance.
```cpp=
int x = n - i - 1;
int y = n - j - 1;
if( (i>0)   && top[i][j] ) top[i][j] += top[i-1][j];
if( (j>0)   && lef[i][j] ) lef[i][j] += lef[i][j-1];
if( (x<n-1) && bot[x][y] ) bot[x][y] += bot[x+1][y];
if( (y<n-1) && rig[x][y] ) rig[x][y] += rig[x][y+1];
```
- Therefore, the answer will be in the four matrix maximum.
```cpp=
int ans = 0;
for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
        ans = max(ans, min({lef[i][j], rig[i][j], top[i][j], bot[i][j]}));
```