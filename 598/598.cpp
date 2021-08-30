class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int min_x= m, min_y= n;
        for (auto i: ops)
        {
            if (min_x> i[0])
                min_x= i[0];
            if (min_y> i[1])
                min_y= i[1];
        }
        return min_x* min_y;
    }
};
