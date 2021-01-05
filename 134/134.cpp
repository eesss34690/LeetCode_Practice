class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (accumulate(gas.begin(), gas.end(), 0)< accumulate(cost.begin(), cost.end(), 0))
            return -1;
        int min= 0;
        int ans= -1;
        for (int i= 0; i< gas.size(); i++)
        {
            min+= gas[i]- cost[i];
            if (min> -1&& ans< 0)
                ans= i;
            else if (min< 0)
            {
                min= 0;
                ans= -1;
            }
        }
        return ans;
    }
};