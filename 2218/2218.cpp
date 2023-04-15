class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<vector<int>> dp(piles.size(), vector<int>(k + 1, 0));
        int maxTaken, acc, i, j, l;
        for (i = 1; i <= k; i++) dp[0][i] = (piles[0].size() >= i) ? dp[0][i - 1] + piles[0][i - 1] : dp[0][piles[0].size()];
        for (i = 1; i < piles.size(); i++)
        {
            for (j = 1; j <= k; j++)
            {
                dp[i][j] = dp[i - 1][j];
                maxTaken = min(j, int(piles[i].size()));
                acc = 0;
                for (l = 0; l < maxTaken; l++)
                {
                    acc += piles[i][l];
                    dp[i][j] = max(dp[i][j], acc + dp[i - 1][j - 1 - l]);
                }
            }            
        }
        return dp.back().back();
    }
};