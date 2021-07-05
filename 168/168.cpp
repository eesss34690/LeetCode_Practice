class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        while (n)
        {
            n-= 1;
            ans+= n% 26+ 'A';
            n/= 26;
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};