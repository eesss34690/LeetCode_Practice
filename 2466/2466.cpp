class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1);
        int i, ans = 0;
        if (zero < one)
        {
            i = zero;
            zero = one;
            one = i;
        }
        for (i = one; i <= zero; i += one) dp[i] = 1;
        dp[zero]++;
        for (; i <= high; i++) dp[i] = (dp[i - zero] + dp[i - one]) % 1000000007;
        for (i = low; i <= high; i++) ans = (ans + dp[i]) % 1000000007;
        return ans;
    }
};