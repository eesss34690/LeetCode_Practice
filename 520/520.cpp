class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word[0] - 'a' >= 0 && word[0] - 'a' < 27)
        {
            for (int i = 1; i < word.length(); i++)
            {
                if (word[i] - 'a' < 0 || word[i] - 'a' > 26)
                    return false;
            }
        }
        else
        {
            if (word.length() == 1)
                return true;
            if (word[1] - 'a' >= 0 && word[1] - 'a' < 27)
            {
                for (int i = 2; i < word.length(); i++)
                {
                    if (word[i] - 'a' < 0 || word[i] - 'a' > 26)
                        return false;
                }
            } else {
                for (int i = 2; i < word.length(); i++)
                {
                    if (word[i] - 'A' < 0 || word[i] - 'A' > 26)
                        return false;
                }
            }
        }
        return true;
    }
};