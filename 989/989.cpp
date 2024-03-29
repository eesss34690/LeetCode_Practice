class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        for (int i = num.size() - 1; i > -1 && k != 0; i--)
        {
            num[i] += (k % 10);
            k /= 10;
            if (num[i] >= 10)
            {
                num[i] -= 10;
                k++;
            }
        }
        while (k != 0)
        {
            num.insert(num.begin(), k % 10);
            k /= 10;
        }
        return num;
    }
};
