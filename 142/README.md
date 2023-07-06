# 142. Linked List Cycle II
###### tags: `leetcode`
## Description
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.

- Example 1:
![](https://i.imgur.com/OJ5dFUU.png)

>Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
>>Explanation: There is a cycle in the linked list, where tail connects to the second node.

- Example 2:
![](https://i.imgur.com/AW4WZeC.png)

>Input: head = [1,2], pos = 0
Output: tail connects to node index 0
>>Explanation: There is a cycle in the linked list, where tail connects to the first node.

- Example 3:
![](https://i.imgur.com/VeO60oj.png)

>Input: head = [1], pos = -1
Output: no cycle
>>Explanation: There is no cycle in the linked list.

- Constraints:

>The number of the nodes in the list is in the range $[0, 10^4]$.
$-10^5 \leq Node.val \leq 10^5$
pos is -1 or a valid index in the linked-list.

- Follow up: Can you solve it using O(1) (i.e. constant) memory?

## Solution
- The problem is not a typical question. But can be solve by some  creation
- The problem claims that the linked list contains circle, which means that it is not a self loop. So put two iterations and let one go faster. One day the two would collide (Go back to one of the stage where the loop exists).
```cpp=
ListNode *slow = head;
ListNode *fast = head;
while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast)
        break;
}
```
- Check if the `slow` is actually `nullptr`, just like `fast`, which would mean that there is no loop and the two just go to the end
```cpp=
if (fast == nullptr || fast->next == nullptr)
    return nullptr;
```
- As for checking the source of the loop, put one pointer to the front. Iteration through it one by one until the loop hit for the first time.
```cpp=
fast = slow;
slow = head;
while (slow != fast) {
    slow = slow->next;
    fast = fast->next;
}
return slow;
```