class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto ans = lower_bound(letters.begin(), letters.end(), target + 1);
        return (ans == letters.end()) ? letters[0] : *ans;
    }
};
