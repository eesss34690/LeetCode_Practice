class Solution {
public:
    int w, h;
    int dfs(int i, int j, vector<vector<int>>& grid, bool& inside) {
        int ans = 1;
        grid[i][j] = -1;
        if (i == 0) inside = false;
        else if (grid[i - 1][j] == 1) ans += dfs(i - 1, j, grid, inside);
        if (i == h) inside = false;
        else if (grid[i + 1][j] == 1) ans += dfs(i + 1, j, grid, inside);
        if (j == 0) inside = false;
        else if (grid[i][j - 1] == 1) ans += dfs(i, j - 1, grid, inside);
        if (j == w) inside = false;
        else if (grid[i][j + 1] == 1) ans += dfs(i, j + 1, grid, inside);
        return ans;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int ans = 0, temp;
        bool inside;
        w = grid[0].size() - 1, h = grid.size() - 1;
        for (int i = 1; i < h; i++)
        {
            for (int j = 1; j < w; j++)
            {
                if (grid[i][j] == 1)
                {
                    inside = true;
                    temp = dfs(i, j, grid, inside);
                    if (inside) ans += temp;
                }
            }
        }
        return ans;
    }
};
