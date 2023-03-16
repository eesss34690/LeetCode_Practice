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
    TreeNode* buildSubTree(vector<int>& inorder, vector<int>& postorder, int inl, int postl, int len) {
        int temp = postl + len - 1;
        TreeNode* src = new TreeNode(postorder[temp]);
        if (len == 1)
            return src;
        auto it = find(inorder.begin() + inl, inorder.begin() + inl + len, postorder[temp]);
        temp = (it - inorder.begin()) - inl;
        if (temp != 0)
            src->left = buildSubTree(inorder, postorder, inl, postl, temp);
        inl += temp + 1;
        postl += temp;
        temp = len - temp - 1;
        if (temp != 0)
            src->right = buildSubTree(inorder, postorder, inl, postl, temp);
        return src;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildSubTree(inorder, postorder, 0, 0, postorder.size());
    }
};
