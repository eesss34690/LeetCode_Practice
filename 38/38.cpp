class Solution {
public:
    string convert(string ans)
    {
        string a;
        int ind= 0;
        for (int i= 1; i< ans.length(); i++)
        {
            if (ans[i]!= ans[ind])
            {
                a+= to_string(i- ind)+ ans[ind];
                ind= i;
            }
        }
        a+= to_string(ans.size()- ind)+ ans[ind];
        return a;
    }
    string countAndSay(int n) {
        if (n== 1)
            return "1";
        string ans= "11";
        while (--n!= 1)
        {
            ans= convert(ans);
        }
        return ans;
    }
};