# 598 Range Addition II
###### tags: `leetcode` `153`
## Problem Statement
You are given an m x n matrix M initialized with all 0's and an array of operations ops, where ops[i] = [ai, bi] means M[x][y] should be incremented by one for all $0 \leq x < a_i$ and $0 \leq y < b_i$.

Count and return the number of maximum integers in the matrix after performing all the operations.

- Example 1:
> Input: m = 3, n = 3, ops = [[2,2],[3,3]]
Output: 4
Explanation: The maximum integer in M is 2, and there are four of it in M. So return 4.
- Example 2:

> Input: m = 3, n = 3, ops = [[2,2],[3,3],[3,3],[3,3],[2,2],[3,3],[3,3],[3,3],[2,2],[3,3],[3,3],[3,3]]
Output: 4
- Example 3:

> Input: m = 3, n = 3, ops = []
Output: 9
- Constraints:

> $1 \leq m, n \leq 4 \times 10^4\\
0 \leq ops.length \leq 10^4\\
ops[i].length == 2\\
1 \leq a_i \leq m\\
1 \leq b_i \leq n$
## Solution
- Since the up-left can be added everytime, record the maximum x-axis and y-axis will do the job.
```cpp=
for (auto i: ops)
{
    if (min_x> i[0])
        min_x= i[0];
    if (min_y> i[1])
        min_y= i[1];
}
return min_x* min_y;
```