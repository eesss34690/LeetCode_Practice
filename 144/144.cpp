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
    vector<int> preorderTraversal(TreeNode* root) {
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
  } 
};