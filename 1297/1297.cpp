class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int start = 0;
        int result = 0;
        unordered_map<int,int> count;
        unordered_map<string,int> occurence;
        for(int i = 0; i < s.length(); i++)
        {
            count[s[i]]++;
            if(i - start + 1 > minSize)
            {
                if(--count[s[start]] == 0)
                    count.erase(s[start]);
                start++;
            }
            if(i - start + 1 == minSize && count.size() <= maxLetters)
                result = max(result, ++occurence[s.substr(start, i - start + 1)]);
        }
        return result;
    }
};
