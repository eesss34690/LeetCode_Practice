class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (!nums.size())
            return 0;
        sort(nums.begin(), nums.end());
        for (vector<int>::iterator i= nums.begin(); i!= nums.end()- 1; i++)
        {
            if (*i== *(i+ 1))
                return 1;
        }
        return 0;
    }
};