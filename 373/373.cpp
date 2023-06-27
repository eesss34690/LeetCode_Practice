class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        priority_queue<vector<int>> q;
        set<pair<int, int>> visited;
        q.push({-nums1[0] - nums2[0], 0, 0});
        visited.insert({0, 0});
        while (!q.empty() && k--)
        {
            auto it = q.top();
            q.pop();
            ans.push_back({nums1[it[1]], nums2[it[2]]});
            if (it[1] + 1 < nums1.size() && visited.count({it[1] + 1, it[2]}) == 0)
            {
                q.push({-nums1[it[1] + 1] - nums2[it[2]], it[1] + 1, it[2]});
                visited.insert({it[1] + 1, it[2]});
            }
            if (it[2] + 1 < nums2.size() && visited.count({it[1], it[2] + 1}) == 0)
            {
                q.push({-nums1[it[1]] - nums2[it[2] + 1], it[1], it[2] + 1});
                visited.insert({it[1], it[2] + 1});
            }
        }
        return ans;
    }
};
