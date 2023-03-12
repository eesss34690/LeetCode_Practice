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
class Solution {
public:
    ListNode* KListsMerge(ListNode* l, ListNode* r)
    {
        ListNode* ans = new ListNode(0);
        ListNode* iter = ans;
        while (l != NULL && r != NULL)
        {
            if (l->val < r->val)
            {
                iter->next = l;
                l = l->next;
            }
            else
            {
                iter->next = r;
                r = r->next;
            }
            iter = iter->next;
        }
        if (l != NULL) iter->next = l;
        if (r != NULL) iter->next = r;
        return ans->next;
    }
    ListNode* KListsSplit(vector<ListNode*>& lists, int l, int r)
    {
        if (l == r)
            return lists[l];
        if (r - l == 1)
            return KListsMerge(lists[l], lists[r]);
        int m = (l + r) / 2;
        return KListsMerge(KListsSplit(lists, l, m), KListsSplit(lists, m + 1, r));
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() > 0)
            return KListsSplit(lists, 0, lists.size() - 1);
        else return NULL;
    }
};
