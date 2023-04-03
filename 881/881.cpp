class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int r = people.size() - 1, l = 0, ans = 0;
        while (l < r)
        {
            if (people[l] + people[r] > limit)
            {
                while (people[l] + people[r] > limit && r != l)
                    r--, ans++;
            }
            ans++, l++, r--;
        }
        return (l == r) ? ans + 1 : ans;
    }
};