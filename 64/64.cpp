class Solution {
public:
    int r, c;
    vector<vector<int>> dp;
    void minSubPathSum(vector<vector<int>>& grid, int y, int x) {
        if (grid[y][x] != -1)
        {
            if (y == r)
            {
                if (x == c) dp[y][x] = grid[y][x];
                else
                {
                    if (grid[y][x + 1] != -1) minSubPathSum(grid, y, x + 1);
                    dp[y][x] = grid[y][x] + dp[y][x + 1];
                }
            }
            else if (x == c)
            {
                if (grid[y + 1][x] != -1) minSubPathSum(grid, y + 1, x);
                dp[y][x] = grid[y][x] + dp[y + 1][x];
            }
            else
            {
                if (grid[y][x + 1] != -1) minSubPathSum(grid, y, x + 1);
                if (grid[y + 1][x] != -1) minSubPathSum(grid, y + 1, x);
                dp[y][x] = grid[y][x] + min(dp[y][x + 1], dp[y + 1][x]);
            }
        }
        grid[y][x] = -1;
    }
    int minPathSum(vector<vector<int>>& grid) {
        dp.resize(grid.size(), vector<int>(grid[0].size()));
        r = grid.size() - 1, c = grid[0].size() - 1;
        minSubPathSum(grid, 0, 0);
        return dp[0][0];
    }
};
