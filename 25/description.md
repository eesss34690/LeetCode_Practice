# 25_Reverse_Nodes_in_k-Group
###### tags: `leetcode` `25`
## Problem Statement
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

- Example 1:
> Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
- Example 2:
> Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
- Example 3:
> Input: head = [1,2,3,4,5], k = 1
Output: [1,2,3,4,5]
- Example 4:
> Input: head = [1], k = 1
Output: [1]
 
- Constraints:

> The number of nodes in the list is in the range sz.
$1 \leq sz \leq 5000$
$0 \leq Node.val \leq 1000$
$1 \leq k \leq sz$
 
- Follow-up: Can you solve the problem in $O(1)$ extra memory space?
## Solution
- Since it is a listed list structure, the question can be split by doing multiple reverse sublist.
- Calculate the number of sublist

```cpp=
while (h->next!= NULL)
{
    size++;
    h= h->next;
}
```
- Keep reversing the string and remember the last begin one.

```cpp=
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
            fu= fu-> next;             }
}
```
- If it is the first element, record the first one and see wether to put the last one to ```null```

```cpp=
if (h== head)
{
    ans= pre;
    h= cur;            
    if (cur== pre)
        prev_h-> next= nullptr;
}
```
- If not the first one, connect the previous head to the current one.

```cpp=
else
{
    prev_h-> next= pre;
    prev_h= h;
    h= cur;
}
```
- The rest depends on wether there are segments left.

```cpp=
if (size)
{
    prev_h-> next= cur;
}
else
{
    prev_h-> next= NULL;
}
```
