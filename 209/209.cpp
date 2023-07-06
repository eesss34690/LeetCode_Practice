class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0, total = 0, ans = INT_MAX;
        while (r < nums.size())
        {
            total += nums[r];
            if (total >= target)
            {
                while (total >= target)
                {
                    ans = min(ans, r - l + 1);
                    total -= nums[l++];
                }
            }
            r++;
        }
        return (ans == INT_MAX) ? 0 : ans;
    }
};
