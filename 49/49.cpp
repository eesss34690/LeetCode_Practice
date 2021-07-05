class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;
        vector<vector<string>> result;
        for(auto str : strs)
        {
            int charset[26] = {0};
            string charstr = "";
            for(auto c : str)
                charset[c - 'a']++;
            for(auto v : charset)
                charstr += '#' + char(v);
            anagrams[charstr].push_back(str);
        }
        for(auto it : anagrams)
            result.push_back(it.second);
        return result;
    }
};