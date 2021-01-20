class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_= 0, l= 0, p1= 0, p2= 0, temp= 0;
        bool c= 1;
        for (int i= 1; i< prices.size(); i++)
        {
            if (l+ prices[i]- prices[i- 1]> 0)
            {
                l+= prices[i]- prices[i- 1];
                if (c)
                {
                    temp= i;
                    c= 0;
                }
            }
            else
            {
                l= 0;
                c= 1;
            }
            if (max_< l)
            {
                max_= l;
                p2= i+ 1;
                p1= temp;
            }
        }
        l= 0;
        int max_l= 0, max_r= 0, max_m= 0;
        if (p2!= 0&& prices.size()> 1)
        {
            for (int i= 1; i< p1; i++)
            {
                l= max(l+ prices[i]- prices[i- 1], 0);
                max_l= max(max_l, l);
            }
            l= 0;
            for (int i= p2; i< prices.size(); i++)
            {
                l= max(l+ prices[i]- prices[i- 1], 0);
                max_r= max(max_r, l);
            }
            vector<int>::iterator a, b;
            b= min_element(prices.begin()+ p1, prices.begin()+ p2- 1);
            do
            {
                a= max_element(prices.begin()+ p1, b);
                temp= (*a> *b)? prices[p2- 1]- *b+ *a- prices[p1- 1]: 0; 
                max_m= max(max_m, temp);
                b= find(b+ 1, prices.begin()+ p2- 1, *b);
            }while (b!= prices.begin()+ p2- 1);
            b= max_element(prices.begin()+ p1, prices.begin()+ p2- 1);
            do
            {
                a= min_element(b, prices.begin()+ p2- 1);
                temp= (*a< *b)? prices[p2- 1]- *a+ *b- prices[p1- 1]: 0; 
                max_m= max(max_m, temp);
                b= find(b+ 1, prices.begin()+ p2- 1, *b);
            }while (b!= prices.begin()+ p2- 1);
            
            max_l= max(max_l, max_r);
            max_= max(max_, max_+ max_l); 
        }
        return max(max_, max_m);
    }
};