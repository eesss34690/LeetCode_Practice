class Solution {
public:
    vector<int> ori, shu;
    int ind;
    Solution(vector<int>& nums) {
        ori= nums, shu= nums;
        ind= nums.size();
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return ori;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        swap(shu[rand()% ind], shu[rand()% ind]);
        return shu;
    }
};
