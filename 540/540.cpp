class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int m, l = 0, r = nums.size() - 1;
        while (l < r)
        {
            m = (l + r) / 2;
            if (nums[m] == nums[m - 1])
            {
                if ((m - l) % 2 == 0)
                    r = m - 2;
                else
                    l = m + 1;
            }
            else if (nums[m] == nums[m + 1])
            {
                if ((m - l) % 2 == 1)
                    r = m - 1;
                else
                    l = m + 2;
            }
            else
                return nums[m];
        }
        return nums[l];
    }
};
