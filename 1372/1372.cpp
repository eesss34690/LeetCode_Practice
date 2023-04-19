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
    int ans = 0;

    void zz(TreeNode* node, bool goLeft, int currPathLen) {
        if (!node) return;
        ans = std::max(ans, currPathLen);
        if (goLeft) {
            zz(node->left, false, currPathLen + 1);
            zz(node->right, true, 1);
        } else {
            zz(node->right, true, currPathLen + 1);
            zz(node->left, false, 1);
        }
    }

    int longestZigZag(TreeNode* root) {
        zz(root, true, 0);
        zz(root, false, 0);
        return ans;
    }
};
