class Solution {
public:
    int mod = 1000000007;
    long inverse (long num) {
        if (num == 1) return 1;
        return mod - mod / num * inverse(mod % num) % mod;
    }
    int dfs(vector<int>& nums) {
        if (nums.size() <= 2) return 1;
        vector<int> left, right;
        int i = 1;
        for (; i < nums.size(); i++) {
            if (nums[i] < nums[0]) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }
        int a = left.size();
        int b = right.size();
        long res = 1;
        for (i = b + 1; i <= a + b; i++) res = res * i % mod;
        for (i = 2; i <= a; i++) res = res * inverse(i) % mod;
        return res * dfs(left) % mod * dfs(right) % mod;
    }
    int numOfWays(vector<int>& nums) {
        return dfs(nums) - 1;
    }
};
