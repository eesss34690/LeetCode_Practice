class Solution {
public:
    vector<int> dp;
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        dp.resize(satisfaction.size() + 1);
        for (int i = satisfaction.size() - 1; i >= 0; i--)
        {
            if (dp[i + 1] > 0)
            {
                if (satisfaction[i] + dp[i + 1] + satisfaction[i + 1] > dp[i + 1])
                {
                    dp[i] = satisfaction[i] + dp[i + 1] + satisfaction[i + 1];
                    satisfaction[i] += satisfaction[i + 1];
                }
                else return dp[i + 1];
            }
            else if (satisfaction[i] > 0) dp[i] = satisfaction[i];
        }
        return dp[0];
    }
};
