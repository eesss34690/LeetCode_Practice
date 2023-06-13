class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int ans = 0, j, k;
        for (int i = 0; i < grid.size(); i++)
        {
            for (j = 0; j < grid.size(); j++)
            {
                for (k = 0; k < grid.size() && grid[i][k] == grid[k][j]; k++);
                if (k == grid.size()) ans++;
            }
        }
        return ans;
    }
};
