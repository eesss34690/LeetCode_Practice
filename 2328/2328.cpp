class Solution {
public:
    int modulus = 1000000007;
    int dfs(vector<vector<int>>& grid, vector<vector<int>>& dp, int i, int j, int prev) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] <= prev) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = (1 + dfs(grid, dp, i + 1, j, grid[i][j]) + dfs(grid, dp, i, j + 1, grid[i][j]) + dfs(grid, dp, i - 1, j, grid[i][j]) + dfs(grid, dp, i, j - 1, grid[i][j])) % modulus;
    }
    int countPaths(vector<vector<int>>& grid) {
        int ans = 0;
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++) ans = (ans + dfs(grid, dp, i, j, -1)) % modulus;
        }
        return ans;
    }
};