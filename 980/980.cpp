class Solution {
public:
    int total;
    void dfs(int& ans, vector<vector<int>> stamp, int start_i, int start_j, int cur)
    {
        if (stamp[start_i][start_j] == -1)
            return;
        cur++;
        if (stamp[start_i][start_j] == 2)
        {
            if (cur == total)
                ans++;
            return;
        }
        stamp[start_i][start_j] = -1;
        if (start_i > 0)
            dfs(ans, stamp, start_i - 1, start_j, cur);
        if (start_j > 0)
            dfs(ans, stamp, start_i, start_j - 1, cur);
        if (start_i < stamp.size() - 1)
            dfs(ans, stamp, start_i + 1, start_j, cur);
        if (start_j < stamp[0].size() - 1)
            dfs(ans, stamp, start_i, start_j + 1, cur);
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int ans = 0;
        int start_i, start_j;
        total = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    start_i = i;
                    start_j = j;
                }
                if (grid[i][j] != -1)
                    total++;
            }
        }
        dfs(ans, grid, start_i, start_j, 0);
        return ans;
    }
};