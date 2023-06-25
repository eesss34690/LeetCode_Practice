class Solution {
public:
    int mod = 1000000007;
    int search(vector<int>& locations, vector<vector<int>>& dp, int start, int& finish, int fuel) {
        if (dp[start][fuel] != -1) return dp[start][fuel];
        if (fuel == 0) return dp[start][0] = (start == finish);
        int cur, ans = (start == finish);
        for (int i = 0; i < locations.size(); i++)
        {
            if (i == start) continue;
            cur = fuel - abs(locations[start] - locations[i]);
            if (cur >= 0) ans = (ans + search(locations, dp, i, finish, cur)) % mod;
        }
        return dp[start][fuel] = ans;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        vector<vector<int>> dp(locations.size(), vector<int>(201, -1));
        return search(locations, dp, start, finish, fuel);
    }
};