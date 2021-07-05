class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> dict;
        map<char, char>::iterator iter;
        dict[s[0]] = t[0];
        for (int i= 1; i< s.length(); i++)
        {
            iter= dict.find(s[i]);
            if (iter!= dict.end()&& iter->second!= t[i])
            {
                return false;
            }
            if (iter== dict.end())
            {
                if (t.rfind(t[i], i- 1)!= string::npos)
                    return false;
                dict[s[i]]= t[i];
            }
        }
        return true;
    }
};