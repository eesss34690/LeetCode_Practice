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
    vector<int> ans;
    void treversal(TreeNode* a){
        if (a->left){
            treversal(a->left);
        }
        ans.push_back(a->val);
        if (a->right){
            treversal(a->right);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        if (root)
            treversal(root);
        return ans;
    }
};