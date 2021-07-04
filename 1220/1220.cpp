class Solution {
public:
    int countVowelPermutation(int n) {
        long long int ans[n][5];
        for (int i= 0; i< 5; i++)
        {
            ans[0][i]= 1;
        }
        for (long int i= 1; i< n; i++)
        {
            ans[i][0]= (ans[i-1][1]+ ans[i-1][2]+ ans[i-1][4])% 1000000007;
            ans[i][1]= (ans[i-1][0]+ ans[i-1][2])% 1000000007;
            ans[i][2]= (ans[i-1][1]+ ans[i-1][3])% 1000000007;
            ans[i][3]= ans[i-1][2]% 1000000007;
            ans[i][4]= (ans[i-1][2]+ ans[i-1][3])% 1000000007;
        }
        return (ans[n-1][0]+ans[n-1][1]+ ans[n-1][2]+ ans[n-1][3]+ ans[n-1][4])% 1000000007;
    }
};
