# 95 Unique Binary Search Trees II
###### tags: `leetcode` `95`
## Problem Statement
Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.

- Example 1:
![](https://i.imgur.com/ZpIFVOS.png)

> Input: n = 3
Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
- Example 2:

> Input: n = 1
Output: [[1]]
 
- Constraints:

> $1 \leq n \leq 8$
## Solution
- Actually the binary search tree has one fundamental principle to follow--> ```The left children are smaller, the right children are bigger, than the root.```
- As the result, use iterative cumulate method to add the siblings into the main trees.
```cpp=
vector<TreeNode*> left = rec(start, i-1), right = rec(i+1, end);
for (auto l : left)
    for (auto r : right)
        res.push_back(new TreeNode(i, l, r));
```