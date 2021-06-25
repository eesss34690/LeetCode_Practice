# 684_Redundant_Connection
###### tags: `leetcode` `684`
## Problem Statement
In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

 

- Example 1:

> Input: edges = [[1,2],[1,3],[2,3]]
Output: [2,3]
- Example 2:

> Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
Output: [1,4]

- Constraints:

> n == edges.length
3 <= n <= 1000
edges[i].length == 2
1 <= ai < bi <= edges.length
ai != bi
There are no repeated edges.
The given graph is connected.

## Solution
- To solve this case is equivalent to finding a loop in the graph.
- There are many algorithm for finding a loop, like DFS, BFS. But for this question, the fastest way is to use ```DSU (Disjoint Set Union)```.
### DSU
- To complete this, there are 2 elements to remember: ```join```, ```union```.
    - join: find the parent root of the current set.
    - union: if the two dots are from different sets, they need to be combined.

```cpp=
int find(int x) {
    if (x != par[x]) par[x] = find(par[x]);
    return par[x];
}
void uniun(int x, int y) {
    par[find(y)] = find(x);
}
```
- First ocnstruct new set if there are no dots in the existing set.
- If the two dots for the edges are in different set (they have different root parent in ```find```), they need to union.
- If the two dots are in the same set (they have the same parents), they are the dirst edges to form a group.
```cpp=
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        par.resize(edges.size()+1);
        for (int i = 0; i < par.size(); i++)
            par[i] = i;
        for (auto& e : edges)
            if (find(e[0]) == find(e[1])) return e;
            else uniun(e[0],e[1]);
        return edges[0];
    }
private:
    vector<int> par;
    int find(int x) {
        if (x != par[x]) par[x] = find(par[x]);
        return par[x];
    }
    void uniun(int x, int y) {
        par[find(y)] = find(x);
    }
};
```
