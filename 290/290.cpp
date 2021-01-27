class Solution {
public:
    bool wordPattern(string pattern, string s) {
        string::size_type pos= s.find(" "), ori= 0;
        vector<string> pat;
        while(string::npos != pos)
        {
            pat.push_back(s.substr(ori, pos- ori));
            ori = pos+ 1;
            pos = s.find(" ", ori);
        }
        if (ori != s.length())
            pat.push_back(s.substr(ori));
        if (pattern.length()!= pat.size())
            return false;
        map<char, string> table;
        table[pattern[0]]= pat[0];
        map<char, string>::iterator iter;
        for (int i= 1; i< pattern.length(); i++)
        {
            iter= table.find(pattern[i]);
            if (iter!= table.end()&& iter->second != pat[i])
            {
                return false;
            }
            if (iter== table.end())
            {
                if (find(pat.begin(), pat.begin()+ i, pat[i])!= pat.begin()+ i)
                {
                    return false;
                }
                table[pattern[i]]= pat[i];
            }
        }
        return true;
    }
};