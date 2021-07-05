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
        if (a->right){
            treversal(a->right);
        }
        ans.push_back(a->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        if (root)
            treversal(root);
        return ans;
    }
};