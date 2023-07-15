class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> pos;
        vector<int> dp(arr.size());
        int ans = 1;
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            auto it = pos.find(arr[i] + difference);
            if (it == pos.end()) dp[i] = 1;
            else dp[i] = dp[it->second] + 1;
            pos[arr[i]] = i;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
