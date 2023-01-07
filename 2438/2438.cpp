class Solution {
public:
    void convertToBin(int n, vector<int>& binary, int times) {
        if (n % 2 == 1)
            binary.push_back(pow(2, times));
        if (n > 1)
            convertToBin(n / 2, binary, times + 1);
    }
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans(queries.size());
        vector<int> binary;
        long long int temp;
        convertToBin(n, binary, 0);
        for (int i = 0; i < queries.size(); i++)
        {
            temp = 1;
            for (int j = queries[i][0]; j <= queries[i][1]; j++)
                temp = (temp * (binary[j] % 1000000007)) % 1000000007;
            ans[i] = temp;
        }
        return ans;
    }
};