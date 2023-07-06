# 133. Clone Graph
###### tags: `leetcode`
## Description
Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (`int`) and a list (`List[Node]`) of its neighbors.
```
class Node {
    public int val;
    public List<Node> neighbors;
}
 ```

**Test case format:**

For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with `val == 1`, the second node with `val == 2`, and so on. The graph is represented in the test case using an adjacency list.

An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with `val = 1`. You must return the copy of the given node as a reference to the cloned graph.

- Example 1:
![](https://assets.leetcode.com/uploads/2019/11/04/133_clone_graph_question.png)

>Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
Output: [[2,4],[1,3],[2,4],[1,3]]
>>Explanation: There are 4 nodes in the graph.
1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).

- Example 2:
![](https://assets.leetcode.com/uploads/2020/01/07/graph.png)

>Input: adjList = [[]]
Output: [[]]
>>Explanation: Note that the input contains one empty list. The graph consists of only one node with val = 1 and it does not have any neighbors.

- Example 3:

>Input: adjList = []
Output: []
>>Explanation: This an empty graph, it does not have any nodes.

- Constraints:

>The number of nodes in the graph is in the range [0, 100].
$1 \leq Node.val \leq 100$
Node.val is unique for each node.
There are no repeated edges and no self-loops in the graph.
The Graph is connected and all nodes can be visited starting from the given node.

## Solution
- The problem is not intuitive to see what is the core of the task first. But the problem is actually trying to make a copy of the current Nodes.
- To make a copy, the task is to map the original node to the new node and return the new one.
- Because of doublly connected nodes, without the mapping and reuse the iterated nodes, the infinite loop will be generated
- In order to avoid this, use a map to store the mapping for the value and the new node.
```cpp=
unordered_map<int, Node*> copyMap;
```
- After initializing the new node and giving the value to the new node, put it into the map. Even though the vector of neighbor is not added yet, it does not affect the result because it is a pointer which can be modified afterward
```cpp=
Node* ans = new Node();
ans->val = node->val;
copyMap[ans->val] = ans;
```
- For every nodes in the neighbor, check the existence in the copy. If it does not exist, iterate back to the function, else use the one in the copy map.
```cpp=
for (auto &i : node->neighbors)
{
    if (copyMap.find(i->val) == copyMap.end()) ans->neighbors.push_back(cloneGraph(i));
    else ans->neighbors.push_back(copyMap[i->val]);
}
```