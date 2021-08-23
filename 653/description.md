# 653_TwoSum IV - Input is a BST
###### tags: `leetcode` `653`
## Problem Statement
Given the root of a Binary Search Tree and a target number k, return true if there exist two elements in the BST such that their sum is equal to the given target.

![](https://i.imgur.com/qlh55sw.png)

- Example 1
> Input: root = [5,3,6,2,4,null,7], k = 9
Output: true
![](https://i.imgur.com/1G4DPRf.png)
- Example 2
> Input: root = [5,3,6,2,4,null,7], k = 28
Output: false
- Example 3

> Input: root = [2,1,3], k = 4
Output: true
- Example 4

> Input: root = [2,1,3], k = 1
Output: false
- Example 5:

> Input: root = [2,1,3], k = 3
Output: true

- Constraints:

> The number of nodes in the tree is in the range $[1, 10^4]$.
$-10^4 \leq Node.val \leq 10^4$
root is guaranteed to be a valid binary search tree.
$-10^5 \leq k \leq 10^5$
## Solution
- To make sure all the number is seeked, use treversal to finish the job.
- One important thing is to prevent the value to be taken from the same node, which happens when the target is twice of the node value.
```cpp=
bool treverse(TreeNode* root, int k)
{
    if (k- root->val!= root->val&& find_(rot, k- root->val))
        return true;
    if (root-> left!= NULL)
    {
    	if (treverse(root-> left, k))
            return true;
    }
    if (root-> right!= NULL)
    {
        if (treverse(root-> right, k))
            return true;
    }
    return false;
}
```
- In each time to determine whether the value can make pair, the usage is to see the other pair in the tree staring from the real root.
```cpp=
bool find_(TreeNode* root, int k)
{
    if (root-> val== k)
        return true;
    if (root-> val< k)
    {
        if (root-> right!= NULL&& find_(root-> right, k))
            return true;
    }
    else if (root-> left!= NULL&& find_(root-> left, k))
        return true;
    return false;
}
```