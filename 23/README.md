# 23. Merge k Sorted Lists
###### tags: `leetcode`
## Description
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

- Example 1:

>Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
>Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6

- Example 2:

>Input: lists = []
Output: []

- Example 3:

>Input: lists = [[]]
Output: []

- Constraints:
>k == lists.length
$0 \leq k \leq 10^4$
$0 \leq lists[i].length \leq 500$
$-10^4 \leq lists[i][j] \leq 10^4$
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed $10^4$.

## Solution
- The merging of LinkedList can be done by using `MergeSort`
- First check the boundary of the subsection, return itself if there is only one LinkedList
```cpp=
if (l == r)
    return lists[l];
```
- Check of there are two, then go straightly into merging. Elsewise do the split for left and right and then merge the two result
```cpp=
if (r - l == 1)
    return KListsMerge(lists[l], lists[r]);
int m = (l + r) / 2;
return KListsMerge(KListsSplit(lists, l, m), KListsSplit(lists, m + 1, r));
```
- For the merging part, keep record of the head and use one iterator to append value
```cpp=
ListNode* ans = new ListNode(0);
ListNode* iter = ans;
```
- When there are all values on left and right, compare the two heads. Join the smaller one on the iterator and turn it to the next one
```cpp=
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
```
- Put the rest of the LinkedList into the result iterator if there is any. Because the answer head is a dummy node, return the next of it
```cpp=
if (l != NULL) iter->next = l;
if (r != NULL) iter->next = r;
return ans->next;
```