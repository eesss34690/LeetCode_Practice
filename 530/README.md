# 530. Minimum Absolute Difference in BST
###### tags: `leetcode`
## Description
Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.

- Example 1:
![](https://assets.leetcode.com/uploads/2021/02/05/bst1.jpg)

>Input: root = [4,2,6,1,3]
Output: 1

- Example 2:
![](https://assets.leetcode.com/uploads/2021/02/05/bst2.jpg)

>Input: root = [1,0,48,null,null,12,49]
Output: 1

- Constraints:

>The number of nodes in the tree is in the range [2, 104].
0 <= Node.val <= 105

- Note: This question is the same as 783: https://leetcode.com/problems/minimum-distance-between-bst-nodes/

## Solution
- The problem can be done by the iteration through all the possibilities. The only possible choices for a root node are
    - The rightmost of the root's left
    - The leftmost of the root's right
- Leverage on these, iterate through all of the nodes and do the comparison
```cpp=
if (root->left != NULL)
{
    temp = root->left;
    while (temp->right != NULL) temp = temp->right;
    ans = min(ans, root->val - temp->val);
    ans = min(ans, getMinimumDifference(root->left));
}
if (root->right != NULL)
{
    temp = root->right;
    while (temp->left != NULL) temp = temp->left;
    ans = min(ans, temp->val - root->val);
    ans = min(ans, getMinimumDifference(root->right));
}
```
