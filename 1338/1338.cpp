class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> cnt;
        for (int x : arr) ++cnt[x];
        
        vector<int> fre;
        for (auto [_, freq] : cnt) fre.push_back(freq);
        sort(fre.begin(), fre.end());
        
        int ans = 0, removed = 0, half = arr.size() / 2, i = fre.size() - 1;
        while (removed < half) {
            ans ++;
            removed += fre[i--];
        }
        return ans;

    }
};
