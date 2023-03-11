/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    vector<int> vecList;
    TreeNode* iterateTree(int l, int r) {
        int m = (l + r) / 2;
        auto ans = new (TreeNode);
        ans->val = vecList[m];
        ans->left = (l == m)? NULL : iterateTree(l, m - 1);
        ans->right = (r == m) ? NULL : iterateTree(m + 1, r);
        return ans;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* temp = head;
        while (temp != NULL)
        {
            vecList.push_back(temp->val);
            temp = temp->next;
        }
        TreeNode* ans;
        if (vecList.size() == 0)
            return ans;
        else
            ans = iterateTree(0, vecList.size() - 1);
        cout << ans->val;
        return ans;
    }
};
