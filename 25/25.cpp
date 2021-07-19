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
/*
A -> B    C -> D    E
  <-   xx   <-     
  
*/
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        k= k- 1;
        if (!k)
            return head;
        int size= 1;
        ListNode* pre, *cur, *fu, *h= head, *ans, *prev_h= head;
        while (h->next!= NULL)
        {
            size++;
            h= h->next;
        }
        h= head;
        while(size> k)
        {
            pre= h;
            cur= h->next;
            fu= cur->next;
            for (int i= 0; i< k; i++)
            {
                cur->next= pre;
                pre= cur;
                if (fu!= NULL)
                {
                    cur= fu;
                    if (fu-> next!= NULL)
                        fu= fu-> next;                   
                }
            }
            if (h== head)
            {
                ans= pre;
                h= cur;            
                if (cur== pre)
                    prev_h-> next= nullptr;
            }
            else
            {
                prev_h-> next= pre;
                prev_h= h;
                h= cur;
            }
            size-= k+ 1;
        }
        if (size)
        {
            prev_h-> next= cur;
        }
        else
        {
            prev_h-> next= NULL;
        }
        return ans;
    }
};
