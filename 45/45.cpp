class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size()== 1)
        {
            return 0;
        }
        int cnt= 0, prev= 0, old= 0, new_= 0;
        while(new_< nums.size()- 1)
        {
            old= new_;
            for(int i= prev; i<= old; i++)
            {
                new_= max(new_, i+ nums[i]);
            }
            cnt++;
            prev= old;            
        }
        return cnt;
    }
};