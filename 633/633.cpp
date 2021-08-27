class Solution {
public:
    bool is_square(int target)
    {
        int mid= sqrt(target);
        return mid* mid== target;
    }
    bool judgeSquareSum(int c) {
        int mid= sqrt(c/ 2);
        for (int i= mid; i> -1; i--)
        {
            if (is_square(c- i* i))
                return true;
        }
        return false;
    }
};
