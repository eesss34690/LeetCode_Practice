class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int dist = 1, cnt = false;
        while(1)
        {
            for (int i = 0; i < grid.size(); i++)
            {
                for (int j = 0; j < grid[0].size(); j++)
                {
                    if (grid[i][j] == dist && grid[i][j] > 0)
                    {
                        if (i + 1 < grid.size() && grid[i + 1][j] == 0)
                        {
                            grid[i + 1][j] = dist + 1;
                            cnt = true;
                        }
                        if (i > 0 && grid[i - 1][j] == 0)
                        {
                            grid[i - 1][j] = dist + 1;
                            cnt = true;
                        }
                        if (j + 1 < grid[0].size() && grid[i][j + 1] == 0)
                        {
                            grid[i][j + 1] = dist + 1;
                            cnt = true;
                        }
                        if (j > 0 && grid[i][j - 1] == 0)
                        {
                            grid[i][j - 1] = dist + 1;
                            cnt = true;
                        }
                    }
                }
            }
            if (cnt == false)
                return (dist == 1) ? -1 : dist - 1;
            dist++;
            cnt = false;
        }
        return dist - 1;
    }
};
