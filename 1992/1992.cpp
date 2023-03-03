class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> groups;
        for (int i = 0; i < land.size(); ++i) {
            for (int j = 0; j < land[0].size(); ++j) {
                if (land[i][j] == 0)
                    continue;
                int x = i;
                int y;
                for (; x < land.size() && land[x][j]; ++x) {
                    for (y = j; y < land[0].size() && land[x][y]; ++y) {
                        land[x][y] = 0;
                    }
                }
                groups.push_back({i, j, x - 1, y - 1});
            }
        }
        return groups;
    }
};
