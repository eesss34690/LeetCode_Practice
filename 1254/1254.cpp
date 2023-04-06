class Solution {
public:
    int w, h;
    bool dfs(int i, int j, vector<vector<int>>& grid) {
        grid[i][j] = -1;
        bool closed = true;
        if (i == 0) closed = false;
        else if (grid[i - 1][j] == 0) closed &= dfs(i - 1, j, grid);
        if (i == h - 1) closed = false;
        else if (grid[i + 1][j] == 0) closed &= dfs(i + 1, j, grid);
        if (j == 0) closed = false;
        else if (grid[i][j - 1] == 0) closed &= dfs(i, j - 1, grid);
        if (j == w - 1) closed = false;
        else if (grid[i][j + 1] == 0) closed &= dfs(i, j + 1, grid);
        return closed;
    }
    int closedIsland(vector<vector<int>>& grid) {
        w = grid[0].size(), h = grid.size();
        int ans = 0;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (grid[i][j] == 0)
                    if (dfs(i, j, grid)) ans++;
            }
        }
        return ans;
    }
};