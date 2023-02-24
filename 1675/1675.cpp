class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> q;
        int m = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            if (nums[i] % 2 == 0){
                q.push(nums[i]);
                m = min(m, nums[i]);
            }
            else {
                q.push(nums[i] * 2);
                m = min(m, nums[i] * 2);
            }
        }
        int ans = INT_MAX;
        while (!q.empty()){
            int top = q.top();
            q.pop();
            ans = min(ans, top - m);
            if (top % 2 != 0){
                break;
            }
            m = min(m, top / 2);
            q.push(top / 2);
        }
        return ans;
               
    }
};