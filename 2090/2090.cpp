qclass Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> ans(nums.size(), -1);
        if (k * 2 >= nums.size()) return ans;
        long sum = 0;
        int end = nums.size() - k - 1, len = k * 2 + 1, i = 0;
        for (; i < len; i++) sum += nums[i];
        for (i = k; i < end; i++)
        {
            ans[i] = sum / len;
            sum -= nums[i - k], sum += nums[i + k + 1];
        }
        ans[end] = sum / len;
        return ans;
    }
};