class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int idx, ans;
        for (int i = 0; i < words.size() - 1; i++)
        {
            idx = 0;
            while (idx < words[i].length() && idx < words[i + 1].length())
            {
                ans = order.find(words[i][idx]) - order.find(words[i + 1][idx]);
                if (ans > 0)
                    return false;
                if (ans < 0)
                    break;
                idx++;
            }
            if (idx == words[i + 1].length() && idx != words[i].length())
                return false;
        }
        return true;
    }
};
