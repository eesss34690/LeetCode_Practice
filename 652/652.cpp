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
    unordered_map<string, int> fullPath;
    vector<TreeNode*> ans;
    string serialPath(TreeNode* root)
    {
        if (root == NULL)
            return "*";
        string s = serialPath(root->left) + "," + serialPath(root->right) + "," + to_string(root->val);
        if (fullPath[s] == 1)
            ans.push_back(root);
        fullPath[s]++;
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        serialPath(root);
        return ans;
    }
};
