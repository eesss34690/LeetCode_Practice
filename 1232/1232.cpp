class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if (coordinates[1][0] - coordinates[0][0] == 0)
        {
            for (int i = 2; i < coordinates.size(); i++)
                if (coordinates[i][0] != coordinates[i - 1][0]) return false;
            return true;
        }
        float tilt = float(coordinates[1][1] - coordinates[0][1]) / float(coordinates[1][0] - coordinates[0][0]);
        for (int i = 2; i < coordinates.size(); i++)
        {
            if (float(coordinates[i][1] - coordinates[i - 1][1]) / float(coordinates[i][0] - coordinates[i - 1][0]) != tilt) return false;
        }
        return true;
    }
};
