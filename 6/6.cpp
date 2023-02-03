class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        vector<string> ansRow(numRows);
        int idx = 0, temp = 0;
        while (idx < s.length())
        {
            while (idx < s.length() && temp < numRows)
                ansRow[temp++] += s[idx++];
            temp = numRows - 2;
            while (idx < s.length() && temp > 0)
                ansRow[temp--] += s[idx++];
        }
        string ans;
        for (auto &i : ansRow)
            ans += i;
        return ans;
    }
};
