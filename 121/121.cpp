class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_= 0, l= 0;
        for (int i= 1; i< prices.size(); i++)
        {
            l= max(l+ prices[i]- prices[i- 1], 0);
            max_= max(max_, l);   
        }
        return max_;
    }
};