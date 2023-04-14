class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int len = s.size();
        vector<vector<int>> dp(len, vector<int>(len, 0));
        for (int i = 1; i <= len; i++)
        {
            for (int start = 0; start <= len - i; start++)
            {
                int end = start + i - 1;
                if (i == 1) dp[start][end] = 1;
                else if (s[start] == s[end])dp[start][end] = 2 + dp[start + 1][end - 1];
                else dp[start][end] = max(dp[start + 1][end], dp[start][end - 1]);
            }
        }
        return dp[0].back();
    }
};