# 144_Binary_Tree_Preorder_Traversal
###### tags: `leetcode` `144`
## Problem Statement
Given the root of a binary tree, return the preorder traversal of its nodes' values.

- Example 1:


> Input: root = [1,null,2,3]
Output: [1,2,3]
- Example 2:

> Input: root = []
Output: []
- Example 3:

> Input: root = [1]
Output: [1]
- Example 4:

> Input: root = [1,2]
Output: [1,2]
- Example 5:

> Input: root = [1,null,2]
Output: [1,2]
 

- Constraints:

> The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100

## Solution
- Since the question is about how to construct the traversal of the tree, the key point is to understand how the traversal goes.
- The preordered traversal can be divided as a consecutive questions.
- The value of the path is added first, and then add in other elements left first then left.
- The empty one shoud be kicked out.
```cpp=
vector<int> ret;
if (root) {
    vector<TreeNode *> s;
    s.push_back(root);
    while (s.size()) {
        TreeNode * node = s.back();
        s.pop_back();
        ret.push_back(node->val);
        if (node->right)
            s.push_back(node->right);
        if (node->left)
            s.push_back(node->left);
        }
    }
    return ret;
```