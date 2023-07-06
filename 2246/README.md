# 2246. Longest Path With Different Adjacent Characters
###### tags: `leetcode`
## Description
You are given a tree (i.e. a connected, undirected graph that has no cycles) rooted at node 0 consisting of n nodes numbered from 0 to n - 1. The tree is represented by a 0-indexed array parent of size n, where parent[i] is the parent of node i. Since node 0 is the root, parent[0] == -1.

You are also given a string s of length n, where s[i] is the character assigned to node i.

Return the length of the longest path in the tree such that no pair of adjacent nodes on the path have the same character assigned to them.

- Example 1:
![](https://i.imgur.com/VcD7wfL.png)

>Input: parent = [-1,0,0,1,1,2], s = "abacbe"
Output: 3
>>Explanation: The longest path where each two adjacent nodes have different characters in the tree is the path: 0 -> 1 -> 3. The length of this path is 3, so 3 is returned.
It can be proven that there is no longer path that satisfies the conditions. 

- Example 2:
![](https://i.imgur.com/gqs7a4i.png)

>Input: parent = [-1,0,0,0], s = "aabc"
Output: 3
>>Explanation: The longest path where each two adjacent nodes have different characters is the path: 2 -> 0 -> 3. The length of this path is 3, so 3 is returned.

- Constraints:

>n == parent.length == s.length
1 <= n <= 105
0 <= parent[i] <= n - 1 for all i >= 1
parent[0] == -1
parent represents a valid tree.
s consists of only lowercase English letters.

## Solution
- The problem is still related to DFS but with a slight change
- Because the statement does not specify that the path should start from the root node, all the subtree should be advertised
- Because the answer may lies in the subtree, not in the root, the maximum value should be kept, and the subtree result needs to be stored with the definition that `only one directional path is there and the node with the value mest present`
- To construct a path, it may be the middle node that connects the two single direction paths. Therefore, update the maximum 2 paths for all the child nodes and add 1 is the current maximum within the subtree
```cpp=
temp = dfs(i, idx, s, ans);
if (s[i] != s[idx])
{
    if (cur_max_1 < temp)
    {
        cur_max_2 = cur_max_1;
        cur_max_1 = temp;
    } else if (cur_max_2 < temp)
        cur_max_2 = temp;
}
```

```cpp=
ans = max(1 + cur_max_1 + cur_max_2, ans);
```
- When returning, the value should be the single directional path because this should be added by the parents for the connecting dots
```cpp=
return 1 + cur_max_1;
```