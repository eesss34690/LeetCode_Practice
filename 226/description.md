# 226. Invert Binary Tree
###### tags: `leetcode`
## Description
Given the root of a binary tree, invert the tree, and return its root.

- Example 1:
![](https://i.imgur.com/3XCNHC7.png)

>Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]

- Example 2:
![](https://i.imgur.com/M0oC6Vj.png)

>Input: root = [2,1,3]
Output: [2,3,1]

- Example 3:

>Input: root = []
Output: []

- Constraints:

>The number of nodes in the tree is in the range $[0,\ 100]$.
$-100 \leq \text{Node.val} \leq 100$

## Solution
- By iterating through the tree, the question can be done by divide and conquer.
- The checking procedure should be done by making sure every node is not null and the nullptr is given if the corresponding neighbot node is not empty.
```cpp=
TreeNode* temp;
    if (root->left != nullptr)
        temp = invertTree(root->left);
    else temp = nullptr;
    if (root->right != nullptr)
        root->left = invertTree(root->right);
    else root->left = nullptr;
    root->right = temp;
```