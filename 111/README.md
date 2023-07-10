# 111. Minimum Depth of Binary Tree
###### tags: `leetcode`
## Description
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

**Note**: A leaf is a node with no children.

- Example 1:
![](https://assets.leetcode.com/uploads/2020/10/12/ex_depth.jpg)

>Input: root = [3,9,20,null,null,15,7]
Output: 2

- Example 2:

>Input: root = [2,null,3,null,4,null,5,null,6]
Output: 5

- Constraints:

>The number of nodes in the tree is in the range [0, 105].
-1000 <= Node.val <= 1000

## Solution
- With the iteration of `BFS`, we can iterate with depth
```cpp=
if (root == NULL) return ans;
queue<TreeNode*> q;
q.push(root);
```
- With doing iteration, add the answer and check the existence of child. If there is no child then return the value
```cpp=
while (!q.empty())
{
    ans++;
    len = q.size();
    while (len--)
    {
        auto cur = q.front();
        q.pop();
        if (cur->left == NULL)
        {
            if (cur->right == NULL) return ans;
            else q.push(cur->right);
        }
        else
        {
            q.push(cur->left);
            if (cur->right != NULL) q.push(cur->right);
        }
    }
}
```
