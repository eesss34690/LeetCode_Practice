class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int j = 0;
        bool f = !(strs.size() > 0);
        while (!f){
            
            if (strs[0].size() <= j)
            {
                j++;
                break;
            }
            for (int i = 1; i < strs.size(); i ++){
                if (strs[i].size() <= j || strs[i][j] != strs[0][j])
                {f = true; break;}
            }
            j ++;
        }

        return j-1 >= 0 ? strs[0].substr(0, j-1) : "";
    }
};