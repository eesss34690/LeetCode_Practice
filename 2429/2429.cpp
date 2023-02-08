class Solution {
public:
    int countSetBit(int num)
    {
        if (num == 0)
            return 0;
        else
            return 1 + countSetBit(num & (num - 1));
    }
    int minimizeXor(int num1, int num2) {
        int cnt1 = countSetBit(num1);
        int cnt2 = countSetBit(num2);
        if (cnt1 == cnt2)
            return num1;
        if (cnt1 < cnt2)
        {
            int dist = cnt2 - cnt1, temp = num1, ans = 0;
            while (dist != 0 && temp != 0)
            {
                ans = ans << 1;
                ans++;
                if (temp % 2 == 0)
                    dist--;
                temp = temp >> 1;
            }
            if (dist == 0)
                return ans | num1;
            else
            {
                for (int i = log(ans) / log(2) + 1; dist > 0; dist--, i++)
                    ans += pow(2, i);
                return ans;
            }
        }
        int temp = num1, times = 1;
        for (int i = cnt1 - cnt2; i > 0; times = times << 1)
        {
            if (temp % 2 == 1)
            {
                i--;
                num1 -= times;
            }
            temp = temp >> 1;
        }
        return num1;
    }
};
