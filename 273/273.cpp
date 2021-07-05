class Solution {
public:
    map<char, string> normal;
    map<char, string> ty;
    map<char, string> ten;
    vector<string> ans;
    void add2(char a, char b)
    {
        if (a== '1')
            ans.push_back(ten.find(b)->second);
        
        else if (a!= '0')
        {
            if (b!= '0')
                ans.push_back(normal.find(b)->second);
    
            ans.push_back(ty.find(a)->second);
        }
        else if (b!= '0')
            ans.push_back(normal.find(b)->second);
    }
    string numberToWords(int num) {
        if (num== 0)
            return "Zero";
        string eng[]= {"Thousand", "Million", "Billion"};
        normal['0']= "";
        normal['1']= "One";
        normal['2']= "Two";
        normal['3']= "Three";
        normal['4']= "Four";
        normal['5']= "Five";
        normal['6']= "Six";
        normal['7']= "Seven";
        normal['8']= "Eight";
        normal['9']= "Nine";
        ten['1']= "Eleven";
        ten['2']= "Twelve";
        ten['3']= "Thirteen";
        ten['4']= "Fourteen";
        ten['5']= "Fifteen";
        ten['6']= "Sixteen";
        ten['7']= "Seventeen";
        ten['8']= "Eighteen";
        ten['9']= "Nineteen";
        ten['0']= "Ten";
        ty['2']= "Twenty";
        ty['3']= "Thirty";
        ty['4']= "Forty";
        ty['5']= "Fifty";
        ty['6']= "Sixty";
        ty['7']= "Seventy";
        ty['8']= "Eighty";
        ty['9']= "Ninety";
        string n= to_string(num);
        reverse(begin(n), end(n));
        int temp= -1;
        for (int i= 2; i< n.length(); i+= 3)
        {
            if (n[i]== '0'&& n[i- 1]== '0'&& n[i- 2]== '0')
            {
                temp++;
                continue;
            }
            if (i!= 2)
                ans.push_back(eng[temp++]);
            else
                temp++;
            add2(n[i- 1], n[i- 2]);
            if (n[i]!= '0')
            {
                ans.push_back("Hundred");
                ans.push_back(normal.find(n[i])->second);
            }
        }
        if (n.length()% 3== 2)
        {
            if (temp!= -1)
                ans.push_back(eng[temp]);
            add2(*(n.end()- 1), *(n.end()- 2));
        }
        else if (n.length()% 3== 1)
        {
            if (temp!= -1)
                ans.push_back(eng[temp]);
            add2('0', *(n.end()- 1));
        }
        string aa;
        for (vector<string>::iterator i= ans.end()- 1; i!= ans.begin(); i--)
        {
            aa+= *i;
            aa+= " ";
        }
        aa+= ans[0];
        return aa;
    }
};