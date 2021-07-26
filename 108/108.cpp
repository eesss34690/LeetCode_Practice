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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        vector<int>::iterator pos= nums.begin()+ (nums.size()/ 2);
        TreeNode* ans= new TreeNode(*pos);
        if (pos!= nums.begin())
        {
            vector<int> l(nums.begin(), pos);
            ans-> left= sortedArrayToBST(l);            
        }
        if (pos!= nums.end()- 1)
        {
            vector<int> r(pos+ 1, nums.end());
            ans-> right= sortedArrayToBST(r);            
        }

        return ans;
    }
};
