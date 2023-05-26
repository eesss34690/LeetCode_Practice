class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size(), opponentScore, m, score, i, x;
        vector<int> suffixSums(n + 1);
        for (i = n - 1; i >= 0; i--) suffixSums[i] = suffixSums[i + 1] + piles[i];
        vector<vector<int>> dp(n, vector<int>(n + 1));
        for (i = n - 1; i >= 0; i--)
        {
            for (m = 1; m <= n; m++)
            {
                if (i + 2 * m >= n) dp[i][m] = suffixSums[i];
                else
                {
                    for (x = 1; x <= 2 * m; x++)
                    {
                        opponentScore = dp[i + x][max(x, m)];
                        score = suffixSums[i] - opponentScore;
                        dp[i][m] = max(dp[i][m], score);
                    }
                }
            }
        }
        return dp[0][1];
    }
};
