class Solution {
public:
    bool canJump(vector<int>& nums) {
        for(int i=0;i<nums.size();++i){
            if(i==nums.size()-1) return true;
            if(nums[i]==0){
                int j;
                for(j=i;j>=0;j--) if(nums[j]>i-j) break;
                if(j<0) return false;
            }
        }
        return true;
    }
};