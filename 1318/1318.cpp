class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0, resA, resB, resC;
        while (a != 0 || b != 0 || c != 0)
        {
            resA = a % 2, resB = b % 2, resC = c % 2;
            if (resC == 1)
            {
                if (resA == resB && resA == 0) ans++;
            }
            else
            {
                if (resA == 1)
                {
                    if (resB == 1) ans += 2;
                    else ans++;
                }
                else if (resB == 1) ans++;
            }
            a = a >> 1, b = b >> 1, c = c >> 1;
        }
        return ans;
    }
};
