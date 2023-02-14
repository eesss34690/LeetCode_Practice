class Solution {
public:
    string addBinary(string a, string b) {
        if (a.length() < b.length())
        {
            string temp = b;
            b = a;
            a = temp;
        }
        int carry = 0, aLen = a.length() - 1, bLen = b.length() - 1;
        while (aLen >= 0)
        {
            carry += (bLen >= 0) ? (a[aLen] - '0') + (b[bLen--] - '0') : a[aLen] - '0';
            a[aLen--] = (carry % 2) + '0';
            carry /= 2;
        }
        return (carry == 1) ? '1' + a : a;
    }
};
