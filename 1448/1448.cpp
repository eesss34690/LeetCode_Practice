/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans;
    void treverse(TreeNode* root, int cur)
    {
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
    }
    int goodNodes(TreeNode* root) {
        ans= 0;
        treverse(root, root-> val);
        return ans;
    }
};
