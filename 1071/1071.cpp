class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int commonmax = gcd(str1.length(), str2.length());
        if (commonmax == 0)
            return "";
        if (str1.length() < str2.length())
        {
            string temp = str1;
            str1 = str2;
            str2 = temp;
        }
        int idx1 = 0;
        string sub;
        while(commonmax > 0)
        {
            sub = str2.substr(0, commonmax);
            while (sub == str2.substr(idx1, commonmax))
                idx1 += commonmax;
            if (idx1 >= str2.length())
            {
                idx1 = 0;
                while (sub == str1.substr(idx1, commonmax))
                    idx1 += commonmax;
                if (idx1 >= str1.length())
                    return sub;
            }
            commonmax--;
        }
        return "";
    }
};
