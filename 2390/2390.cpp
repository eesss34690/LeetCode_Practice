class Solution {
public:
    string removeStars(string s) {
        vector<char> ans;
        for (auto &i : s)
        {
            if (i == '*') ans.pop_back();
            else ans.push_back(i);
        }
        string result(ans.begin(), ans.end());
        return result;
    }
};
