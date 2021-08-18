class Solution {
public:
    int numDecodings(string s) {
        vector<int> num(s.length()+ 2, 0);
        num[1]= 1;
        for (int i= 0; i< s.length(); i++)
        {
            if (s[i]!= '0')
                num[i+ 2]+= num[i+ 1];
            if (s[i]- '0'< 7)
            {
                if (i&& (s[i- 1]== '2'|| s[i- 1]== '1'))
                {
                    num[i+ 2]+= num[i];
                }
            }
            else
            {
                if (i&& s[i- 1]== '1')
                {
                    num[i+ 2]+= num[i];
                }
            }
        }
        return num[s.length()+ 1];
    }
};
