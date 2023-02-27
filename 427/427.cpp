/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
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
    Node* construct(vector<vector<int>>& grid) {
        return iterateGrid(grid, 0, 0, grid.size());
    }
};