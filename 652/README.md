# 652. Find Duplicate Subtrees
###### tags: `leetcode`
## Description
Given the root of a binary tree, return all duplicate subtrees.

For each kind of duplicate subtrees, you only need to return the root node of any one of them.

Two trees are duplicate if they have the same structure with the same node values.

- Example 1:
![](https://i.imgur.com/uWY4rBk.png)

>Input: root = [1,2,3,4,null,2,4,null,null,4]
Output: [[2,4],[4]]

- Example 2:
![](https://i.imgur.com/iUCVAvi.png)

>Input: root = [2,1,1]
Output: [[1]]

- Example 3:
![](https://i.imgur.com/oNmDJaQ.png)

>Input: root = [2,2,2,3,null,3,null]
Output: [[2,3],[3]]

- Constraints:

>The number of the nodes in the tree will be in the range $[1, 5000]$
$-200 \leq Node.val \leq 200$

## Solution
- Because the problem is related to the whole path of the nodes, there is need to store the path reached for every node
- To do so, construct a map and store the whole path structure inside the map in self-defined format
```cpp=
unordered_map<string, int> fullPath;
```
- When dealing with the path, return star if the node is null and iterate through left and right then finally the value of it, separated by comma
```cpp=
if (root == NULL)
    return "*";
string s = serialPath(root->left) + "," + serialPath(root->right) + "," + to_string(root->val);
```
- After the path is determined, see the map and check whether the path has already been used. Push back the answer if it exists. And remember to add into the path map for future use
```cpp=
if (fullPath[s] == 1)
    ans.push_back(root);
fullPath[s]++;
```