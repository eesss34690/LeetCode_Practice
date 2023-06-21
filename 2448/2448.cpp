class Solution {
public:
    long long find_cost(vector<int>& nums, vector<int>& cost, int ele)
    {
        long long ans = 0;
        for (int i = 0; i < nums.size(); i++) ans += (long long)abs(nums[i] - ele) * cost[i];
        return ans;
    }

    long long minCost(vector<int>& nums, vector<int>& cost) {
        int minele = INT_MAX, mxele = INT_MIN, mid;
        for (auto &i : nums)
        {
            minele = min(minele, i);
            mxele = max(mxele, i);
        }
        long long ans = LLONG_MAX, temp, l, r;
        while (minele <= mxele)
        {
            mid = minele + (mxele - minele) / 2;
            temp = find_cost(nums, cost, mid);
            ans = min(ans, temp);
            r = find_cost(nums, cost, mid + 1);
            l = find_cost(nums, cost, mid - 1);
            if(temp < l && temp < r) return ans;
            else if(temp < l && temp > r) minele = mid + 1;
            else mxele = mid - 1;
        }
        return ans;
    }
};
