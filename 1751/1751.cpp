class Solution {
public:
    int search (vector<vector<int>>& events, int stop, int idx) {
        int l = idx, r = events.size() - 1, m;
        while (l < r)
        {
            m = l + (r - l) / 2;
            if (events[m][0] > stop) r = m;
            else l = m + 1;
        }
        return (l < events.size() && events[l][0] > stop) ? l : -1;
    }
    int memo (vector<vector<int>>& dp, vector<vector<int>>& events, int n, int k, int idx) {
        if (idx == n || k == 0) return 0;
        if (dp[idx][k] != -1) return dp[idx][k];
        int ans = memo(dp, events, n, k, idx + 1);
        int stamp = search(events, events[idx][1], idx + 1);
        ans = max(ans, events[idx][2] + ((stamp == -1) ? 0 : memo(dp, events, n, k - 1, stamp)));
        return dp[idx][k] = ans;
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        vector<vector<int>> dp(events.size(), vector<int>(k + 1, -1));
        return memo(dp, events, events.size(), k, 0);
    }
};
