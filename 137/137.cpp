class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> mapping, duplicate;
        for (auto &i : nums)
        {
            auto it = mapping.find(i);
            if (it == mapping.end()) mapping.insert(i);
            else duplicate.insert(i);
        }
        for (auto &i : mapping)
        {
            if (duplicate.find(i) == duplicate.end()) return i;
        }
        return 0;
    }
};
