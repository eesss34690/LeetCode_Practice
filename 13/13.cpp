class Solution {
public:
    int romanToInt(string s) {
        vector<int> temp;
        bool cnt= 1;
        int same= 0, ans= 0;
        for (auto &i: s)
        {
            switch(i)
            {
                case 'I':
                    temp.push_back(1);
                    break;
                case 'V':
                    temp.push_back(5);
                    break;
                case 'X':
                    temp.push_back(10);
                    break;
                case 'L':
                    temp.push_back(50);
                    break;
                case 'C':
                    temp.push_back(100);
                    break;
                case 'D':
                    temp.push_back(500);
                    break;
                default:
                    temp.push_back(1000);
                    break;
            }
        }
        for (int i= 1; i< temp.size(); i++)
        {
            if (temp[i]== temp[i- 1]&& cnt)
            {
                same= i- 1;
                cnt= 0;
            }
            else if (temp[i]< temp[i- 1])
            {
                ans+= temp[i- 1]* (i- same);
                cnt= 1;
                same= i;
            }
            else if (temp[i]> temp[i- 1])
            {
                ans+= temp[i]- temp[i- 1];
                same= i+ 1;
            }
        }
        ans+= *(temp.end()- 1)* (temp.size()- same);
        return ans;
    }
};