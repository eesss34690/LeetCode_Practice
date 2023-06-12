class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if (nums.size() == 0) return ans;
        int start = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[i - 1] + 1)
            {
                ans.push_back((i == start + 1) ? to_string(nums[start]) : to_string(nums[start]) + "->" + to_string(nums[i - 1]));
                start = i;
            }
        }
        ans.push_back((nums.size() == start + 1) ? to_string(nums[start]) : to_string(nums[start]) + "->" + to_string(nums.back()));
        return ans;
    }
};
