# 834 Sum of Distances in Tree
###### tags: `leetcode` `834`
## Problem Statement
There is an undirected connected tree with n nodes labeled from $0$ to $n - 1$ and $n - 1$ edges.

You are given the integer n and the array edges where $edges[i] = [a_i, b_i]$ indicates that there is an edge between nodes $a_i$ and $b_i$ in the tree.

Return an array answer of length $n$ where $answer[i]$ is the sum of the distances between the ith node in the tree and all other nodes.

- Example 1:
![](https://i.imgur.com/srWrixK.png)

> Input: n = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
Output: [8,12,6,10,10,10]
Explanation: The tree is shown above.
We can see that ```dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + dist(0,5)```
equals ```1 + 1 + 2 + 2 + 2 = 8.```
Hence, answer[0] = 8, and so on.
- Example 2:
![](https://i.imgur.com/LCacfNp.png)

> Input: n = 1, edges = []
Output: [0]
- Example 3:
![](https://i.imgur.com/cQIvQJR.png)

> Input: n = 2, edges = [[1,0]]
Output: [1,1]
 
- Constraints:

> $1 \leq n \leq 3 \times 10^4\\
edges.length = n - 1\\
edges[i].length = 2\\
0 <= a_i,\ b_i < n\\
a_i\ \not= b_i$
The given input represents a valid tree.
## Solution
- Since the tree is bi-directional, put the connection into vector for storage the connected status.
```cpp=
for(auto i: edges) {
    tree[i[0]].push_back(i[1]);
	tree[i[1]].push_back(i[0]);
}
```
- There are 2 numbers to remember for each connection: 
    - m: the current sum of the whole related values
    - under: the distance itself
- Therefore, to remember the whole anwser, in each connection, update the current anwser and the cumulative anwser.
```cpp=
for(int j: tree[i]) {
	if(j==p) continue;
	if(m.find({i,j})==m.end()) {
		auto p= getDfs(j,i);
		m[{i,j}]=p.first;
		under[{i,j}]=p.second;
	}
	ans+= m[{i,j}]+under[{i,j}];
	c+=under[{i,j}];
}
```