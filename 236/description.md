# 236_Lowest_Common_Ancestor_of_a_Binary_Tree
###### tags: `leetcode` `236`
## Problem Statement
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

- Example 1:


> Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
- Example 2:


> Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
- Example 3:

> Input: root = [1,2], p = 1, q = 2
Output: 1
 
- Constraints:

> The number of nodes in the tree is in the range [2, 105].
-109 <= Node.val <= 109
All Node.val are unique.
p != q
p and q will exist in the tree.

## Solution
- This is the problem related to ```tree```. It can be done by recursively search for the correct value.
- Start by the root value, if the value meets one of the searching target, return the root value.
- If the value does not match, look through the left and right node and see whether they are the value.
- If both return has value, return it, else return the one with value if the other is NULL.

```cpp=
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root== NULL)
            return NULL;
        if (root== p|| root== q)
            return root;
        TreeNode* left= lowestCommonAncestor(root->left, p, q);
        TreeNode* right= lowestCommonAncestor(root->right, p, q);
        if (left== NULL)
            return right;
        if (right== NULL)
            return left;
        return root;
        
    }
};
```