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
    TreeNode* lowest(TreeNode* root, TreeNode* b, TreeNode* s)
    {
        if (root== b|| root== s)
            return root; 
        if (root->val< b->val&& root->val> s->val)
            return root;
        if (root->val> b->val)
            return lowest(root->left, b, s);
        else
            return lowest(root->right, b, s);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val< q->val)
            return lowest(root, q, p);
        else
            return lowest(root, p, q);   
    }
};
