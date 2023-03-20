class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int prev = 0;
        for (int i = 0; i < flowerbed.size(); i++)
        {
            if (flowerbed[i] == 0)
            {
                if (prev == 0)
                {
                    prev = 2;
                    n--;
                }
                else prev = 0;
            }
            else
            {
                if (prev == 2) n++;
                prev = 1;
                if (n <= 0) return true;
            }
        }
        return n <= 0;
    }
};
