class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if (k < arr[0])
            return k;
        if (k > arr.back() - arr.size())
            return k + arr.size();
        k -= arr[0] - 1;
        int temp, i = 0;
        while (true)
        {
            temp = arr[i + 1] - arr[i] - 1;
            if (k > temp)
                k -= temp;
            else break;
            i++;
        }
        return arr[i] + k;
    }
};
