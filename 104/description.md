# 104. Maximum Depth of Binary Tree
###### tags: `leetcode`
## Description
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

- Example 1:
![](https://i.imgur.com/G9YGe4s.png)

>Input: root = [3,9,20,null,null,15,7]
Output: 3

- Example 2:

>Input: root = [1,null,2]
Output: 2

- Constraints:

The number of nodes in the tree is in the range [0, 104].
$-100 \leq \text{Node.val} \leq 100$

## Solution
- By checking the BFS, the depth can be determined
- Construct a queue for the root, check the existence of root first. Push the root inside
```cpp=
if (root == NULL)
    return 0;
queue<TreeNode*> q;
q.push(root);
```
- In the queue, check the siblings for the node. Append to the queue if the child node is not empty
```cpp=
while (!q.empty())
{
    ans++;
    for (int i = q.size() - 1; i > -1; --i)
    {
        TreeNode* temp = q.front();
        q.pop();
        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right != NULL)
            q.push(temp->right);
    }
}
```