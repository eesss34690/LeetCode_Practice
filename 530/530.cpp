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
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        auto temp = root;
        if (root->left != NULL)
        {
            temp = root->left;
            while (temp->right != NULL) temp = temp->right;
            ans = min(ans, root->val - temp->val);
            ans = min(ans, getMinimumDifference(root->left));
        }
        if (root->right != NULL)
        {
            temp = root->right;
            while (temp->left != NULL) temp = temp->left;
            ans = min(ans, temp->val - root->val);
            ans = min(ans, getMinimumDifference(root->right));
        }
        return ans;
    }
};
