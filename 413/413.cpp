class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() < 3) return 0;
        int ans = 0, subcnt = 0, diff = nums[1] - nums[0];
        for (int i = 2; i < nums.size(); i++)
        {
            if (nums[i] - nums[i - 1] == diff) subcnt++;
            else
            {
                ans += subcnt * (subcnt + 1) / 2;
                subcnt = 0;
                diff = nums[i] - nums[i - 1];
            }
        }
        ans += subcnt * (subcnt + 1) / 2;
        return ans;
    }
};
