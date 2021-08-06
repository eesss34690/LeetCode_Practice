# 113_Path_Sum_II
###### tags: `leetcode` `113`
## Problem Statement
Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where each path's sum equals targetSum.

A leaf is a node with no children.

- Example 1:
![](https://i.imgur.com/FZzLULL.png)

> Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
- Example 2:
![](https://i.imgur.com/iRXEFeh.png)

> Input: root = [1,2,3], targetSum = 5
Output: []
- Example 3:

Input: root = [1,2], targetSum = 0
Output: []
 
- Constraints:

> The number of nodes in the tree is in the range [0, 5000].
$-1000 \leq Node.val \leq 1000\\
-1000 \leq targetSum \leq 1000$
## Solution
- By doing this, we need to search through all the path.
- If the target now has other path to walk (not a leaf node), keep adding up.

```cpp=
if (root->left)
{
    vector<int> temp= now;
    temp.push_back((root-> left)-> val);
    pushPath(temp, root-> left, sum+ (root-> left)-> val, targetSum);
}
if (root->right)
{
    now.push_back((root-> right)-> val);
    sum+= (root-> right)-> val;
    pushPath(now, root-> right, sum, targetSum);
}
```
- If it is a leaf, check whether the sum match and add the answer.

```cpp=
else if (root->left== NULL&& sum== targetSum)
{
    ans.push_back(now);
}
```