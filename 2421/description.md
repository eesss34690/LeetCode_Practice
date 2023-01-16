# 2421. Number of Good Paths
###### tags: `leetcode`
## Description
There is a tree (i.e. a connected, undirected graph with no cycles) consisting of n nodes numbered from 0 to n - 1 and exactly n - 1 edges.

You are given a 0-indexed integer array vals of length n where vals[i] denotes the value of the ith node. You are also given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.

A good path is a simple path that satisfies the following conditions:

The starting node and the ending node have the same value.
All nodes between the starting node and the ending node have values less than or equal to the starting node (i.e. the starting node's value should be the maximum value along the path).
Return the number of distinct good paths.

Note that a path and its reverse are counted as the same path. For example, 0 -> 1 is considered to be the same as 1 -> 0. A single node is also considered as a valid path.

- Example 1:
![](https://i.imgur.com/sF815WD.png)

>Input: vals = [1,3,2,1,3], edges = [[0,1],[0,2],[2,3],[2,4]]
Output: 6
>>Explanation: There are 5 good paths consisting of a single node.
There is 1 additional good path: 1 -> 0 -> 2 -> 4.
(The reverse path 4 -> 2 -> 0 -> 1 is treated as the same as 1 -> 0 -> 2 -> 4.)
Note that 0 -> 2 -> 3 is not a good path because vals[2] > vals[0].

- Example 2:
![](https://i.imgur.com/Akj3iio.png)

>Input: vals = [1,1,2,2,3], edges = [[0,1],[1,2],[2,3],[2,4]]
Output: 7
>>Explanation: There are 5 good paths consisting of a single node.
There are 2 additional good paths: 0 -> 1 and 2 -> 3.

- Example 3:
![](https://i.imgur.com/0v31J4X.png)

>Input: vals = [1], edges = []
Output: 1
>>Explanation: The tree consists of only one node, so there is one good path.

- Constraints:

>n == vals.length
1 <= n <= 3 * 104
0 <= vals[i] <= 105
edges.length == n - 1
edges[i].length == 2
0 <= ai, bi < n
ai != bi
edges represents a valid tree.

## Solution
- The problem is relatively hard. But the algorithm lies behind is `Uniform Grid`
- To make it, add each values one by one by reconstructing the graph. In order to make it works, construct the object to be able to determine the line by choosing one object as the root path
```cpp=
void connect(int p, int q) {
    int i = find(p), j = find(q);
    if (i == j) return;
    if (rank[i] < rank[j]) {
        id[i] = j;  
    } else {
        id[j] = i;
        if (rank[i] == rank[j]) rank[j]++;
    }
    --cnt;
}
```
- Therefore, when finding the path, find the root and see if they are a match
```cpp=
int find(int p) {
    if (id[p] == p) return p;
    return id[p] = find(id[p]);
}
bool connected(int p, int q) { 
    return find(p) == find(q); 
}
```
- In the procedure, construct the paths with the smaller value to bigger value because of the functionality of adding one by one
```cpp=
for (auto &e : edges) {
    int u = e[0], v = e[1];
            
    if (vals[u] >= vals[v]) {
        adj[u].push_back(v);
    } else if (vals[v] >= vals[u]) {
        adj[v].push_back(u);
    }
}
```
- In each value, we need to connect the graph first, group the nodes with the values, add first the number of current nodes then the poaths we got now by ```num * (num - 1)```
```cpp=
for (auto &[value, allNodes] : sameValues) {
    for (int u : allNodes) {
        for (int v : adj[u]) {
            uf.connect(u, v);
        }
    }
    unordered_map<int, int> group;
    for (int u : allNodes) {
        group[uf.find(u)]++;
    }
    goodPaths += allNodes.size();

    for (auto &[_, size] : group) {
        goodPaths += (size * (size - 1) / 2);
    }
}
```