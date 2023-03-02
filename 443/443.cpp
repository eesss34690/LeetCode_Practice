class Solution {
public:
    int compress(vector<char>& chars) {
        int idx = 0, first = 0, temp;
        vector<char> compression;
        while (1)
        {
            compression.push_back(chars[idx]);
            while (idx < chars.size())
            {
                if (chars[first] == chars[idx])
                    idx++;
                else
                    break;
            }
            temp = idx - first;
            if (temp > 1)
            {
                auto val = to_string(temp);
                for (auto &i : val)
                    compression.push_back(i);
            }
            if (idx == chars.size())
                break;
            first = idx;
        }
        chars = compression;
        return chars.size();
    }
};