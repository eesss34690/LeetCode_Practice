class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long prev = 0, ans = 0;
        for (auto &i : nums)
        {
            if (i == 0)
            {
                prev++;
                ans += prev;
            }
            else prev = 0;
        }
        return ans;
    }
};
