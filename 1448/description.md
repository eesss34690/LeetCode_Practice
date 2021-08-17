# 1448_Count_Good_Nodes_in_Binary_Tree
###### tags: `leetcode` `1448`
## Problem Statement
Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.

Return the number of good nodes in the binary tree.

- Example 1:
![](https://i.imgur.com/kmhXy13.png)

> Input: root = [3,1,4,3,null,1,5]
Output: 4
Explanation: Nodes in blue are good.
Root Node (3) is always a good node.
Node 4 -> (3,4) is the maximum value in the path starting from the root.
Node 5 -> (3,4,5) is the maximum value in the path
Node 3 -> (3,1,3) is the maximum value in the path.
- Example 2:
![](https://i.imgur.com/NVNjLk4.png)

> Input: root = [3,3,null,4,2]
Output: 3
Explanation: Node 2 -> (3, 3, 2) is not good, because "3" is higher than it.
- Example 3:

> Input: root = [1]
Output: 1
Explanation: Root is considered as good.
 
- Constraints:

> The number of nodes in the binary tree is in the range $[1, 10^5]$.
Each node's value is between $[-10^4, 10^4]$
## Solution
- This is a DFS problem. To deal with it we can do a simple treversal for each path.
- In each treversal, record the current maximum value as the threshold. Keep updating as path extend.
```cpp=
int max_= cur;
if (root-> val>= cur)
{
    ans++;
    max_= root-> val;
}
if (root->left)
    treverse(root->left, max_);
if (root-> right)
    treverse(root->right, max_);
```
