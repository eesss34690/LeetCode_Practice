class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int i = 0, j = 0, cnt = 0, maxT = 0, maxF = 0;
        while (j < answerKey.length())
        {
            if (answerKey[j] == 'T') cnt++;
            while (i < j && cnt > k) if (answerKey[i++] == 'T') cnt--;
            maxT = max(maxT, j++ - i + 1);
        }
        i = 0, j = 0, cnt = 0;
        while (j < answerKey.length())
        {
            if (answerKey[j] == 'F') cnt++;
            while (i < j && cnt > k) if (answerKey[i++] == 'F') cnt--;
            maxF = max(maxF, j++ - i + 1);
        }
        return max(maxT, maxF);
    }
};
