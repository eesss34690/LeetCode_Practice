class Solution {
public:
    string removeDuplicateLetters(string s) {
        int app[26]= {0};
        string ans;
        int i= 0;
        for (; i< s.length(); i++)
        {
            app[s[i]- 'a']= i;
        }
        set<char> seen;
        i= 0;
        for (auto &c: s)
        {
            if (!seen.count(c))
            {
                while (!ans.empty()&& c< ans.back()&& app[ans.back()- 'a']> i)
                {
                    seen.erase(ans.back());
                    ans.pop_back();
                }
                ans+= c;
                seen.emplace(c);
            }
            i++;
        }
        return ans;
    }
};