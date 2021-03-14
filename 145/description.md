# 145_Binary_Tree_Postorder_Traversal
###### tags: `leetcode` `145`
## Problem Statement
Given the root of a binary tree, return the postorder traversal of its nodes' values.

- Example 1:

> Input: root = [1,null,2,3]
Output: [3,2,1]
- Example 2:

> Input: root = []
Output: []
- Example 3:

> Input: root = [1]
Output: [1]
- Example 4:

> Input: root = [1,2]
Output: [2,1]
- Example 5:

> Input: root = [1,null,2]
Output: [2,1]

- Constraints:

> The number of the nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
 
## Solution
- This is just like the former question, but with different traversal method.
:::info
[https://hackmd.io/@eesss34690/rkUnRSiXu](https://)
:::

- this needs to traverse to the left, then add the right one, lastly add the value into the vector.

```cpp=
void treversal(TreeNode* a){
    if (a->left){
        treversal(a->left);
    }
    if (a->right){
        treversal(a->right);
    }
    ans.push_back(a->val);
}
```
```cpp=
vector<int> ans;
vector<int> postorderTraversal(TreeNode* root) {
    if (root)
        treversal(root);
    return ans;
}
```
