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
    int minDepth(TreeNode* root) {
        int ans = 0, len;
        if (root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            ans++;
            len = q.size();
            while (len--)
            {
                auto cur = q.front();
                q.pop();
                if (cur->left == NULL)
                {
                    if (cur->right == NULL) return ans;
                    else q.push(cur->right);
                }
                else
                {
                    q.push(cur->left);
                    if (cur->right != NULL) q.push(cur->right);
                }
            }
        }
        return ans;
    }
};
