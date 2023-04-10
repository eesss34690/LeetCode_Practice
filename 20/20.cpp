class Solution {
public:
    bool isValid(string s) {
        stack<int> sta;
        if (s.length() % 2) return false;
        char temp;
        for (auto &i : s)
        {
            if (i == '(' || i == '[' || i == '{') sta.push(int(i));
            else
            {
                if (sta.empty()) return false;
                temp = int(i) - sta.top();
                sta.pop();
                if (temp < 0 || temp > 2) return false;
            }
        }
        return sta.empty();
    }
};
