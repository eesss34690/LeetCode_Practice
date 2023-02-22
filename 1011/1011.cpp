class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);
        while (l < r) {
            int m = l + (r - l) / 2;
            int cur = 0, temp = 1;
            for (auto &i : weights) {
                if (cur + i > m) {
                    cur = 0;
                    temp++;
                }
                cur += i;
            }
            if (temp <= days)
                r = m;
            else
                l = m + 1;
        }
        return l;
    }
};
