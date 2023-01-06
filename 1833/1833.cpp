class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        vector<int>::iterator iter = costs.begin();
        int ans = 0;
        while(iter != costs.end())
        {
            ans += *iter;
            if (ans > coins)
                return iter - costs.begin();
            iter++;
        }
        return costs.size();
    }
};
