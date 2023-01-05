class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int x_end = points[0][1], ans = 1;
        for (int i = 1; i < points.size(); i++)
        {
            if (x_end < points[i][0])
            {
                x_end = points[i][1];
                ans++;
            } else if (x_end > points[i][1])
                x_end = points[i][1];
        }
        return ans;
    }
};