class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long temp = *min(time.begin(), time.end());
        long long l = 0, r = temp * totalTrips, m;
        while (r - l > 1)
        {
            m = (l + r) / 2;
            temp = 0;
            for (auto &i : time)
                temp += m / i;
            if (totalTrips <= temp)
                r = m;
            else l = m;
        }
        return r;
    }
};
