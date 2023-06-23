class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(1002));
        int diff, ans = 2;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                diff = nums[j] - nums[i] + 500;
                dp[j][diff] = max(2, dp[i][diff] + 1);
                ans = max(ans, dp[j][diff]);
            }
        }
        return ans;
    }
};