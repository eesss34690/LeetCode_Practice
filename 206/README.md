# 206 Reverse Linked List
###### tags: `leetcode` `206`
## Problem Statement
Given the head of a singly linked list, reverse the list, and return the reversed list.
- Example 1:
![](https://i.imgur.com/iKFTa9f.png)

> Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
- Example 2:
![](https://i.imgur.com/Xh0slas.png)

> Input: head = [1,2]
Output: [2,1]
- Example 3:

> Input: head = []
Output: []
 
- Constraints:

> The number of nodes in the list is the range [0, 5000].
$-5000 \leq Node.val \leq 5000$
 
- Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?
## Solution
- Just use the ```prev, current, next``` as the record to change the next of the current for the previous one.
```cpp=
while (cur!= NULL)
{
    nxt= cur-> next;
    cur->next= head;
    head= cur;
    cur= nxt;
}
```
- Remember to change the head to NULL as well in prevention of loop.
```cpp=
head->next= NULL;
```