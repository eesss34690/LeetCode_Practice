class Solution {
public:
    int real[2], im[2];
    int trans(string word)
    {
        if (word[0]== '-')
            return (-1)* stoi(word.substr(1, string::npos));
        else
            return stoi(word);   
    }
    void complex(string num1, int ind)
    {
        auto a= num1.find("+");
        real[ind]= trans(num1.substr(0, a));
        im[ind]= trans(num1.substr(a+ 1, string::npos));
    }
    string complexNumberMultiply(string num1, string num2) {
        complex(num1, 0);
        complex(num2, 1);

        return to_string(real[0]* real[1]- im[0]* im[1])+"+"+to_string(real[0]* im[1]+ im[0]* real[1])+"i";
    }
};
