class Solution {
public:
    int numberOfArrays(string s, int k) {
        int ans = 0, kVal = log10(k) + 1;
        vector<int> dp(s.length());
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == '0') dp[i] = 0;
            else
            {
                for (int j = 1; j < kVal && i + j < s.length(); j++) dp[i] = (dp[i] + dp[i + j]) % 1000000007;
                if (i + kVal < s.length())
                {
                    if (stol(s.substr(i, kVal)) <= k) dp[i] = (dp[i] + dp[i + kVal]) % 1000000007;
                }
                else if (stol(s.substr(i)) <= k) dp[i]++;
            }
        }
        return dp[0];
    }
};
