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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int> storage;
        for (ListNode* i = head; i != NULL; i = i->next) storage.push_back(i->val);
        int temp = storage[k - 1];
        storage[k - 1] = storage[storage.size() - k];
        storage[storage.size() - k] = temp;
        temp = max(k, int(storage.size()) + 1 - k);
        ListNode* node = head;
        for (int i = 0; i < temp; i++)
        {
            if (i == k - 1 || i == storage.size() - k) node->val = storage[i];
            node = node->next;
        }
        return head;
    }
};
