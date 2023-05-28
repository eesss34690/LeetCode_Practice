class Solution {
public:
    vector<vector<int>> dp;
    int minSubCost(vector<int>& cuts, int l, int r) {
        if (dp[l][r] != 0 || r - l < 2) return dp[l][r];
        dp[l][r] = cuts[r] - cuts[l];
        if (r > l + 2)
        {
            int temp = INT_MAX;
            for (int i = l + 1; i < r; i++) temp = min(temp, minSubCost(cuts, l, i) + minSubCost(cuts, i, r));
            dp[l][r] += temp;
        }
        return dp[l][r];
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        dp.resize(cuts.size(), vector<int>(cuts.size()));
        return minSubCost(cuts, 0, cuts.size() - 1);
    }
};
