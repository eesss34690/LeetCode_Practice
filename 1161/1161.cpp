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
    int maxLevelSum(TreeNode* root) {
        int val = INT_MIN, temp, len, ans, level = 1;
        queue<TreeNode*> q;
        TreeNode* cur;
        q.push(root);
        while (!q.empty())
        {
            temp = 0;
            len = q.size();
            while (len--)
            {
                cur = q.front();
                q.pop();
                temp += cur->val;
                if (cur->left != NULL) q.push(cur->left);
                if (cur->right != NULL) q.push(cur->right);
            }
            if (val < temp)
            {
                ans = level;
                val = temp;
            }
            level++;
        }
        return ans;
    }
};
