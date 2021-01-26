class Solution {
public:
    string reverseVowels(string s) {
        vector<char> vow;
        vector<int> ind;
        for (int i= s.length()- 1; i> -1; i--)
        {
            if (s[i]== 'a'|| s[i]== 'A'|| s[i]== 'e'|| s[i]== 'E'|| s[i]== 'i'|| s[i]== 'I'|| s[i]== 'o'|| s[i]== 'O'|| s[i]== 'u'|| s[i]== 'U')
            {
                vow.push_back(s[i]);
                ind.push_back(i);
                s[i]= '0';
            }            
        }
        for (int i= 0; i< ind.size(); i++)
        {
            s[ind[ind.size()- i- 1]]= vow[i];
        }
        return s;
    }
};