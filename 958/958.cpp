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
    bool isCompleteTree(TreeNode* root) {
        bool ChildNull = false;
        queue<TreeNode*> q;
        int cnt;
        q.push(root);
        while (!q.empty())
        {
            cnt = q.size();
            while (cnt--)
            {
                TreeNode* cur = q.front();
                q.pop();
                if (cur->left != NULL)
                {
                    if (ChildNull) return false;
                    else q.push(cur->left);
                }
                else ChildNull = true;
                if (cur->right != NULL)
                {
                    if (ChildNull) return false;
                    else q.push(cur->right);
                }
                else ChildNull = true;
            }
        }
        return true;
    }
};
