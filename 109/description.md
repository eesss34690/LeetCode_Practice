# 109. Convert Sorted List to Binary Search Tree
###### tags: `leetcode`
## Description
Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height-balanced binary search tree.

- Example 1:
![](https://i.imgur.com/Dc6gV8w.png)

>Input: head = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
>>Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.

- Example 2:

>Input: head = []
Output: []

- Constraints:

>The number of nodes in head is in the range $[0,\ 2 \times 10^4]$.
$-10^5 \leq Node.val \leq 10^5$

## Solution
- The problem can be done by a simple recursive function
- Because there is no knowing of the ListedList length, put it into the vector in order to organize the tree.
```cpp=
ListNode* temp = head;
while (temp != NULL)
{
    vecList.push_back(temp->val);
    temp = temp->next;
}
```
- While iterating the tree, go to the middle of the subvector and put it into the value.
```cpp=
int m = (l + r) / 2;
auto ans = new (TreeNode);
ans->val = vecList[m];
```
- When putting left and right value, tell whether there are other values not being put yet
```cpp=
ans->left = (l == m)? NULL : iterateTree(l, m - 1);
ans->right = (r == m) ? NULL : iterateTree(m + 1, r);
```
- When returning, **must print the value once before ending the function**. Seems like a bug and I have reported the issue.
```cpp=
TreeNode* ans;
if (vecList.size() == 0)
    return ans;
else
    ans = iterateTree(0, vecList.size() - 1);
cout << ans->val;
return ans;
```