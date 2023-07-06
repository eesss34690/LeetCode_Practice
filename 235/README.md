# 235_Lowest_Common_Ancestor_of_a_Binary_Search_Tree
###### tags: `leetcode` `235`
## Problem Statement
Given a ```binary search tree (BST)```, find the ```lowest common ancestor (LCA)``` of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

- Example 1:

> Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.
- Example 2:
> Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
- Example 3:

> Input: root = [2,1], p = 2, q = 1
Output: 2
- Constraints:

> The number of nodes in the tree is in the range [2, 105].
$-10^9 \leq Node.val \leq 10^9$
All ```Node.val``` are unique.
$p != q$
p and q will exist in the BST.
## Solution
- This one is related to ```236: _Lowest_Common_Ancestor_of_a_Binary_Tree``` (https://hackmd.io/@eesss34690/HkXqXe92_), but in a simpler way.
- Because a binary search tree must guarantee the tree to be formed with the left hand side all smaller than the root amd right hand side bigger than the root, we can decide which way to dig into.
- First decide the bigger value of the target.

```cpp=
if (p->val< q->val)
    return lowest(root, q, p);
else
    return lowest(root, p, q);
```
- Then if the value is the same as the target or it is in between of the target, return the root value

```cpp=
if (root== b|| root== s)
    return root; 
if (root->val< b->val&& root->val> s->val)
    return root;
```
- See wether the value is too big or too small for the target and search for the different direction.

```cpp=
if (root->val> b->val)
    return lowest(root->left, b, s);
else
    return lowest(root->right, b, s);
```