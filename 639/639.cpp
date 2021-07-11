class Solution {
public:
    int numDecodings(string s) {
        long prev = 1;
        long cur = numOfOneChar(s[0]);
        for (int i = 1; i < s.size(); ++i) {
            long next = prev * numOfTwoChars(s[i - 1], s[i]) + cur * numOfOneChar(s[i]);
            prev = cur;
            cur = next % 1000000007;
        }
        return cur;
    }
    int numOfTwoChars(char a, char b) {
        // Return number of char encoded by two digits or '*'.
        if (a == '*') {
            if (b == '*') {
                return 15;
            } else if (b <= '6') {
                return 2;
            } else {
                return 1;
            }
        } else if (a == '1') {
            return b == '*' ? 9 : 1;
        } else if (a == '2') {
            if (b == '*') {
                return 6;
            } else if (b <= '6') {
                return 1;
            } else {
                return 0;
            }
        } 
        return 0;
    }
    int numOfOneChar(char a) {
        if (a == '0') {
            return 0;
        } else if (a == '*') {
            return 9;
        }
        return 1;
    }
};
