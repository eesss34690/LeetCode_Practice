# 2477. Minimum Fuel Cost to Report to the Capital
###### tags: `leetcode`
## Description
There is a tree (i.e., a connected, undirected graph with no cycles) structure country network consisting of n cities numbered from 0 to n - 1 and exactly n - 1 roads. The capital city is city 0. You are given a 2D integer array roads where roads[i] = [ai, bi] denotes that there exists a bidirectional road connecting cities ai and bi.

There is a meeting for the representatives of each city. The meeting is in the capital city.

There is a car in each city. You are given an integer seats that indicates the number of seats in each car.

A representative can use the car in their city to travel or change the car and ride with another representative. The cost of traveling between two cities is one liter of fuel.

Return the minimum number of liters of fuel to reach the capital city.

- Example 1:
![](https://i.imgur.com/ia71CNc.png)

>Input: roads = [[0,1],[0,2],[0,3]], seats = 5
Output: 3
>>Explanation: 
- Representative1 goes directly to the capital with 1 liter of fuel.
- Representative2 goes directly to the capital with 1 liter of fuel.
- Representative3 goes directly to the capital with 1 liter of fuel.
It costs 3 liters of fuel at minimum. 
It can be proven that 3 is the minimum number of liters of fuel needed.

- Example 2:
![](https://i.imgur.com/ADM2tjT.png)

>Input: roads = [[3,1],[3,2],[1,0],[0,4],[0,5],[4,6]], seats = 2
Output: 7
>>Explanation: 
- Representative2 goes directly to city 3 with 1 liter of fuel.
- Representative2 and representative3 go together to city 1 with 1 liter of fuel.
- Representative2 and representative3 go together to the capital with 1 liter of fuel.
- Representative1 goes directly to the capital with 1 liter of fuel.
- Representative5 goes directly to the capital with 1 liter of fuel.
- Representative6 goes directly to city 4 with 1 liter of fuel.
- Representative4 and representative6 go together to the capital with 1 liter of fuel.
It costs 7 liters of fuel at minimum. 
It can be proven that 7 is the minimum number of liters of fuel needed.

- Example 3:
![](https://i.imgur.com/Jcmw3U2.png)

>Input: roads = [], seats = 1
Output: 0
>>Explanation: No representatives need to travel to the capital city.

- Constraints:

>1 <= n <= 105
roads.length == n - 1
roads[i].length == 2
$0 \leq a_i, b_i < n$
$a_i != b_i$
roads represents a valid tree.
$1 \leq seats \leq 10^5$

## Solution
- Because we need to record the number of subtree in each node, the easiest way to do it is to use DFS
- When initializing, the graph vector has each of the path it can get to. Also store an array to remember the walk through
```cpp=
vector<vector<int>> graph;
vector<int> visit;
graph.resize(roads.size() + 1);
visit.resize(graph.size());
for (auto &i : roads)
{
    graph[i[0]].push_back(i[1]);
    graph[i[1]].push_back(i[0]);
}
```
- Use the dfs to check the subtree to iterate through, and add the subtree for the child node to itself
```cpp=
long long int left = 1;
visit[idx] = 1;
for (auto &i : graph[idx])
    if (!visit[i])
        left += dfs(i, seats, ans);
```
- When adding to answer, check the seat size, adding 1 means when it is just fit, we do not need to add one more. Also when the idx is root, just return it back
```cpp=
if (idx == 0)
    return left;
ans += ((left - 1) / seats) + 1;
return left;
```
