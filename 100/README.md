# 100. Same Tree
###### tags: `leetcode`
## Problem Statement
Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

- Example 1:

![](https://i.imgur.com/UcVXdKg.png)

>Input: p = [1,2,3], q = [1,2,3]
Output: true

- Example 2:

![](https://i.imgur.com/7deSsim.png)

>Input: p = [1,2], q = [1,null,2]
Output: false

- Example 3:

![](https://i.imgur.com/YFdbgXM.png)

>Input: p = [1,2,1], q = [1,1,2]
Output: false

- Constraints:

>The number of nodes in both trees is in the range [0, 100].
$-10^4 \leq Node.val \leq 10^4$

## Solution
- This is a simple treversal problem
- Still somethings to notice: Because the `null` value is acceptable, the check of nullity is required
```cpp=
if (p == nullptr && q == nullptr)
    return true;
if (p == nullptr || q == nullptr || p->val != q->val)
    return false;
if (!isSameTree(p->left, q->left))
    return false;
if (!isSameTree(p->right, q->right))
    return false;
return true;
```