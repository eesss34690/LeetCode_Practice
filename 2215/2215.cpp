class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans(2);
        unordered_set<int> n1, n2;
        for (auto &i : nums1) n1.insert(i);
        for (auto &i : nums2) n2.insert(i);
        for (auto &i : n2)
        {
            if (n1.count(i) == 0) ans[1].push_back(i);
            else n1.erase(i);
        }
        for (auto &i : n1) ans[0].push_back(i);
        return ans;
    }
};
