# 129. Sum Root to Leaf Numbers
###### tags: `leetcode`
## Problem Statement
You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path in the tree represents a number.

For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

A leaf node is a node with no children.

- Example 1:
![](https://i.imgur.com/jhPjhrI.png)
>Input: root = [1,2,3]
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.

- Example 2:
![](https://i.imgur.com/ftF5fJE.png)
> Input: root = [4,9,0,5,1]
Output: 1026
Explanation:
The root-to-leaf path 4->9->5 represents the number 495.
The root-to-leaf path 4->9->1 represents the number 491.
The root-to-leaf path 4->0 represents the number 40.
Therefore, sum = 495 + 491 + 40 = 1026.
 
- Constraints:

>The number of nodes in the tree is in the range [1, 1000].
0 <= Node.val <= 9
The depth of the tree will not exceed 10.

## Solution
- This is a simple traverse of treenode
- Everytime when traversing to the new child, update the original value by multiplying 10 and add the child node value, just like the calculation of decimal number.
- Then traverse through leaf to add one the child node value

```cpp=
int sumNum(TreeNode* root, int sum)
{
    sum = sum * 10 + root->val;
    if (root->left == NULL && root->right == NULL)
        return sum;
    int ans = 0;
    if (root->left != NULL)
        ans = sumNum(root->left, sum);
    if (root->right != NULL)
        ans += sumNum(root->right, sum);
    return ans;
}
```