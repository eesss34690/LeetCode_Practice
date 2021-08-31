class Solution {
public:
    int findMin(vector<int>& nums) {
        int l= 0, r= nums.size(), m;
        while (l< r)
        {
            m= (l+ r)/ 2;
            if (nums[l]< nums[m])
                l= m;
            else
                r= m;
        }
        return (++l>= nums.size())? nums[0]: nums[l];
    }
};
