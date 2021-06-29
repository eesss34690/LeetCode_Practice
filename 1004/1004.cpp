class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l= 0, r= 0, consume= 0, ma= 0;
        while (r< nums.size())
        {
            if (!nums[r++])
                consume++;
            while (consume> k)
            {
                if (!nums[l])
                    consume--;
                l++;
            }
            if (ma< r-l)
                ma= r-l;
            //cout<<l<<" "<<r<<" "<<consume<<" "<<ma<<endl;
        }
        return ma;
        
    }
};