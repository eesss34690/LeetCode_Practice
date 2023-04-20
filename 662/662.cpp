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
    int widthOfBinaryTree(TreeNode* a) {
        if(!a) return 0;
        int ans = 1, sz, a1, b1, i, mn;
        queue<pair<TreeNode*,long long int>>q;
        q.push({a,0});
        while(!q.empty())
        {
            sz = q.size();
            a1 = 0, b1 = 0;
            mn = q.front().second;
            for(i = 0; i < sz; i++)
            {
                auto p = q.front();
                TreeNode* b = p.first;
                long long int k = p.second - mn;
                q.pop();
                if(i == 0) a1 = k;
                if(i == sz - 1) b1 = k;

                if(b->left) q.push({b->left, 2 * k + 1});
                
                if(b->right) q.push({b->right, 2 * k + 2});
            }
            ans = max(ans, b1 - a1 + 1);
        }
        return ans;
    }
};