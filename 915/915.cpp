class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        vector<int>::iterator pos= min_element(nums.begin(), nums.end());
        vector<int>::iterator max_= max_element(nums.begin(), pos);
        vector<int>::iterator min_= min_element(1+ pos, nums.end());
        while(*max_> *min_)
        {
            pos= max_element(pos, min_);
            max_= (*max_< *pos)? pos: max_;
            pos= min_;
            min_= min_element(1+ pos, nums.end());
        }
        
        return (1+ pos- nums.begin());
    }
};
