# 101. Symmetric Tree
###### tags: `leetcode`
## Description
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

- Example 1:
![](https://assets.leetcode.com/uploads/2021/02/19/symtree1.jpg)

>Input: root = [1,2,2,3,4,4,3]
Output: true

- Example 2:
![](https://assets.leetcode.com/uploads/2021/02/19/symtree2.jpg)

>Input: root = [1,2,2,null,3,null,3]
Output: false

- Constraints:

>The number of nodes in the tree is in the range [1, 1000].
$-100 \leq Node.val \leq 100$

- Follow up: Could you solve it both recursively and iteratively?

## Solution
- This is an interesting question about recursive
- By checking the extistence of the left and right, make sure that it does not appear only on one side, and return true when both are `NULL`
```cpp=
bool leftNull = (left == NULL);
bool rightNull = (right == NULL);
if (leftNull ^ rightNull)
    return false;
if (leftNull && rightNull)
    return true;
```
- For the recursive part, check the value first and the mirror means **the right children is like the left one** and **the left children is like the right one**. As the result, recursive twice for the comparison with right node of left and left node of right, also with right node of right and left node of left.
```cpp=
return (left->val == right->val) && compare(left->right, right->left) && compare(left->left, right->right);
```