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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        vector<int> temp;
        vector<TreeNode*> res(1, root); 
        int s;
        while (res.size())
        {
            s= res.size();
            for (int i= 0; i< s; i++)
            {
                temp.push_back(res[0]->val);
                if (res[0]-> left)
                {
                    res.push_back(res[0]->left);
                }
                if (res[0]->right)
                {
                    res.push_back(res[0]->right);
                }
                res.erase(res.begin());
            }
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
    }
};