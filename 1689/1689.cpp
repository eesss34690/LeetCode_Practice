class Solution {
public:
    int minPartitions(string n) {
        int maxNum = '0';
        for (auto &i : n)
        {
            maxNum = max(maxNum, int(i));
        }
        return maxNum - '0';
    }
};
