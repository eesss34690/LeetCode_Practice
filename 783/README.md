# 783. Minimum Distance Between BST Nodes
###### tags: `leetcode`
## Description
Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.

- Example 1:
![](https://i.imgur.com/fpUbZNJ.png)

>Input: root = [4,2,6,1,3]
Output: 1

- Example 2:
![](https://i.imgur.com/7sIxwej.png)

>Input: root = [1,0,48,null,null,12,49]
Output: 1

- Constraints:

>The number of nodes in the tree is in the range $[2,\ 100]$.
$0 \leq \text{Node.val} \leq 10^5$

## Solution
- This is difficult at first glance. But after thinking a little bit, it is a simple traversal problem with a small twist
- When finding the smallest difference in the `BST`, the sequence has already being determined. Therefore the sorted result is just using `DFS`. As the result, use DFS to iterate through all the nodes and compare the neighbor distance
```cpp
if (root->left != NULL) minDiffInBST(root->left);
if (pre >= 0) res = min(res, root->val - pre);
pre = root->val;
if (root->right != NULL) minDiffInBST(root->right);
return res;
```