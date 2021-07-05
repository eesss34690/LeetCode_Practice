class Solution {
public:
    bool isNumber(string s) {
        int cnt= 0;
        bool dot= 0;
        for (int i= 0; i< s.size(); i++)
        {
            if (s[i]== '+'|| s[i]== '-')
            {
                if (i== s.length()- 1|| (i!= 0&& cnt!= 3)|| s.length()== 1)
                    return 0;
                if (cnt== 3)
                    cnt= 4;
                else
                    cnt= 1;
            }
            else if (s[i]- '0'> -1&& s[i]- '0'< 10)
            {
                if (cnt> 2)
                    cnt= 5;
                else
                    cnt= 2;
            }
            else if (s[i]== 'e'|| s[i]== 'E')
            {
                if (cnt!= 2|| i== s.length()- 1|| i== 0)
                    return 0;
                cnt= 3;
            }
            else if (s[i]== '.')
            {
                if (dot|| s.length()== 1|| cnt> 2|| (i== s.length()- 1&& cnt% 3!= 2))
                    return 0;
                dot= 1;
            }
            else
                return 0;
        }
        return 1;
    }
};