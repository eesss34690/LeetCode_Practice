# 207. Course Schedule
###### tags: `leetcode`
## Description
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

- Example 1:

>Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
>>Explanation: There are a total of 2 courses to take.
To take course 1 you should have finished course 0. So it is possible.

- Example 2:

>Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
>>Explanation: There are a total of 2 courses to take.
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

- Constraints:

>1 <= numCourses <= 2000
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.

## Solution
- The problem actually is asking for the fact whether there is a loop in the graph
- To make sure that does not happen, we can collect all the incoming edge count for each node and the outgoing vertex for each node
```cpp=
vector<unordered_set<int>> graph(numCourses);
vector<int> disclude(numCourses, 0);
for (auto &i : prerequisites)
{
    graph[i[1]].insert(i[0]);
    disclude[i[0]]++;
}
```
- For all the nodes, check if they are free and then iterate through them to disclude all the others step by step
```cpp=
while (--numCourses >= 0)
{
    if (disclude[numCourses] == 0) dfs(graph, disclude, numCourses);
}
```
- For `dfs` function, we can disclude the finished node and then go through the outgoing edge by substracting the count by 1 to see whether they are free
```cpp=
void dfs(vector<unordered_set<int>>& graph, vector<int>& disclude, int numCourses) {
    disclude[numCourses] = -1;
    for (auto &i : graph[numCourses]) if (--disclude[i] == 0) dfs(graph, disclude, i);
}
```
- After all the procedures, check the unvisited node
```cpp=
for (int i = 0; i < disclude.size(); i++)
{
    if (disclude[i] > 0) return false;
}
return true;
```
