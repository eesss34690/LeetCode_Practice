# 1632_Rank_Transform_of_a_Matrix
###### tags: `leetcode` `1632`
## Problem Statement
Given an m x n matrix, return a new matrix answer where answer```[row][col]``` is the rank of matrix```[row][col]```.

The rank is an integer that represents how large an element is compared to other elements. It is calculated using the following rules:

The rank is an integer starting from 1.
If two elements p and q are in the same row or column, then:
:::info
If $p < q$ then $rank(p) < rank(q)$
If $p = q$ then $rank(p) = rank(q)$
If $p > q$ then $rank(p) > rank(q)$
:::

The rank should be as small as possible.
It is guaranteed that answer is unique under the given rules.

- Example 1:
![](https://i.imgur.com/LnJN9tu.png)

> Input: matrix = [[1,2],[3,4]]
Output: [[1,2],[2,3]]
Explanation:
> > The rank of ```matrix[0][0]``` is 1 because it is the smallest integer in its row and column.

> > The rank of ```matrix[0][1]``` is 2 because ```matrix[0][1] > matrix[0][0]``` and matrix[0][0] is rank 1.

> > The rank of ```matrix[1][0]``` is 2 because ```matrix[1][0] > matrix[0][0]``` and matrix[0][0] is rank 1.

> > The rank of ```matrix[1][1]``` is 3 because ```matrix[1][1] > matrix[0][1]```, ```matrix[1][1] > matrix[1][0]```, and both matrix[0][1] and matrix[1][0] are rank 2.
- Example 2:
![](https://i.imgur.com/8CzYLM2.png)

> Input: matrix = [[7,7],[7,7]]
Output: [[1,1],[1,1]]
- Example 3:
![](https://i.imgur.com/e43f8dH.png)

> Input: matrix = [[20,-21,14],[-19,4,19],[22,-47,24],[-19,4,19]]
Output: [[4,2,3],[1,3,4],[5,1,6],[1,3,4]]
- Example 4:
![](https://i.imgur.com/7g5TGyY.png)

> Input: matrix = [[7,3,6],[1,4,5],[9,8,2]]
Output: [[5,1,4],[1,2,3],[6,3,1]]
- Constraints:

> $m = matrix.length\\
n = matrix[i].length\\
1 \leq m, n \leq 500\\
-10^9 \leq matrix[row][col] \leq 10^9$
## Solution
- This problem can be think in a simple logic, but to implement it needs lots of programming skill
    - To begin with, the matrix is interfered by other elements which are
        - In the same row/ column
        - Smaller
    - To do it in a correct order, start from the smallest element and do it increasingly.
    - To fill in the target value, look whether there are other elements in the same row/column which have the value filled. Look for the maximum, and the target value would be ```1+ ${maximum}```
    - The most problematic part is that there are ```duplicates``` in the matrix, so everytime when dealing with a target, looking for other duplicates and check whether their row/column have the same index to see whether their values are the identical.
- The algorithm I used is ```Union and Find```.
- To begin with, construct a pairing and sort the value with ```map```.
```cpp=
map<int, vector<pair<int, int>>> groupByValue;
for (int r = 0; r < m; ++r)
    for (int c = 0; c < n; ++c)
        groupByValue[matrix[r][c]].push_back({r, c});
```
- Construct a class for each target named ```Union``` for making sure they are in the same parents or not.
- The map ```parent``` store the parent of every index.
- Therefore, to see the parent of target, the column and row index will be sent into the parent insert and then search whether the parents has record.
- If positive, their parent would be the same one, else different.
```cpp=
class UnionFind {
public:
    unordered_map<int, int> parent;
    int Find(int u) {
        if (u == parent[u]) return u;
        return parent[u] = Find(parent[u]);
    }
    void Union(int u, int v) {
        if (parent.count(u) == 0) parent[u] = u;
        if (parent.count(v) == 0) parent[v] = v;
        int pu = Find(u), pv = Find(v);
        if (pu != pv) parent[pu] = pv;
    }
};
```
```cpp=
for (auto const& [r, c] : cells)
    uf.Union(r, c + m);
```
- Once set the parenting relationship, add all the parent and their children into a map.

```cpp=
unordered_map<int, vector<int>> groups;
for (auto const& [u, _] : uf.parent) 
    groups[uf.Find(u)].push_back(u);
```
- Inside the group, all the data should be the maximum one, so see which contains the max.
- Remember to update the rank as the current row/column maximum value.
```cpp=
for (auto const& [_, group] : groups) {
    int maxRank = 0;
    for (int i : group) maxRank = max(maxRank, rank[i]);
    for (int i : group) rank[i] = maxRank + 1;
}
```
- Put in the answer.
```cpp=
for (auto const& [r, c] : cells) matrix[r][c] = rank[r];
```