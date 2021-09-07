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
    ListNode* reverseList(ListNode* head) {
        if (head== NULL)
            return head;
        ListNode* cur= head->next, *nxt;
        head->next= NULL;
        while (cur!= NULL)
        {
            nxt= cur-> next;
            cur->next= head;
            head= cur;
            cur= nxt;
        }
        return head;
    }
};
