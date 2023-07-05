class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0, r = 0, zero = -1, ans = 0;
        for (; r < nums.size(); r++)
        {
            if (nums[r] != 1)
            {
                if (zero != -1)
                {
                    while (nums[l++] == 1);
                }
                zero = r;
            }
            ans = max(ans, r - l);
        }
        return ans;
    }
};
