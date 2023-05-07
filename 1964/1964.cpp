class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int len = obstacles.size(), l, m, r, s = 0;
        vector<int> ans(len);
        vector<int> increase(len);
        for (int i = 0; i < len; i++)
        {
            l = 0, r = s;
            while (r - l > 0)
            {
                m = (l + r) / 2;
                if (increase[m] <= obstacles[i]) l = m + 1;
                else r = m;
            }
            ans[i] = l + 1;
            if (s == l) s++;
            increase[l] = obstacles[i];
        }
        return ans;
    }
};