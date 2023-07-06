# 797. All Paths From Source to Target
###### tags: `leetcode`
## Problem Statement
Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.

The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).

- Example 1:


>Input: graph = [[1,2],[3],[3],[]]
Output: [[0,1,3],[0,2,3]]
>>Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
- Example 2:


> Input: graph = [[4,3,1],[3,2,4],[3],[4],[]]
Output: [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]
 

- Constraints:

> n == graph.length
2 <= n <= 15
0 <= graph[i][j] < n
graph[i][j] != i (i.e., there will be no self-loops).
All the elements of graph[i] are unique.
The input graph is guaranteed to be a DAG.

## Solution
This is a simple demonstration of DFS. To find all the paths in the DAG, simply trace each of the path as the recursive function to connect the dot, and then add to the final answer.
To note, the argument need to be referenced because the value is shared for the answer. As for the temporary one, the value should be uniqle for all the sequences.

```cpp=
void dfs(vector<vector<int>>& sol, vector<int> temp, vector<vector<int>>& graph, int starter, int num)
{
    temp.push_back(starter);
    if (starter == num)
    {
        sol.push_back(temp);
        return;
    }
    for (auto i : graph[starter])
        dfs(sol, temp, graph, i, num);       
}
```