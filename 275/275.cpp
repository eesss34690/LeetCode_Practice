class Solution {
public:
    int hIndex(vector<int>& citations) {
        int s= citations.size(), h= s, l= 0, m;
        while (l< h)
        {
            m= (h+ l+ 1)/ 2;
            if (m<= citations[s- m])
                l= m;
            else
                h= m- 1;
        }
        return l;
    }
};