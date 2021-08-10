class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans= num2; // big one
        int small, plus= 0;
        if (num1.size()> num2.size())
        {
            ans= num1;
            num1= num2;
            num2= ans;
        }
        small= num2.size()- num1.size()- 1; //compare gap- 1
        int i= ans.size()- 1, j= num1.size()- 1;
        //cout<<ans<<" "<<i<<endl;
        for (; j> -1; i--, j--)
        {
            plus+= (num1[j]- '0')+ (num2[i]- '0');
            //cout<<plus<<" ";
            if (plus> 9)
            {
                ans[i]= (plus- 10)+ '0';
                plus= 1;
            }
            else
            {
                ans[i]= plus+ '0';
                plus= 0;
            }
            //cout<<ans<<endl;
        }
        while (plus&& i> -1)
        {
            plus+= (num2[i]- '0');
            if (plus> 9)
            {
                ans[i--]= (plus- 10)+ '0';
                plus= 1;
            }
            else
            {
                ans[i]= plus+ '0';
                return ans;
            }
        }
        if (plus&& i== -1)
            ans.insert(0, "1");
        return ans;
    }
};
