class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> sor;
        int si= nums.size();
        for (int i= 0; i< si; i++)
        {
            sor.emplace(nums[i], i);
        }
        for (auto &i: sor)
        {
            int val= target- i.first;
            auto fi= sor.find(val);
            if (fi!= sor.end())
            {
                if (fi->first== i.first)
                {
                    nums[i.second]= INT_MAX;
                    auto look= find(nums.begin(), nums.end(), i.first);
                    if (look!= nums.end())
                    {
                        int an= look- nums.begin();
                        return {an, i.second};
                    }
                    else
                        continue;
                }
                return {fi->second, i.second};
            }
        }
        return nums;
    }
};
