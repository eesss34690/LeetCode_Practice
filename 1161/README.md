# 1161. Maximum Level Sum of a Binary Tree
###### tags: `leetcode`
## Description
Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

Return the smallest level x such that the sum of all the values of nodes at level x is maximal.

- Example 1:
![](https://assets.leetcode.com/uploads/2019/05/03/capture.JPG)

>Input: root = [1,7,0,7,-8,null,null]
Output: 2
>>Explanation: 
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.

- Example 2:

>Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
Output: 2

- Constraints:

>The number of nodes in the tree is in the range [1, 104].
-105 <= Node.val <= 105

## Solution
- The problem is a typical `BFS`
- Use a queue to store all the values in the same level. Calculate the current level value and keep the maximum score
```cpp=
queue<TreeNode*> q;
q.push(root);
```
- When checking for each level, check the size to make sure the stuff from next level would not be iterated in the inner loop
```cpp=
temp = 0;
len = q.size();
while (len--)
```
- In the inner loop, get each of the node and add up. Put the child into the queue again to make them be gone through the next iteration
```cpp=
cur = q.front();
q.pop();
temp += cur->val;
if (cur->left != NULL) q.push(cur->left);
if (cur->right != NULL) q.push(cur->right);
```
- After, check the value and update the answer for level value if necessary
```cpp=
if (val < temp)
{
    ans = level;
    val = temp;
}
```