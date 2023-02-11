# 1129. Shortest Path with Alternating Colors
###### tags: `leetcode`
## Description
You are given an integer n, the number of nodes in a directed graph where the nodes are labeled from 0 to n - 1. Each edge is red or blue in this graph, and there could be self-edges and parallel edges.

You are given two arrays redEdges and blueEdges where:

redEdges[i] = [ai, bi] indicates that there is a directed red edge from node ai to node bi in the graph, and
blueEdges[j] = [uj, vj] indicates that there is a directed blue edge from node uj to node vj in the graph.
Return an array answer of length n, where each answer[x] is the length of the shortest path from node 0 to node x such that the edge colors alternate along the path, or -1 if such a path does not exist.

- Example 1:

>Input: n = 3, redEdges = [[0,1],[1,2]], blueEdges = []
Output: [0,1,-1]

- Example 2:

>Input: n = 3, redEdges = [[0,1]], blueEdges = [[2,1]]
Output: [0,1,-1]

- Constraints:

>1 <= n <= 100
0 <= redEdges.length, blueEdges.length <= 400
redEdges[i].length == blueEdges[j].length == 2
0 <= ai, bi, uj, vj < n

## Solution
- It is a typical BFS problem. Use the structure of BFS may solve it
- The graph contains two parts and it is difficult to monitor with the two graph. As the result, combine them into a two dimensional array with the color as note
```cpp=
for (vector<int>& edge : redEdges) {
    int u = edge[0];
    int v = edge[1];
    graph[u].emplace_back(v, 1);
}

for (vector<int>& edge : blueEdges) {
    int u = edge[0];
    int v = edge[1];
    graph[u].emplace_back(v, 2);
}
```
- As for the queue, the store the color of the current node and the corresponding ending node number
```cpp=
queue<pair<int, int>> q{{{0, 0}}};
```
- In the BFS, count the step number and the queue size. For each time, empty the whole chunk of the queue in the session.
```cpp=
for (int step = 0; !q.empty(); ++step)
    for (int sz = q.size(); sz > 0; --sz) {
```
- For each iteration, pop the front queue and update the new ans if the current destination node has not being iterated yet. Append all the vertices that is the other color and not iterated yet
```cpp=
auto [u, prevColor] = q.front();
q.pop();
ans[u] = ans[u] == -1 ? step : ans[u];
for (auto& [v, edgeColor] : graph[u]) {
    if (v == -1 || edgeColor == prevColor)
        continue;
    q.emplace(v, edgeColor);
    v = -1;
}
```