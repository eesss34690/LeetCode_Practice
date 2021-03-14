# 102_Binary_Tree_Level_Order_Traversal
###### tags: `leetcode` `102`
## Problem Statement
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

- Example 1:

> Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
- Example 2:

> Input: root = [1]
Output: [[1]]
- Example 3:

> Input: root = []
Output: []

- Constraints:

> The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000
## Solution
- This is different to the former question, but with likewise idea.
- Since it is asked about the **level**, the use a vector to store the current used level, and store the next level treenode is the solution.
```cpp=
vector<vector<int>> ans;
if (!root)
    return ans;
vector<int> temp;
vector<TreeNode*> res(1, root); 
int s;
while (res.size())
{
    s= res.size();
    for (int i= 0; i< s; i++)
    {
        temp.push_back(res[0]->val);
        if (res[0]-> left)
        {
            res.push_back(res[0]->left);
        }
        if (res[0]->right)
        {
            res.push_back(res[0]->right);
        }
        res.erase(res.begin());
    }
    ans.push_back(temp);
    temp.clear();
}
return ans;
```