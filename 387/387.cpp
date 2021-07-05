class Solution {
public:
    int firstUniqChar(string s) {
        int alpha[26]= {0};
        for (int i= 0; i< s.length(); i++)
        {
            alpha[s[i]- 'a']++;
        }
        for (int i= 0; i< s.length(); i++)
        {
            if(alpha[s[i]- 'a']== 1)
                return i;
        }
        return -1;
    }
};