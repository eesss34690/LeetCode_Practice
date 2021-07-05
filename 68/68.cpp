class Solution {
public:
    vector<string> ans, row;
    string pack;
    int temp= 0, space, more;
    void packing (int maxWidth)
    {
        if (row.size()!= 1)
        {
            space= (maxWidth- temp+ row.size())/ (row.size()- 1)- 1;
            more= (maxWidth- temp+ row.size())% (row.size()- 1);
            for (int j= 0; j< row.size()- 1; j++)
            {
                pack+= row[j]+ " ";
                for (int k= 0; k< space; k++)
                    pack+= " ";
                if (more--> 0)
                    pack+= " ";
            }
            pack+= *(row.end()- 1);         
        }
        else 
        {
            pack+= row[0];
            while (pack.length()!= maxWidth)
                pack+= " ";
            
        }
        ans.push_back(pack);   
        pack= "";
        row.clear();        
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        for (int i= 0; i< words.size()- 1; i++)
        {
            if (temp+ words[i].length()> maxWidth)
            {
                packing(maxWidth);
                temp= words[i].length()+ 1;
                row.push_back(words[i]);
            }
            else
            {
                temp+= words[i].length()+ 1;
                row.push_back(words[i]);
            }
        }
        if (temp+ (*(words.end()- 1)).length()> maxWidth)
        {
            packing(maxWidth);
        }
        for (auto &i: row)
        {
            pack+= i+ " ";
        }
        pack+= *(words.end()- 1);
        while (pack.length()< maxWidth)
            pack+= " ";
        ans.push_back(pack);
        return ans;
    }
};