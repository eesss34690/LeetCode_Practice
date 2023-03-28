class Solution {
public:
    vector<int> dp;
    void minDFS(vector<int>& days, vector<int>& costs, int idx) {
        if (dp[idx] == 0)
        {
            if (idx + 1 != days.size())
            {
                minDFS(days, costs, idx + 1);
                dp[idx] = dp[idx + 1] + costs[0];
            }
            else dp[idx] = costs[0];
            auto it = lower_bound(days.begin() + idx, days.end(), days[idx] + 7);
            if (it != days.end())
            {
                minDFS(days, costs, it - days.begin());
                dp[idx] = min(dp[idx], dp[it - days.begin()] + costs[1]);
            }
            else dp[idx] = min(dp[idx], costs[1]);
            it = lower_bound(days.begin() + idx, days.end(), days[idx] + 30);
            if (it != days.end())
            {
                minDFS(days, costs, it - days.begin());
                dp[idx] = min(dp[idx], dp[it - days.begin()] + costs[2]);
            }
            else dp[idx] = min(dp[idx], costs[2]);
        }
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        dp.resize(days.size());
        minDFS(days, costs, 0);
        return dp[0];
    }
};
