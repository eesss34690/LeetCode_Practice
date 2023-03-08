class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long l = 0, r = *max_element(piles.begin(), piles.end());
        long long m, temp;
        while (r - l > 1)
        {
            m = (l + r) / 2;
            temp = 0;
            for (auto &i : piles)
                temp += (i % m == 0) ? i / m : i / m + 1;
            if (temp <= h)
                r = m;
            else l = m;
        }
        return r;
    }
};
