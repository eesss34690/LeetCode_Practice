# 427. Construct Quad Tree
###### tags: `leetcode`
## Description
Given a `n * n` matrix grid of 0's and 1's only. We want to represent the grid with a Quad-Tree.

Return the root of the Quad-Tree representing the grid.

Notice that you can assign the value of a node to True or False when isLeaf is False, and both are accepted in the answer.

A Quad-Tree is a tree data structure in which each internal node has exactly four children. Besides, each node has two attributes:

`val`: True if the node represents a grid of 1's or False if the node represents a grid of 0's.
isLeaf: True if the node is leaf node on the tree or False if the node has the four children.
```
class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;
}
```
We can construct a Quad-Tree from a two-dimensional area using the following steps:

If the current grid has the same value (i.e all 1's or all 0's) set isLeaf True and set val to the value of the grid and set the four children to Null and stop.
If the current grid has different values, set isLeaf to False and set val to any value and divide the current grid into four sub-grids as shown in the photo.
Recurse for each of the children with the proper sub-grid.
![](https://i.imgur.com/7ZVmP6c.png)

If you want to know more about the Quad-Tree, you can refer to the wiki.

**Quad-Tree format:**

The output represents the serialized format of a Quad-Tree using level order traversal, where null signifies a path terminator where no node exists below.

It is very similar to the serialization of the binary tree. The only difference is that the node is represented as a list [isLeaf, val].

If the value of isLeaf or val is True we represent it as 1 in the list [isLeaf, val] and if the value of isLeaf or val is False we represent it as 0.

- Example 1:
![](https://i.imgur.com/MiFKWHk.png)

>Input: $grid = [[0,1],[1,0]]$
Output: $[[0,1],[1,0],[1,1],[1,1],[1,0]]$
>>Explanation: The explanation of this example is shown below:
Notice that 0 represnts False and 1 represents True in the photo representing the Quad-Tree.
![](https://i.imgur.com/JKBhNJn.png)

- Example 2:
![](https://i.imgur.com/rJiMHUr.png)

Input: grid = [[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0]]
Output: [[0,1],[1,1],[0,1],[1,1],[1,0],null,null,null,null,[1,0],[1,0],[1,1],[1,1]]
Explanation: All values in the grid are not the same. We divide the grid into four sub-grids.
The topLeft, bottomLeft and bottomRight each has the same value.
The topRight have different values so we divide it into 4 sub-grids where each has the same value.
Explanation is shown in the photo below:
![](https://i.imgur.com/vWT78Ge.png)

- Constraints:

>$n == grid.length == grid[i].length$
$n == 2x where 0 \leq x \leq 6$

## Solution
- The problem is a simple recursive function that iterate through all the sub-elements and find the occurence of differnece
```cpp=
Node* iterateGrid(vector<vector<int>>& grid, int x, int y, int len)
{
    Node* root = new (Node);
    root->val = (grid[x][y] == 1) ? true : false;
    int m = len / 2;
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (grid[x + i][y + j] != grid[x][y] == 1)
            {
                root->topLeft = iterateGrid(grid, x, y, m);
                root->topRight = iterateGrid(grid, x, y + m, m);
                root->bottomLeft = iterateGrid(grid, x + m, y, m);
                root->bottomRight = iterateGrid(grid, x + m, y + m, m);
                return root;
            }
        }
    }
    root->isLeaf = true;
    return root;
}
```