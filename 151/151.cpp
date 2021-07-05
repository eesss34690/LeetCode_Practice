class Solution {
public:
    string reverseWords(string s) {
        string ans;
        bool o= 1;
        int i, j;
        for (i= s.length()- 1; i> -1 ; i--)
        {
            if (s[i]!= ' '&& o)
            {
                j= i;
                if (!ans.empty())
                    ans.append(" ");
                o= 0;
            }
            else if (s[i]== ' '&& !o)
            {
                o= 1;
                ans.append(s.begin()+ i+ 1, s.begin()+ j+ 1);
            }
            
        }
        if (s[0]!= ' '&& !o)
        {
            ans.append(s.begin(), s.begin()+ j+ 1);
        }
        return ans;
    }
};