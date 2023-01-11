# 1443. Minimum Time to Collect All Apples in a Tree
###### tags: `leetcode`
## Problem Statement
Given an undirected tree consisting of n vertices numbered from 0 to n-1, which has some apples in their vertices. You spend 1 second to walk over one edge of the tree. Return the minimum time in seconds you have to spend to collect all apples in the tree, starting at vertex 0 and coming back to this vertex.

The edges of the undirected tree are given in the array edges, where edges[i] = [ai, bi] means that exists an edge connecting the vertices ai and bi. Additionally, there is a boolean array hasApple, where hasApple[i] = true means that vertex i has an apple; otherwise, it does not have any apple.

- Example 1:
![](https://i.imgur.com/8XvtyEL.png)

>Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,true,true,false]
Output: 8 
>>Explanation: The figure above represents the given tree where red vertices have an apple. One optimal path to collect all apples is shown by the green arrows.

- Example 2:
![](https://i.imgur.com/ARQ8r3S.png)

>Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,false,true,false]
Output: 6
>>Explanation: The figure above represents the given tree where red vertices have an apple. One optimal path to collect all apples is shown by the green arrows.

- Example 3:

>Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,false,false,false,false,false]
Output: 0

- Constraints:

>1 <= n <= 105
edges.length == n - 1
edges[i].length == 2
0 <= ai < bi <= n - 1
fromi < toi
hasApple.length == n

## Solution
- This is a harder problem to `DFS`.
- Because not all the nodes are required to traverse, and the format of the graph is a undirected graph, the best way to do it is to use DFS to search for the path for the designated dst.
- When starting, prepare the list for adjancent nodes.
```cpp=
for (auto &i : edges)
{
    adjList[i[0]].push_back(i[1]);
    adjList[i[1]].push_back(i[0]);
}
```
- After the construction of the edges, start traversal with the distance remembered.
    - If the path is needed, add the redundant part in case multiple same paths are counted
```cpp=
for (auto &i : adjList[start])
{
    if (i != priv)
    {
        temp = dfs(i, dist + 1, start, hasApple);
        if (temp)
            cur += temp - dist;
    }
}
```
- After the iteration for all the adjancent nodes, count the result for this one if this node should be included
```cpp=
return (cur || hasApple[start]) ? dist + cur : 0;
```