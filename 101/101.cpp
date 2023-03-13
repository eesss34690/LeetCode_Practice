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
    bool compare(TreeNode* left, TreeNode* right) {
        bool leftNull = (left == NULL);
        bool rightNull = (right == NULL);
        if (leftNull ^ rightNull)
            return false;
        if (leftNull && rightNull)
            return true;
        return (left->val == right->val) && compare(left->right, right->left) && compare(left->left, right->right);
    }
    bool isSymmetric(TreeNode* root) {
        return compare(root->left, root->right);
    }
};